/*
    1.	Scan the infix expression from left to right. 
    2.	If the scanned character is an operand, put it in the postfix expression. 
    3.	Otherwise, do the following
        •	If the precedence scanned operator is greater than the precedence of the operator at the top of the stack [or the stack is empty or the stack contains a ‘(‘ ], then push it in the stack.
            •	In all the other cases when the top of the operator stack is the same as the scanned operator or if the precedence if lower, then pop the operator from the stack.
        •	Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
            •	After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
    4.	If the scanned character is a ‘(‘, push it to the stack. 
    5.	If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
    6.	Repeat steps 2-5 until the infix expression is scanned. 
    7.	Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
    8.	Finally, print the postfix expression.

*/





// C code to convert infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

// Function to return precedence of operators
int precedence(char operator)
{
	switch (operator) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

// Function to check if the scanned character 
// is an operator
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
			|| ch == '^');
}

// Main functio to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
	int i, j;
	int len = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char) * (len + 2));
	char stack[MAX_EXPR_SIZE];
	int top = -1;

	for (i = 0, j = 0; i < len; i++) {
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;
	
		// If the scanned character is operand
		// add it to the postfix expression
		if (isalnum(infix[i])) {
			postfix[j++] = infix[i];
		}
	
		// if the scanned character is '('
		// push it in the stack
		else if (infix[i] == '(') {
			stack[++top] = infix[i];
		}
	
		// if the scanned character is ')'
		// pop the stack and add it to the 
		// output string until empty or '(' found
		else if (infix[i] == ')') {
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			
				top--;
		}
	
		// If the scanned character is an operator
		// push it in the stack
		else if (isOperator(infix[i])) {
			while (top > -1
				&& precedence(stack[top])
						>= precedence(infix[i]))
				postfix[j++] = stack[top--];
			stack[++top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while (top > -1) {
		if (stack[top] == '(') {
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}

// Driver code
int main()
{
	char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

	// Function call
	char* postfix = infixToPostfix(infix);
	printf("%s\n", postfix);
	free(postfix);
	return 0;
}
