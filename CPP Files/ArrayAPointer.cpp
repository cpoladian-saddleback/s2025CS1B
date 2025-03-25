#include<iostream>
using namespace std;


void swap(int* a. int* b) {

}

int main() {
    int a[] = {3, 5, 2, 9, 1, 3};
    int* p = a;
    for(int i = 0; i < 6; i++) {
        //cout << p[i] << " ";
        cout << *(p + i) << " ";
    }
    cout << endl;
}