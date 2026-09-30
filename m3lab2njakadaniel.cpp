// csc 134
// m3lab2 letter grades
// njakad
// 9/30/26
// convert number grades to letter grades

#include <iostream>
using namespace std;

int main() {
    cout << "welcome to the number grade to letter grade conversion program" << endl << endl;
    cout << "enter a number grade (0-100): ";
    
    int num_grade;
    char letter_grade = '-';
    
    cin >> num_grade;
    cout << "you entered: " << num_grade << endl;
    
    if (num_grade >= 90) {
        letter_grade = 'A';
    }
    else if (num_grade >= 80) {
       letter_grade = 'B'; }
    else if (num_grade >= 70) {
       letter_grade = 'C';}
    else if (num_grade >= 60){
       letter_grade = 'D';}
    else letter_grade = 'F';
   
  
    cout << "number grade: " << num_grade << endl;
    cout << "letter grade: " << letter_grade << endl;
    
    return 0;

}