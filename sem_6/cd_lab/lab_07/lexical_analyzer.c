#include "lexical_analyzer.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[1000];
int pos = 0;

Token getNextToken() {
    Token token;

    // Skip whitespaces
    while (isspace(input[pos])) pos++;

    // End of file
    if (input[pos] == '\0') {
        token.type = END_OF_FILE;
        strcpy(token.lexeme, "EOF");
        return token;
    }

    // Recognize tokens
    if (strncmp(&input[pos], "main", 4) == 0 && !isalnum(input[pos + 4])) {
        token.type = MAIN;
        strcpy(token.lexeme, "main");
        pos += 4;
        return token;
    }

    if (strncmp(&input[pos], "int", 3) == 0 && !isalnum(input[pos + 3])) {
        token.type = INT;
        strcpy(token.lexeme, "int");
        pos += 3;
        return token;
    }

    if (strncmp(&input[pos], "char", 4) == 0 && !isalnum(input[pos + 4])) {
        token.type = CHAR;
        strcpy(token.lexeme, "char");
        pos += 4;
        return token;
    }

    // Single character tokens
    switch (input[pos]) {
        case '(':
            token.type = LPAREN;
            strcpy(token.lexeme, "(");
            pos++;
            return token;
        case ')':
            token.type = RPAREN;
            strcpy(token.lexeme, ")");
            pos++;
            return token;
        case '{':
            token.type = LBRACE;
            strcpy(token.lexeme, "{");
            pos++;
            return token;
        case '}':
            token.type = RBRACE;
            strcpy(token.lexeme, "}");
            pos++;
            return token;
        case ';':
            token.type = SEMICOLON;
            strcpy(token.lexeme, ";");
            pos++;
            return token;
        case ',':
            token.type = COMMA;
            strcpy(token.lexeme, ",");
            pos++;
            return token;
        case '=':
            token.type = ASSIGN;
            strcpy(token.lexeme, "=");
            pos++;
            return token;

        default:
            if (isalpha(input[pos])) { // Identifiers
                int start = pos;
                while (isalnum(input[pos])) pos++;
                strncpy(token.lexeme, &input[start], pos - start);
                token.lexeme[pos - start] = '\0';
                token.type = ID;
                return token;
            } else if (isdigit(input[pos])) { // Numbers
                int start = pos;
                while (isdigit(input[pos])) pos++;
                strncpy(token.lexeme, &input[start], pos - start);
                token.lexeme[pos - start] = '\0';
                token.type = NUM;
                return token;
            } else { // Unknown character
                printf("Unknown character: %c\n", input[pos]);
                pos++;
                token.type = END_OF_FILE; // Mark as error for unknown characters
                strcpy(token.lexeme, "ERROR");
                return token;
            }
    }

    return token; // Should never reach here
}
