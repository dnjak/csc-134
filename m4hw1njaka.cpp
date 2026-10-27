// CSC 134
// m4hw1 - gold
// Daniel Njaka
// 10/27/2026

#include <iostream>
#include <limits>
using namespace std;

int main() {

    int tableNumber;

    // loop 1: keep asking until the user enters a number from 1 to 12
    cout << "enter a number from 1 to 12: ";
    cin >> tableNumber;

    while (cin.fail() || tableNumber < 1 || tableNumber > 12) {
        cin.clear();                                          // reset cin after bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the rest of the line
        cout << "error: that's not a number from 1 to 12." << endl;
        cout << "enter a number from 1 to 12: ";
        cin >> tableNumber;
    }

    // loop 2: print the times table from 1 to 12
    int multiplier = 1;

    while (multiplier <= 12) {
        int product = tableNumber * multiplier;
        cout << tableNumber << " times " << multiplier << " is " << product << "." << endl;
        multiplier++;
    }

    return 0;
}