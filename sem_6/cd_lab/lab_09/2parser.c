#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Token types
typedef enum {
    LPAREN,   // (
    RPAREN,   // )
    PLUS,     // +
    MUL,      // *
    ID,       // identifier
    DOLLAR,   // $
    E,        // non-terminal E
    T,        // non-terminal T
    F,        // non-terminal F
    EPRIME    // non-terminal E'
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

// State and symbol stack
typedef struct {
    int state;
    TokenType symbol;
} StackItem;

// Grammar rules for reductions
typedef struct {
    int ruleNumber;
    int popCount;
    TokenType lhs;
} Rule;

Rule rules[] = {
    {0, 1, EPRIME},  // Eprime -> E
    {1, 3, E},       // E -> E + T
    {2, 1, E},       // E -> T
    {3, 3, T},       // T -> T * F
    {4, 1, T},       // T -> F
    {5, 3, F},       // F -> (E)
    {6, 1, F}        // F -> id
};

// ACTION Table for LPAREN, RPAREN, PLUS, MUL, ID, DOLLAR
const char* action[13][6] = {
    { "s4", "", "", "", "s5", "" },
    { "", "", "s6", "", "", "acc" },
    { "", "r2", "r2", "s7", "", "" },
    { "", "r4", "r4", "r4", "", "" },
    { "s4", "", "", "", "s5", "" },
    { "", "r6", "r6", "r6", "", "" },
    { "s4", "", "", "", "s5", "" },
    { "s4", "", "", "", "s5", "" },
    { "", "s12", "s6", "", "", "" },
    { "", "r2", "r2", "s7", "", "" },
    { "", "r1", "r1", "", "", "" },
    { "", "r4", "r4", "r4", "", "" },
    { "", "r5", "r5", "r5", "", "" }
};

// GOTO Table for E, T, F
int gotoTable[13][3] = {
    { 1, 2, 3 }, { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 },
    { 8, 9, 3 }, { -1, -1, -1 }, { -1, 10, 3 }, { -1, -1, 11 },
    { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 },
    { -1, -1, -1 }
};

// Function to get index for the goto table
int getGotoIndex(TokenType symbol) {
    switch (symbol) {
        case E: return 0;
        case T: return 1;
        case F: return 2;
        default: return -1;
    }
}

// Function to get index for the action table
int getActionIndex(TokenType token) {
    switch (token) {
        case LPAREN: return 0;
        case RPAREN: return 1;
        case PLUS: return 2;
        case MUL: return 3;
        case ID: return 4;
        case DOLLAR: return 5;
        default: return -1;
    }
}

// Function to print token type (for debugging)
void printTokenType(TokenType type) {
    switch (type) {
        case LPAREN: printf("LPAREN"); break;
        case RPAREN: printf("RPAREN"); break;
        case PLUS: printf("PLUS"); break;
        case MUL: printf("MUL"); break;
        case ID: printf("ID"); break;
        case DOLLAR: printf("DOLLAR"); break;
        case E: printf("E"); break;
        case T: printf("T"); break;
        case F: printf("F"); break;
        case EPRIME: printf("EPRIME"); break;
        default: printf("UNKNOWN"); break;
    }
}

// Function to print the stack (for debugging)
void printStack(StackItem* stack, int top) {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("[%d,", stack[i].state);
        printTokenType(stack[i].symbol);
        printf("] ");
    }
    printf("\n");
}

// SLR(1) parser
bool parse(Token* tokens, int tokenCount) {
    // Initialize stack
    StackItem stack[1000];
    int top = 0;
    stack[top].state = 0;
    stack[top].symbol = DOLLAR;
    
    int currentToken = 0;
    
    while (true) {
        int currentState = stack[top].state;
        TokenType currentSymbol = tokens[currentToken].type;
        
        printf("\nCurrent State: %d, Current Symbol: ", currentState);
        printTokenType(currentSymbol);
        printf(" (%s)\n", tokens[currentToken].lexeme);
        
        printStack(stack, top);
        
        int actionIndex = getActionIndex(currentSymbol);
        if (actionIndex == -1) {
            printf("Error: Invalid token type.\n");
            return false;
        }
        
        const char* actionValue = action[currentState][actionIndex];
        
        if (strlen(actionValue) == 0) {
            printf("Error: No action defined for state %d and symbol.\n", currentState);
            return false;
        }
        
        printf("Action: %s\n", actionValue);
        
        if (actionValue[0] == 's') { // Shift action
            int nextState = atoi(actionValue + 1);
            top++;
            stack[top].state = nextState;
            stack[top].symbol = currentSymbol;
            currentToken++;
            
            printf("Shift to state %d\n", nextState);
        } else if (actionValue[0] == 'r') { // Reduce action
            int rule = atoi(actionValue + 1);
            int popCount = rules[rule].popCount;
            TokenType lhs = rules[rule].lhs;
            
            printf("Reduce by rule %d: ", rule);
            switch (rule) {
                case 0: printf("Eprime -> E\n"); break;
                case 1: printf("E -> E + T\n"); break;
                case 2: printf("E -> T\n"); break;
                case 3: printf("T -> T * F\n"); break;
                case 4: printf("T -> F\n"); break;
                case 5: printf("F -> (E)\n"); break;
                case 6: printf("F -> id\n"); break;
            }
            
            // Pop states and symbols from the stack
            top -= popCount;
            
            // Get the state at the top of the stack after popping
            int topState = stack[top].state;
            
            // Get the goto state for the non-terminal
            int gotoIndex = getGotoIndex(lhs);
            if (gotoIndex == -1) {
                printf("Error: Invalid non-terminal for goto.\n");
                return false;
            }
            
            int gotoState = gotoTable[topState][gotoIndex];
            if (gotoState == -1) {
                printf("Error: No goto defined for state %d and non-terminal.\n", topState);
                return false;
            }
            
            // Push the new state and symbol onto the stack
            top++;
            stack[top].state = gotoState;
            stack[top].symbol = lhs;
            
            printf("Goto state %d\n", gotoState);
        } else if (strcmp(actionValue, "acc") == 0) { // Accept action
            printf("Input accepted!\n");
            return true;
        } else {
            printf("Error: Unknown action %s.\n", actionValue);
            return false;
        }
    }
}

// Function to tokenize input
int tokenize(const char* input, Token* tokens) {
    int i = 0;
    int tokenCount = 0;
    
    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            i++;
            continue;
        }
        
        if (input[i] == '(') {
            tokens[tokenCount].type = LPAREN;
            strcpy(tokens[tokenCount].lexeme, "(");
            tokenCount++;
        } else if (input[i] == ')') {
            tokens[tokenCount].type = RPAREN;
            strcpy(tokens[tokenCount].lexeme, ")");
            tokenCount++;
        } else if (input[i] == '+') {
            tokens[tokenCount].type = PLUS;
            strcpy(tokens[tokenCount].lexeme, "+");
            tokenCount++;
        } else if (input[i] == '*') {
            tokens[tokenCount].type = MUL;
            strcpy(tokens[tokenCount].lexeme, "*");
            tokenCount++;
        } else if (isalpha(input[i])) {
            int j = 0;
            char id[100];
            while (isalnum(input[i])) {
                id[j++] = input[i++];
            }
            id[j] = '\0';
            i--; // Move back one character since the loop will increment i
            
            tokens[tokenCount].type = ID;
            strcpy(tokens[tokenCount].lexeme, id);
            tokenCount++;
        } else {
            printf("Error: Unknown character %c.\n", input[i]);
            return -1;
        }
        
        i++;
    }
    
    // Add the end marker
    tokens[tokenCount].type = DOLLAR;
    strcpy(tokens[tokenCount].lexeme, "$");
    tokenCount++;
    
    return tokenCount;
}

// Main function
int main() {
    char input[1000];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);
    
    Token tokens[100];
    int tokenCount = tokenize(input, tokens);
    
    if (tokenCount == -1) {
        return 1;
    }
    
    printf("Tokens:\n");
    for (int i = 0; i < tokenCount; i++) {
        printf("%d: ", i);
        printTokenType(tokens[i].type);
        printf(" (%s)\n", tokens[i].lexeme);
    }
    
    if (parse(tokens, tokenCount)) {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed!\n");
    }
    
    return 0;
}
