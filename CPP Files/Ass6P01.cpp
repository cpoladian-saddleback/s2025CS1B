#include <iostream>
using namespace std;


void reverseString(char* str) {
    if (str == nullptr) return;

    char* end = str;
    while(*end) {
        ++end;
    }
    --end;

    while (str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        ++str;
        --end;
    }
}




int main() {
    char str[] = "hello";

    cout << "Original String: " << endl;
    reverseString(str);
    cout << "Reversed String: " << endl;

    return 0;
}