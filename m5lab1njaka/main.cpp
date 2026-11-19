#include <iostream>
#include <limits>
using namespace std;

/*
csc 134
m5lab1 choose your own adventure
daniel njaka
11/19/2026
*/

void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void search_the_kitchen();
void hide_in_the_pantry();

int main() {
  cout << "m5lab1 choose your own adventure" << endl;
  main_menu();
  cout << "thanks for playing" << endl;
  return 0;
}

void main_menu() {
  cout << "main menu" << endl;
  cout << "you are in front of a spooky old house" << endl;
  cout << "do you" << endl;
  cout << "1 try the front door" << endl;
  cout << "2 sneak around back" << endl;
  cout << "3 forget it and go home" << endl;
  cout << "4 quit" << endl;
  cout << "choose ";
  int choice = 0;
  cin >> choice;
  if (cin.fail()) {
    cin.clear();
    choice = 0;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_go_home();
  } else if (4 == choice) {
    cout << "ok quitting the game" << endl;
    return;
  } else {
    cout << "that is not a valid choice so please try again" << endl;
    main_menu();
  }
}

void choice_front_door() {
  cout << "you try the front door" << endl;
  cout << "it is locked" << endl;
  cout << "do you" << endl;
  cout << "1 check around back" << endl;
  cout << "2 give up and go home" << endl;
  int choice = 0;
  cout << "choose ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_back_door() {
  cout << "you sneak around to the back of the house" << endl;
  cout << "the back door is cracked open and you can see a dark kitchen inside" << endl;
  cout << "do you" << endl;
  cout << "1 go inside and search the kitchen" << endl;
  cout << "2 get scared and go home" << endl;
  int choice = 0;
  cout << "choose ";
  cin >> choice;
  if (1 == choice) {
    search_the_kitchen();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_go_home() {
  cout << "you decide this house is not worth it and walk back home" << endl;
  cout << "you never find out what was inside" << endl;
  cout << "the end ending 1 of 2" << endl;
}

void search_the_kitchen() {
  cout << "you step into the kitchen and the floor creaks under your feet" << endl;
  cout << "upstairs you hear slow footsteps coming toward the stairs" << endl;
  cout << "do you" << endl;
  cout << "1 hide in the pantry" << endl;
  cout << "2 run back outside and go home" << endl;
  int choice = 0;
  cout << "choose ";
  cin >> choice;
  if (1 == choice) {
    hide_in_the_pantry();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void hide_in_the_pantry() {
  cout << "you squeeze into the pantry and pull the door shut" << endl;
  cout << "the footsteps walk right past you and fade away" << endl;
  cout << "behind a jar of pickles you find an old box full of gold coins" << endl;
  cout << "the end ending 2 of 2" << endl;
}