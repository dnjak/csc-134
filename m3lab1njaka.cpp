// csc 134
// m3lab1 choices and functions
// daniel njaka
// 11/2/2026

#include <iostream>
using namespace std;

// declare the functions that main will use
void chooseFight();
void chooseRun();
void swingSword();
void raiseShield();

int main() {

  int choice;

  // set the scene and ask the first question
  cout << "a wild goblin jumps out of the bushes" << endl;
  cout << "do you fight or run" << endl;
  cout << "1 fight" << endl;
  cout << "2 run" << endl;
  cout << "type 1 or 2 ";
  cin >> choice;

  if (1 == choice) {
    chooseFight();
  }
  else if (2 == choice) {
    chooseRun();
  }
  else {
    cout << "sorry that is not a valid choice" << endl;
  }

  cout << "thanks for playing" << endl;
  return 0; // finished with no errors

} // end of main

// main calls this if the user picks 1
// it has two choices of its own
void chooseFight() {
  int choice;

  cout << "you draw your sword and face the goblin" << endl;
  cout << "the goblin swings its club at you" << endl;
  cout << "1 swing your sword" << endl;
  cout << "2 raise your shield" << endl;
  cout << "type 1 or 2 ";
  cin >> choice;

  if (1 == choice) {
    swingSword();
  }
  else if (2 == choice) {
    raiseShield();
  }
  else {
    cout << "you freeze up and the goblin steals your lunch" << endl;
  }
}

// main calls this if the user picks 2
void chooseRun() {
  cout << "you run as fast as you can back down the trail" << endl;
  cout << "you are safe but you hear the goblin laughing at you" << endl;
}

// chooseFight calls this if the user picks 1
void swingSword() {
  cout << "you swing first and knock the club out of its hands" << endl;
  cout << "the goblin runs away and drops a bag of gold so you win" << endl;
}

// chooseFight calls this if the user picks 2
void raiseShield() {
  cout << "the club bounces off your shield with a loud clang" << endl;
  cout << "the goblin gets bored and wanders off so it is a tie" << endl;
}