#include<iostream>
using namespace std;

int sum_range(int x, int y, int z) { // z is a dummy parameter to be able to do overloading -- bad practice only for demonstration
    if (x == y) {
        return x;
    }
    return x + sum_range(x+1, y, 0);
}

int sum_range(int x, int y) {
    int res = 0;
    for(int i = x; i <= y; i++) {
        res += i;
    }
    return res;
}


int main() {
    cout << "Enter two numbersL ";
    int x, y;
    cin >> x >> y;
    cout << sum_range(x, y) << endl;
}