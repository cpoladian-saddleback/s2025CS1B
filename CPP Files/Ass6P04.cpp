#include <iostream>
#include <fstream>

// Function to allocate a 3D array dynamically
int*** allocate3DArray(int dim1, int dim2, int dim3) {
    int*** arr = new int**[dim1];
    for (int i = 0; i < dim1; i++) {
        arr[i] = new int*[dim2];
        for (int j = 0; j < dim2; j++) {
            arr[i][j] = new int[dim3];
        }
    }
    return arr;
}

// Function to fill the 3D array from a file
void fill3DArray(int*** arr, int dim1, int dim2, int dim3, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file!\n";
        return;
    }

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                file >> *(*(*(arr + i) + j) + k); // Pointer arithmetic
            }
        }
    }
    file.close();
}

// Function to print the 3D array
void print3DArray(int*** arr, int dim1, int dim2, int dim3) {
    std::cout << "3D Array:\n";
    for (int i = 0; i < dim1; i++) {
        std::cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                std::cout << *(*(*(arr + i) + j) + k) << " "; // Pointer arithmetic
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

// Function to deallocate the 3D array
void deallocate3DArray(int*** arr, int dim1, int dim2) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int dim1 = 3, dim2 = 4, dim3 = 5;
    int*** arr = allocate3DArray(dim1, dim2, dim3);

    fill3DArray(arr, dim1, dim2, dim3, "data.txt");
    print3DArray(arr, dim1, dim2, dim3);

    deallocate3DArray(arr, dim1, dim2);
    return 0;
}
