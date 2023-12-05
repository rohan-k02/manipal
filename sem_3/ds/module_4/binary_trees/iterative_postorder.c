#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a stack node
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode** stack, struct TreeNode* node) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = node;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** stack) {
    if (*stack == NULL) {
        return NULL;
    }

    struct StackNode* temp = *stack;
    struct TreeNode* poppedNode = temp->node;
    *stack = temp->next;
    free(temp);
    return poppedNode;
}

// Function to perform postorder traversal using two stacks
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    // Push the root node onto the first stack
    push(&stack1, root);

    // Continue until the first stack is empty
    while (stack1 != NULL) {
        // Pop a node from the first stack
        struct TreeNode* current = pop(&stack1);

        // Push the popped node onto the second stack
        push(&stack2, current);

        // Push the left child onto the first stack if it exists
        if (current->left != NULL) {
            push(&stack1, current->left);
        }

        // Push the right child onto the first stack if it exists
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    // Print the nodes from the second stack to get the postorder traversal
    while (stack2 != NULL) {
        struct TreeNode* node = pop(&stack2);
        printf("%d ", node->data);
    }
}

int main() {
    // Constructing a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform postorder traversal and print the result
    printf("Postorder Traversal: ");
    postorderTraversal(root);

    return 0;
}
