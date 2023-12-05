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

// Function to perform preorder traversal using a stack
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (stack != NULL) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        // Push the right child first (since we want to process left before right in preorder)
        if (current->right != NULL) {
            push(&stack, current->right);
        }

        // Push the left child
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

int main() {
    // Constructing a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform preorder traversal and print the result
    printf("Preorder Traversal: ");
    preorderTraversal(root);

    return 0;
}
