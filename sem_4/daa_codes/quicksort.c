#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the lowest element as the pivot (i)
    int i = low;
    int j = high;

    while (i < j) {
        // Find an element smaller than or equal to the pivot from the right
        while (arr[j] > pivot) {
            j--;
        }

        // Find an element greater than or equal to the pivot from the left
        while (arr[i] < pivot) {
            i++;
        }

        // Swap the found elements
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    return i;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr;
    int size;

    // Take user input for array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));

    // Take user input for array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
