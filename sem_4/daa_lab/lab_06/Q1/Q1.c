/* Find total number of nodes in a binary tree and analyze its efficiency. Obtain the
experimental result of order of growth and plot the result. */
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new binary tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count the total number of nodes in a binary tree
int countNodes(TreeNode* root, int* count) {
    if (root == NULL) {
        return 0;
    }
    *count+=1;
    return 1 + countNodes(root->left, count) + countNodes(root->right, count);
}

// Function to free the memory allocated for the binary tree nodes
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to create a binary tree interactively
TreeNode* createBinaryTree() {
    int data;
    printf("Enter data for the node (enter -1 to indicate NULL): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    TreeNode* newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = createBinaryTree();
    printf("Enter right child of %d:\n", data);
    newNode->right = createBinaryTree();
    return newNode;
}

int main() {
    int count = 0;
    // Create a binary tree interactively
    TreeNode* root = createBinaryTree();

    // Count the total number of nodes in the binary tree
    int totalNodes = countNodes(root, &count);
    printf("Total number of nodes in the binary tree: %d\n", totalNodes);

    // Free the memory allocated for the binary tree nodes
    freeTree(root);

    return 0;
}
