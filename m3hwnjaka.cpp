// csc 134
// m3hw1 gold
// daniel njaka
// 11/2/2026

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// one function for each question
void question1();
void question2();
void question3();
void question4();

int main() {
  // seed the random numbers once for question 4
  srand(time(0));

  cout << "question 1" << endl;
  question1();
  cout << endl;

  cout << "question 2" << endl;
  question2();
  cout << endl;

  cout << "question 3" << endl;
  question3();
  cout << endl;

  cout << "question 4" << endl;
  question4();

  return 0; // finished with no errors
}

// question 1 a simple chat bot with three different answers
void question1() {
  string answer;

  cout << "hello i am a c++ program" << endl;
  cout << "do you like me please type yes or no" << endl;
  cin >> answer;

  if (answer == "yes") {
    cout << "that is great i am sure we will get along" << endl;
  }
  else if (answer == "no") {
    cout << "well maybe you will learn to like me later" << endl;
  }
  else {
    cout << "if you are not sure that is ok" << endl;
  }
}

// question 2 receipt calculator with a tip for dine in orders
void question2() {
  const double TAX_RATE = 0.0475;  // north carolina state sales tax rate
  const double TIP_RATE = 0.15;

  double mealPrice;
  int orderType;
  double tip = 0.0;  // stays 0 if the order is to go

  cout << "enter the price of the meal ";
  cin >> mealPrice;
  cout << "enter 1 if the order is dine in or 2 if it is to go ";
  cin >> orderType;

  double tax = mealPrice * TAX_RATE;

  // only dine in orders get a tip
  if (orderType == 1) {
    tip = mealPrice * TIP_RATE;
  }

  double total = mealPrice + tax + tip;

  cout << fixed << setprecision(2);
  cout << "--------------------" << endl;
  cout << "meal price  $" << setw(8) << mealPrice << endl;
  cout << "tax         $" << setw(8) << tax << endl;
  if (orderType == 1) {
    cout << "tip         $" << setw(8) << tip << endl;
  }
  cout << "--------------------" << endl;
  cout << "total due   $" << setw(8) << total << endl;
}

// question 3 choose your own adventure with a nested if
void question3() {
  int firstChoice;
  int secondChoice;

  cout << "you wake up in a dark cave and see two tunnels" << endl;
  cout << "1 take the tunnel with the cold wind" << endl;
  cout << "2 take the tunnel with the strange humming" << endl;
  cout << "type 1 or 2 ";
  cin >> firstChoice;

  if (firstChoice == 1) {
    // this choice leads to the second question
    cout << "the wind leads you to a sleeping bear blocking the exit" << endl;
    cout << "1 sneak past the bear" << endl;
    cout << "2 throw a rock at the bear" << endl;
    cout << "type 1 or 2 ";
    cin >> secondChoice;

    if (secondChoice == 1) {
      cout << "you tiptoe past the bear and step out into the sunlight" << endl;
      cout << "victory you escaped the cave" << endl;
    }
    else {
      cout << "the bear wakes up and it is not happy" << endl;
      cout << "defeat the bear chases you deeper into the cave" << endl;
    }
  }
  else {
    // this choice is an instant game over
    cout << "the humming was a giant nest of bees" << endl;
    cout << "game over" << endl;
  }
}

// question 4 math practice with two random single digit numbers
void question4() {
  int num1 = rand() % 10;  // 0 through 9
  int num2 = rand() % 10;
  int userAnswer;

  cout << "what is " << num1 << " plus " << num2 << " ";
  cin >> userAnswer;

  if (userAnswer == num1 + num2) {
    cout << "correct" << endl;
  }
  else {
    cout << "incorrect the answer is " << (num1 + num2) << endl;
  }
}