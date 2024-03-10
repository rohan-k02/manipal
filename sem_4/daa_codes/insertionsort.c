#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to perform insertion sort on a linked list
void insertionSort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;  // Empty or single-element list is already sorted
    }

    struct Node* sortedList = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* next = current->next;

        // Insert current node into the sorted list
        if (sortedList == NULL || sortedList->data >= current->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            struct Node* temp = sortedList;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sortedList;  // Update the head of the original list
}

int main() {
    struct Node* head = NULL;
    int size, data;

    // Take user input for the size of the linked list
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    // Take user input for linked list elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    // Perform insertion sort
    insertionSort(&head);

    printf("Sorted linked list: ");
    printList(head);

    // Free dynamically allocated memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
