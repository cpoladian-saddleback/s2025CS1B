#include<iostream>
using namespace std;


int findMaxIn2DArray(int arr[5][5], int rows) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < 5; j++){
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}


int main() {
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };

    cout << "The maximum value in the array is: " << findMaxIn2DArray(arr, 5)
    return 0;
}