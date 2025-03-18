#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

typedef enum {
    MAIN, LPAREN, RPAREN, LBRACE, RBRACE,
    INT, CHAR, ID, SEMICOLON,
    COMMA, NUM, ASSIGN, RELOP, ADDOP, MULOP,
    IF, ELSE, 
    LBRACKET, RBRACKET,   // Correctly included for array references
    END_OF_FILE,          // Ensure EOF is before ERROR for correct termination logic
    ERROR                 // Keep this as the final token for clarity
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

extern char input[1000];
Token getNextToken();

#endif // LEXICAL_ANALYZER_H
