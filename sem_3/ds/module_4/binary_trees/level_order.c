#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a queue node
struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to enqueue a node in the queue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to dequeue a node from the queue
struct TreeNode* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL) {
        return NULL;
    }

    struct TreeNode* node = (*front)->node;
    struct QueueNode* temp = *front;

    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);

    return node;
}

// Function to perform level order traversal using a queue
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    // Enqueue the root
    enqueue(&front, &rear, root);

    while (front != NULL) {
        // Dequeue a node and process it
        struct TreeNode* current = dequeue(&front, &rear);
        printf("%d ", current->data);

        // Enqueue the left child if exists
        if (current->left != NULL) {
            enqueue(&front, &rear, current->left);
        }

        // Enqueue the right child if exists
        if (current->right != NULL) {
            enqueue(&front, &rear, current->right);
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

    // Perform level order traversal and print the result
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
