#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

// Token types enumeration
typedef enum {
    MAIN, LPAREN, RPAREN, LBRACE, RBRACE, INT, CHAR, ID, NUM,
    ASSIGN, SEMICOLON, COMMA, END_OF_FILE
} TokenType;

// Token structure definition
typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

// Function prototype for getNextToken()
Token getNextToken();

// Declare global variables as extern
extern char input[1000];
extern int pos;

#endif // LEXICAL_ANALYZER_H
