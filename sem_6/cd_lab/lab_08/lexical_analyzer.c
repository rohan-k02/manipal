#include "lexical_analyzer.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define global variables here
char input[1000];
int pos = 0;
int lineNumber = 1; // Track line numbers for error reporting

// Function to get the next token
Token getNextToken() {
    Token token;

    // Skip whitespaces and track line numbers
    while (isspace(input[pos])) {
        if (input[pos] == '\n') lineNumber++;
        pos++;
    }

    // End of file
    if (input[pos] == '\0') {
        token.type = END_OF_FILE;
        strcpy(token.lexeme, "EOF");
        return token;
    }

    // Keywords and Identifiers
    if (strncmp(&input[pos], "main", 4) == 0 && !isalnum(input[pos + 4]) && input[pos + 4] != '_') {
        token.type = MAIN;
        strcpy(token.lexeme, "main");
        pos += 4;
        return token;
    }
    if (strncmp(&input[pos], "int", 3) == 0 && !isalnum(input[pos + 3]) && input[pos + 3] != '_') {
        token.type = INT;
        strcpy(token.lexeme, "int");
        pos += 3;
        return token;
    }
    if (strncmp(&input[pos], "char", 4) == 0 && !isalnum(input[pos + 4]) && input[pos + 4] != '_') {
        token.type = CHAR;
        strcpy(token.lexeme, "char");
        pos += 4;
        return token;
    }
    if (strncmp(&input[pos], "if", 2) == 0 && !isalnum(input[pos + 2]) && input[pos + 2] != '_') {
        token.type = IF;
        strcpy(token.lexeme, "if");
        pos += 2;
        return token;
    }
    if (strncmp(&input[pos], "else", 4) == 0 && !isalnum(input[pos + 4]) && input[pos + 4] != '_') {
        token.type = ELSE;
        strcpy(token.lexeme, "else");
        pos += 4;
        return token;
    }

    // Single character tokens
    switch (input[pos]) {
        case '(':
            token.type = LPAREN; strcpy(token.lexeme, "("); pos++; return token;
        case ')':
            token.type = RPAREN; strcpy(token.lexeme, ")"); pos++; return token;
        case '{':
            token.type = LBRACE; strcpy(token.lexeme, "{"); pos++; return token;
        case '}':
            token.type = RBRACE; strcpy(token.lexeme, "}"); pos++; return token;
        case ';':
            token.type = SEMICOLON; strcpy(token.lexeme, ";"); pos++; return token;
        case ',':
            token.type = COMMA; strcpy(token.lexeme, ","); pos++; return token;
        case '=':
            if (input[pos + 1] == '=') {
                token.type = RELOP; strcpy(token.lexeme, "=="); pos += 2;
            } else {
                token.type = ASSIGN; strcpy(token.lexeme, "="); pos++;
            }
            return token;
        case '!':
            if (input[pos + 1] == '=') {
                token.type = RELOP; strcpy(token.lexeme, "!="); pos += 2;
                return token;
            }
            break;
        case '<':
        case '>':
            if (input[pos + 1] == '=') {
                token.type = RELOP;
                strncpy(token.lexeme, &input[pos], 2);
                token.lexeme[2] = '\0';
                pos += 2;
            } else {
                token.type = RELOP;
                strncpy(token.lexeme, &input[pos], 1);
                token.lexeme[1] = '\0';
                pos++;
            }
            return token;
        case '+':
        case '-':
            token.type = ADDOP;
            token.lexeme[0] = input[pos];
            token.lexeme[1] = '\0';
            pos++;
            return token;
        case '*':
        case '/':
        case '%':
            token.type = MULOP;
            token.lexeme[0] = input[pos];
            token.lexeme[1] = '\0';
            pos++;
            return token;
        case '[':
            token.type = LBRACKET; strcpy(token.lexeme, "["); pos++; return token;
        case ']':
            token.type = RBRACKET; strcpy(token.lexeme, "]"); pos++; return token;
    }

    // Identifiers and Array References
    if (isalpha(input[pos])) {
        int start = pos;
        while (isalnum(input[pos])) pos++;
        strncpy(token.lexeme, &input[start], pos - start);
        token.lexeme[pos - start] = '\0';
        token.type = ID;
        return token;
    }

    // Numbers
    if (isdigit(input[pos])) {
        int start = pos;
        while (isdigit(input[pos])) pos++;
        strncpy(token.lexeme, &input[start], pos - start);
        token.lexeme[pos - start] = '\0';
        token.type = NUM;
        return token;
    }

    // Unknown character
    printf("Error at line %d: Unknown character '%c'\n", lineNumber, input[pos]);
    pos++;  // Prevent infinite loop
    token.type = ERROR;
    strcpy(token.lexeme, "ERROR");
    return token;
}
