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

// Function to perform inorder traversal using a stack
void inorderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct StackNode* stack = NULL;

    while (current != NULL || stack != NULL) {
        // Traverse to the leftmost node of the current subtree
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        // Process the current node
        current = pop(&stack);
        printf("%d ", current->data);

        // Move to the right subtree
        current = current->right;
    }
}

int main() {
    // Constructing a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform inorder traversal and print the result
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}
