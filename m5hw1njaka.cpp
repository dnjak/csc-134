#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
CSC 134
M5HW1 - Gold
Daniel Njaka
11/2/2026
*/

// FUNCTION PROTOTYPES
void question1();

int main() {
  int choice = 0;

  // keep showing the menu until the user picks 6
  while (choice != 6) {
    cout << endl;
    cout << "M5HW1 Menu" << endl;
    cout << "1. Average Rainfall" << endl;
    cout << "2. Block Volume" << endl;
    cout << "3. Roman Numerals" << endl;
    cout << "4. Geometry Calculator" << endl;
    cout << "5. Distance Traveled" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    // if they typed a letter, reset cin so the loop doesn't break
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      choice = 0;
    }

    if (choice == 1) {
      question1();
    } else if (choice >= 2 && choice <= 5) {
      cout << "Not done yet." << endl;
    } else if (choice == 6) {
      cout << "Goodbye!" << endl;
    } else {
      cout << "The valid choices are 1 through 6. Please try again." << endl;
    }
  }

  return 0;
}

// FUNCTION DEFINITIONS

// Question 1: average rainfall for three months
void question1() {
  string month1, month2, month3;
  double rain1, rain2, rain3;

  cout << "Enter month: ";
  cin >> month1;
  cout << "Enter rainfall for " << month1 << ": ";
  cin >> rain1;

  cout << "Enter month: ";
  cin >> month2;
  cout << "Enter rainfall for " << month2 << ": ";
  cin >> rain2;

  cout << "Enter month: ";
  cin >> month3;
  cout << "Enter rainfall for " << month3 << ": ";
  cin >> rain3;

  double average = (rain1 + rain2 + rain3) / 3.0;

  cout << fixed << setprecision(2);
  cout << "The average rainfall for " << month1 << ", " << month2
       << ", and " << month3 << " is " << average << " inches." << endl;
}