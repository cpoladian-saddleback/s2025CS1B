#include <iostream>

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = *(arr + i); // Current element
        int j = i - 1;

        // Shift elements that are greater than key to one position ahead
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key; // Insert key at the correct position
    }
}

// Function to print the array
void printArray(int* arr, int size) {
    std::cout << "Sorted Array: [";
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i);
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    int arr[] = {4, 2, 7, 1, 3}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}
