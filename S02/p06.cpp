#include<iostream>
using namespace std;

int find_gcd_rec(int x, int y) {
    if (x==0) {
        return y;
    }
    return gcd(y % x, x)
}

int find_gcd(int x, int y) {
    while (x != 0) {
        x = y % x;
        y = temp;         
    }
    return y;
}


int main() {
    cout << "Enter two numbers: ";
    int x, y;
    cin >> x >> y;
    cout << find_gcd (x) << endl;
    //cout << find_gcd (x, 1) << endl;
}