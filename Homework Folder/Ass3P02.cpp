#include<iostream>
using namespace std;


int nthDigit(int number, int n) {
    int count = 0;
    while (number > 0) {
        count++;
        if (count == n) return number % 10;
        number /= 10;
    }
    return -1; // if n exceeds the number of digits
}


int main() {
    int number, n;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the position of the digit: ";
    cin >> n;
    int result = nthDigit(number, n);
    if (result != -1)
        cout << "The " << n << "th digit is: " << result << endl;
    else
        cout << "The number doesn't have " << n << " digits." << endl;
    return 0;
}