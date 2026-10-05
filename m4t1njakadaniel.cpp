// csc 134
// m4t1 basic loops
// njakad
// 10/5/26

#include <iostream>
using namespace std;


int main() {
    int count = 1;
    while (count <= 5) {
        cout << "Hello #" << count << endl;
        count++;
    }
    
    const int MIN_NUM = 1;
    const int MAX_NUM =  10;
    
    cout << endl << "Num      Num Squared" << endl;
    cout << "----------------------" << endl;
    int i = MIN_NUM;
    while (i <= MAX_NUM) {
        cout << i << "\t" << i*i << endl;
        i++;
    }
}