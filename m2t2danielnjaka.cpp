/*
csc 134
m2t2 - receipt calculator
njakad
9/28/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    string item = "pizza";
    double item_price = 5.99;
    double tax_percent = 0.08;
    double tax_amount;
    double total;
    
    cout << "welcome to our csc  134 restaurant!" << endl;
    cout << "you ordered one " << item << "." << endl;
    
    tax_amount = item_price * tax_percent;
    total = item_price + tax_amount;
    
    cout << setprecision(2) << fixed;
    cout << "thank you for shopping with us" << endl;
    cout << "------------------------------" << endl;
    cout << item << "\t$" << item_price      << endl;
    cout << "tax" << "\t\t$" << tax_amount   << endl;
    cout << "------------------------------" << endl;
    cout << "total" << "\t\t$" << total   << endl;
    cout << endl;
    
    return 0;

}
      
