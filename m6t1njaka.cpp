// njakad
// 11/9/26
// m6t1
#include <iostream>
using namespace std;

void method1();
void method2();

int main() {
    
    method1();
    method2();
    
    return 0;
    
}

void method1() {
    string item = "pokemon";
    cout << "count how many " << item << " were seen each day." << endl;
    const int SIZE = 5;
    int counts [SIZE];
    int total = 0;
    double average = 0;
    for (int i=0; i < SIZE; i++) {
        cout << "day " << i+1 << ": ";
        cin >> counts[i];
        total += counts[i];
      }
      cout << "total " << item << " seen: " << total << endl;
      average = (double) total / SIZE;
      cout << "average per day: " << average << endl;
    
}

void method2() {
    string item = "pokemon";
    cout << "count how many " << item << " were seen each day." << endl;
    const int SIZE = 5;
    int total = 0;
    int today;
    double average  = 0;
    for (int i=0; i < SIZE; i++) {
        cout << "day " << i+1 << ": ";
        cin >> today;
        total += today;
    }
    cout << "total " << item << " seen: " << total << endl;
      average = (double) total / SIZE;
      cout << "average per day: " << average << endl;
}