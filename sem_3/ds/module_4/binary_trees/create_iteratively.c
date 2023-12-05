#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
void insertNode(struct TreeNode** root, int data) {
    struct TreeNode* newNode = createNode(data);

    // If the tree is empty, set the new node as the root
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Use a queue for iterative insertion
    struct TreeNode* current;
    struct TreeNode* temp;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int front = 0;
    int rear = 0;

    // Enqueue the root
    queue[rear++] = *root;

    // Perform level order traversal and insert the new node at the first empty position
    while (front < rear) {
        current = queue[front++];

        if (current->left == NULL) {
            current->left = newNode;
            free(queue);
            return;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = newNode;
            free(queue);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

// Function to print the inorder traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes into the binary tree
    insertNode(&root, 1);
    insertNode(&root, 2);
    insertNode(&root, 3);
    insertNode(&root, 4);
    insertNode(&root, 5);

    // Print the inorder traversal of the binary tree
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}
