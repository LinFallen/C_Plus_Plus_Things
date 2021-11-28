#include <iostream>
#include <cmath>

using namespace std;

/*
 * Class: Clock
 */
class Clock {
    int Hour, Minute, Second;
public:
    Clock(int h = 0, int m = 0, int s = 0);
        void ShowTime();
        Clock& operator++();
        Clock operator++(int);
    
};

/*
 * Class Clock: Constructor
 */
Clock::Clock(int h, int m, int s) {
   if (h > 0 && h < 24 && m > 0 && m < 60 && s > 0 && s < 60) {
       Hour = h;
       Minute = m;
       Second = s;
    }   
    else {
        cout << "Invalid time" << endl;
    }
}

/*
 * Class Clock: ShowTime
 */
void Clock::ShowTime() {
    cout << Hour << ":" << Minute << ":" << Second << endl;
}

/*
 * Class Clock: Overload ++
 * 时间递增一秒（重载前缀++运算符）
 */
Clock& Clock::operator++() {
    Second++;
    if (Second >= 60) {
        Second -= 60;
        Minute++;

        if (Minute >= 60) {
            Minute -= 60;
            Hour++;
            Hour %= 24;
        }
    }

    return *this;
}

/*
 * Class Clock: Overload ++
 * 时间递增一秒（重载后缀++运算符）
 */
Clock Clock::operator++(int) {
    Clock temp = *this;
    ++(*this);
    return temp;
}

int main() {
    Clock myClock(23, 59, 59);
    cout << "Initial Time: ";
    myClock.ShowTime();

    cout << "The Time after myClock++: ";

    // first execute ShowTime, output: 23:59:59
    // then execute myClock++, output: 00:00:00
    (myClock++).ShowTime();

    cout << "The Time after ++myClock: ";

    // first execute ++myClock, output: 00:00:01
    // then execute ShowTime, output: 00:00:01
    (++myClock).ShowTime();

    system("pause");

    return 0;
}