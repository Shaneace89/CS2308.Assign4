/*// The PasswordManager class
// A 12 hour clock
// Driver (main) in a separate file

#include<iostream>
#include "PasswordManager.h"
using namespace std;


//Driver demo using PasswordManager class

int main() {
    PasswordManager t;
    t.setHour(12);
    t.setMinute(58);
    cout << t.display() <<endl;
    t.addMinute();
    cout << t.display() << endl;
    t.addMinute();
    cout << t.display() << endl;
    return 0;
}
*/