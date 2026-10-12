// csc134
// m4lab1
// daniel njaka
// 10/12/26

#include <iostream>
using namespace std;

int main () {
    string token = "✅";
    int width, height;
    cout << "enter rectangle width: ";
    cin >> width;
    cout << "enter rectangle height: ";
    cin >> height;
    
    cout << "part 1 " << endl;
    for (int i = 0; i < width; i++) {
        cout << token << " ";
    }
    cout << endl;
    
    cout << "part 2 " << endl;
    for (int j = 0; j < height; j++) {
        cout << token << endl;
    }
    
    cout << "here is your rectangle " << width << " by " << height << endl;
    for (int j = 0; j < height; j++){
        for (int i = 0; i < width; i++) {
            cout << token << " ";
        }
        cout << endl;
    }
}