// The Time class
// A 12 hour clock
// class declaration, member function definitions and driver (main)
// all in a single file.

#include <string>
#include <iomanip>
#include <sstream>
#include<iostream>
using namespace std;

// models a 12 hour clock
class Time        //new data type
{
private:
    int hour;
    int minute;
    void addHour();
    
public:
    void setHour(int);
    void setMinute(int);
    int getHour() const;
    int getMinute() const;
    
    string display() const;
    void addMinute();
};

// class function implementations

void Time::setHour(int hr) {
    hour = hr;           // hour is a member var
}
void Time::setMinute(int min) {
    minute = min;        // minute is a member var
}
int Time::getHour() const {
    return hour;
}
int Time::getMinute() const {
    return minute;
}

void Time::addHour() {  // a private member func
    if (hour == 12)
        hour = 1;
    else
        hour++;
}
void Time::addMinute()
{
    if (minute == 59) {
        minute = 0;
        addHour();   // call to private member func
    } else
        minute++;
}

string Time::display() const {
    // returns time in string formatted to hh:mm
    ostringstream sout;
    sout.fill('0');
    sout << hour << ":" << setw(2) << minute;
    return sout.str();
}

//Driver demo using Time class

int main() {
    Time t;
    t.setHour(12);
    t.setMinute(58);
    cout << t.display() <<endl;
    t.addMinute();
    cout << t.display() << endl;
    t.addMinute();
    cout << t.display() << endl;
    return 0;
}
