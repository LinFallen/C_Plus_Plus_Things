#include <iostream>

using namespace std;

class Time {
private:
    int hh;
    int mm;
    int ss;

public:
    Time(int h = 0, int m = 0, int s = 0):hh(h), mm(m), ss(s) {}
    
    void operator()(int h, int m, int s) {
        hh = h;
        mm = m;
        ss = s;
    }

    void ShowTime() {
        cout << hh << ":" << mm << ":" << ss << endl;
    }
};


int main() {
    Time time(12, 34, 56);
    time.ShowTime();

    time.operator()(23, 45, 37);
    time.ShowTime();

    time(10, 10, 10);
    time.ShowTime();

    system("pause");

    return 0;
}