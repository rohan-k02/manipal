#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexical_analyzer.h" // Include the lexical analyzer header

// Global token variable
Token currentToken;

// Function prototypes for grammar rules
void Program();
void Declarations();
void DeclarationsPrime();
void DataType();
void IdentifierList();
void IdentifierListPrime();
void AssignStat();

void match(TokenType expected) {
    printf("Matching token: %s (type: %d)\n", currentToken.lexeme, currentToken.type);
    if (currentToken.type == expected) {
        currentToken = getNextToken(); // Fetch the next token
    } else {
        printf("Syntax Error: Expected %d but found %d (lexeme: %s)\n", expected, currentToken.type, currentToken.lexeme);
        exit(EXIT_FAILURE);
    }
}


// Recursive Descent Parser Functions

// Program → main () { declarations assign_stat }
void Program()
{
    match(MAIN);
    match(LPAREN);
    match(RPAREN);
    match(LBRACE);
    Declarations(); // Process all declarations
    AssignStat();   // Process assignment statements
    match(RBRACE);
}

// Declarations → data-type identifier-list ; declarations'
void Declarations()
{
    if (currentToken.type == INT || currentToken.type == CHAR)
    {
        DataType();
        IdentifierList();
        match(SEMICOLON);
        DeclarationsPrime();
    }
}

// Declarations' → declarations | ε
void DeclarationsPrime()
{
    if (currentToken.type == INT || currentToken.type == CHAR)
    {
        Declarations(); // Recurse for more declarations
    }
    // ε case: Do nothing
}

// Data-Type → int | char
void DataType()
{
    if (currentToken.type == INT)
    {
        match(INT);
    }
    else if (currentToken.type == CHAR)
    {
        match(CHAR);
    }
    else
    {
        printf("Syntax Error: Expected data type (int or char), but found %s\n", currentToken.lexeme);
        exit(EXIT_FAILURE);
    }
}

// Identifier-List → id identifier-list'
void IdentifierList()
{
    match(ID);             // Match the first identifier
    IdentifierListPrime(); // Handle the rest of the list
}

// Identifier-List' → , identifier-list | ε
void IdentifierListPrime()
{
    if (currentToken.type == COMMA)
    {
        match(COMMA);
        IdentifierList(); // Recurse for more identifiers
    }
    // ε case: Do nothing
}

void AssignStat()
{
    match(ID);     // Match the left-hand side identifier
    match(ASSIGN); // Match '='

    if (currentToken.type == ID)
    {
        match(ID);        // Match right-hand side identifier
        match(SEMICOLON); // Match ';'
    }
    else if (currentToken.type == NUM)
    {
        match(NUM);       // Match right-hand side number
        match(SEMICOLON); // Match ';'
    }
    else
    {
        printf("Syntax Error: Expected ID or NUM after '=', but found %s\n", currentToken.lexeme);
        exit(EXIT_FAILURE);
    }
}

// Main function to drive the parser
int main()
{
    printf("Enter the input program:\n");

    fgets(input, 1000, stdin); // Get input program from user (global variable `input` is in lexical analyzer)

    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input

    currentToken = getNextToken(); // Initialize with the first token

    printf("\nParsing started...\n");

    Program(); // Start parsing from the start symbol

    if (currentToken.type == END_OF_FILE)
    {
        printf("Parsing completed successfully. Input is syntactically correct.\n");
    }
    else
    {
        printf("Syntax Error: Unexpected tokens at the end of input.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
