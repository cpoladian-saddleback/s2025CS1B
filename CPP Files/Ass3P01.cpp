#include<iostream>
using namespace std;


bool isPerfectNumber(int n) {
    if (n <= 1) return false;
    int sum = 1;
    for (int i = 2; i * i <= n, i++) {
        if(n % i == 0) {
            sum += 1;
            if(i != n / i) sum += n / i;  // add the corresponding divisor
        }
    }
    return sum == n;
}


int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(isPerfectNumber(num))
    cout << " is a perfect number." << endl;
    else
    cout << num << " is not a perfect number." << endl;

    return 0;
}