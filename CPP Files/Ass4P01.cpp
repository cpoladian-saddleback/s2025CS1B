#include<iostream>
#include<string>
using namespace std;

enum class DayOfWeek {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

DayOfWeek getNextDay(DayOfWeek today) {
    return (today == DayOfWeek::Sunday) ? DayOfWeek::Monday : static_cast<DayOfWeek>(static_cast<int>(today) + 1);
}
    void printDay(DayOfWeek day) {
        switch (day) {
            case DayOfWeek::Monday: cout << "Monday"; break;
            case DayOfWeek::Tuesday: cout << "Tuesday"; break;
            case DayOfWeek::Wednesday: cout << "Wednesday"; break;
            case DayOfWeek::Thursday: cout << "Thursday"; break;
            case DayOfWeek::Friday: cout << "Friday"; break;
            case DayOfWeek::Saturday: cout << "Saturday"; break;
            case DayOfWeek::Sunday: cout << "Sunday"; break;
        }
    }
    

int main() {
    int dayInput;
    cout << "Enter current day (1 through 7 for valid input - 1 for Monday, 7 for Sunday): ";
    cin >> dayInput;

    if (cin.fail() || dayInput < 1 || dayInput > 7) {
        cout << "Invalid input. Please enter a number between 1 and 7." << endl;
        return 1;
    }
    
    DayOfWeek today = static_cast<DayOfWeek>(dayInput);
    DayOfWeek nextDay = getNextDay(today);
    
    cout << "Next day is: ";
    printDay(nextDay);
    cout << endl;
    
    return 0;
}

