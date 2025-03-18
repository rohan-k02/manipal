#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexical_analyzer.h"

// Global token variable
Token currentToken;
extern int lineNumber;  // Track line numbers for better error handling

// Function prototypes for grammar rules
void Program();
void Declarations();
void DataType();
void IdentifierList();
void IdentifierListPrime();
void StatementList();
void Statement();
void AssignStat();
void Expn();
void EPrime();
void SimpleExpn();
void SEPrime();
void Term();
void TPrime();
void Factor();
void DecisionStat();
void DPrime();

// Function to convert TokenType to string for better error reporting
const char* tokenTypeToString(TokenType type) {
    switch (type) {
        case MAIN: return "main";
        case INT: return "int";
        case CHAR: return "char";
        case ID: return "identifier";
        case NUM: return "number";
        case LPAREN: return "(";
        case RPAREN: return ")";
        case LBRACE: return "{";
        case RBRACE: return "}";
        case SEMICOLON: return ";";
        case COMMA: return ",";
        case ASSIGN: return "=";
        case RELOP: return "relational operator";
        case ADDOP: return "addition operator";
        case MULOP: return "multiplication operator";
        case IF: return "if";
        case ELSE: return "else";
        case END_OF_FILE: return "EOF";
        default: return "unknown token";
    }
}

// Improved match function with enhanced error reporting
void match(TokenType expected) {
    if (currentToken.type == expected) {
        currentToken = getNextToken();
    } else {
        printf("Syntax Error at line %d: Expected '%s' but found '%s'\n",
               lineNumber, tokenTypeToString(expected), currentToken.lexeme);
        exit(EXIT_FAILURE);
    }
}

// Grammar Rule Implementations
void Program() {
    match(MAIN);
    match(LPAREN);
    match(RPAREN);
    match(LBRACE);
    Declarations();
    StatementList();
    match(RBRACE);
}

void Declarations() {
    while (currentToken.type == INT || currentToken.type == CHAR) {
        DataType();
        IdentifierList();
        match(SEMICOLON);
    }
}

void DataType() {
    if (currentToken.type == INT) {
        match(INT);
    } else if (currentToken.type == CHAR) {
        match(CHAR);
    }
}

void IdentifierList() {
    match(ID);
    IdentifierListPrime();
}

void IdentifierListPrime() {
    if (currentToken.type == COMMA) {
        match(COMMA);
        IdentifierList();
    } else if (currentToken.type == LBRACE) {
        match(LBRACE);
        match(NUM);
        match(RBRACE);
        IdentifierListPrime();
    } else if (currentToken.type == LBRACKET) {
        match(LBRACKET);
        match(NUM);
        match(RBRACKET);
    }
}

void StatementList() {
    do {
        Statement();
    } while (currentToken.type == ID || currentToken.type == IF);
}

void Statement() {
    if (currentToken.type == ID) {
        AssignStat();
        match(SEMICOLON);
    } else if (currentToken.type == IF) {
        DecisionStat();
    } else {
        printf("Syntax Error: Invalid statement at line %d near '%s'\n", 
               lineNumber, currentToken.lexeme);
        exit(EXIT_FAILURE);
    }
}

void AssignStat() {
    match(ID);
    match(ASSIGN);
    Expn();
}

void Expn() {
    SimpleExpn();
    EPrime();
}

void EPrime() {
    if (currentToken.type == RELOP) {
        match(RELOP);
        SimpleExpn();
    }
}

void SimpleExpn() {
    Term();
    SEPrime();
}

void SEPrime() {
    while (currentToken.type == ADDOP) {
        match(ADDOP);
        Term();
    }
}

void Term() {
    Factor();
    TPrime();
}

void TPrime() {
    while (currentToken.type == MULOP) {
        match(MULOP);
        Factor();
    }
}

void Factor() {
    if (currentToken.type == ID) {
        match(ID);
    } else if (currentToken.type == NUM) {
        match(NUM);
    } else {
        printf("Syntax Error: Expected ID or NUM but found '%s'\n", currentToken.lexeme);
        exit(EXIT_FAILURE);
    }
}

void DecisionStat() {
    match(IF);
    match(LPAREN);
    Expn();
    match(RPAREN);
    match(LBRACE);
    StatementList();
    match(RBRACE);
    DPrime();
}

void DPrime() {
    if (currentToken.type == ELSE) {
        match(ELSE);
        match(LBRACE);
        StatementList();
        match(RBRACE);
    }
}

// Main function to drive the parser
int main() {
    FILE *file = fopen("input.c", "r");
    if (!file) {
        perror("Error opening input.c");
        return EXIT_FAILURE;
    }

    fread(input, 1, sizeof(input) - 1, file);
    fclose(file);

    currentToken = getNextToken();
    printf("\nParsing started...\n");

    Program();

    if (currentToken.type == END_OF_FILE) {
        printf("Parsing completed successfully. Input is syntactically correct.\n");
    } else {
        printf("Syntax Error: Unexpected tokens at the end of input.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}