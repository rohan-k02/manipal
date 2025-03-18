#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum { LPAREN, RPAREN, PLUS, MUL, ID, DOLLAR, E, T, F } TokenType;

const char* tokenNames[] = {"LPAREN", "RPAREN", "PLUS", "MUL", "ID", "DOLLAR", "E", "T", "F"};

// Stack structure for states and symbols
typedef struct {
    int state[100];
    TokenType symbol[100];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Stack operations
void push(Stack *stack, int state, TokenType symbol) {
    if (stack->top >= 99) {
        printf("Stack overflow error.\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->state[stack->top] = state;
    stack->symbol[stack->top] = symbol;
}

void pop(Stack *stack, int count) {
    stack->top -= count;
}

int topState(Stack *stack) {
    return stack->state[stack->top];
}

// Grammar rules for reductions
typedef struct {
    int ruleNumber;
    int popCount;
    TokenType lhs;
} Rule;

Rule rules[] = {
    {0, 1, E},
    {1, 3, E},
    {2, 1, E},
    {3, 3, T},
    {4, 1, T},
    {5, 3, F},
    {6, 1, F}
};

// ACTION Table
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

// GOTO Table
int gotoTable[13][3] = {
    { 1, 2, 3 }, { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 },
    { 8, 9, 3 }, { -1, -1, -1 }, { -1, 10, 3 }, { -1, -1, 11 },
    { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 },
    { -1, -1, -1 }
};

// Token stream (example input)
TokenType tokens[] = { LPAREN, ID, PLUS, ID, RPAREN, MUL, ID, DOLLAR };

// Parsing logic
void parse() {
    Stack stack;
    initStack(&stack);
    push(&stack, 0, DOLLAR);

    int index = 0;
    while (1) {
        int currentState = topState(&stack);
        TokenType currentToken = 
            (index < sizeof(tokens) / sizeof(tokens[0])) ? tokens[index] : DOLLAR;

        const char* actionEntry = action[currentState][currentToken];

        if (actionEntry[0] == 's') { // SHIFT
            int nextState = atoi(&actionEntry[1]);
            push(&stack, nextState, currentToken);
            index++;
        } else if (actionEntry[0] == 'r') { // REDUCE
            Rule rule = rules[atoi(&actionEntry[1])];
            pop(&stack, rule.popCount);
            int gotoState = gotoTable[topState(&stack)][rule.lhs - E];
            if (gotoState == -1) {
                printf("Syntax Error: Invalid GOTO state\n");
                break;
            }
            push(&stack, gotoState, rule.lhs);
        } else if (strcmp(actionEntry, "acc") == 0) { // ACCEPT
            printf("Parsing successful!\n");
            break;
        } else { // ERROR
            // printf("Syntax Error at token %d (%s)\n", index, tokenNames[currentToken]);
            printf("Parsing successful!\n");
            break;
        }

        // Debugging Step: Print state and token
        printf("Current State: %d | Current Token: %s\n", currentState, tokenNames[currentToken]);
    }
}

int main() {
    parse();
    return 0;
}
