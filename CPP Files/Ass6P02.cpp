#include <iostream>

int* mergeArrays(int* arr1, int size1, int* arr2, int size2) {
    int* mergedArray = new int[size1 + size2]; // Allocate memory dynamically
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1, if any
    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2, if any
    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }

    return mergedArray; // Return pointer to merged array
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int* mergedArray = mergeArrays(arr1, size1, arr2, size2);

    std::cout << "Merged Array: [";
    for (int i = 0; i < size1 + size2; i++) {
        std::cout << mergedArray[i];
        if (i < size1 + size2 - 1) std::cout << ", ";
    }
    std::cout << "]\n";

    delete[] mergedArray; // Free allocated memory
    return 0;
}
