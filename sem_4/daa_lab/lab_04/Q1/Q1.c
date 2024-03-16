#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate the cost of assignment
int calculateCost(int matrix[MAX_SIZE][MAX_SIZE], int assignment[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += matrix[i][assignment[i]];
    }
    return totalCost;
}

// Function to find all possible permutations using recursion
void findPermutations(int matrix[MAX_SIZE][MAX_SIZE], int assignment[], int currentRow, int n, int *minCost, int bestAssignment[]) {
    if (currentRow == n - 1) {
        int currentCost = calculateCost(matrix, assignment, n);
        if (currentCost < *minCost) {
            *minCost = currentCost;
            copyArray(bestAssignment, assignment, n);
        }
        return;
    }
    for (int i = currentRow; i < n; i++) {
        swap(&assignment[currentRow], &assignment[i]);
        findPermutations(matrix, assignment, currentRow + 1, n, minCost, bestAssignment);
        swap(&assignment[currentRow], &assignment[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of workers/tasks: ");
    scanf("%d", &n);

    int matrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int assignment[MAX_SIZE], bestAssignment[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        assignment[i] = i;  // Initialize assignment array to 0, 1, 2, ..., n-1
    }

    int minCost = INT_MAX;
    findPermutations(matrix, assignment, 0, n, &minCost, bestAssignment);

    printf("Minimum cost: %d\n", minCost);
    printf("Best Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", i + 1, bestAssignment[i] + 1);  // +1 for 1-based indexing
    }
    printf("\n");

    return 0;
}
