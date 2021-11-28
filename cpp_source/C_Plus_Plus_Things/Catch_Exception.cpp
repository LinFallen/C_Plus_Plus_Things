#include <iostream>

using namespace std;

void fun(int x) {
    try {
        if (x == 0) {
            throw "THERE IS AN EXCEPTION!!!";
        }
    } catch (...) {
        cout << "IN fun" << endl;
        throw 1;
    }
    
}

int main() {
    try {
        fun(0);
    } catch (int n) {
        cout << "IN main" << endl;
    }

    system("pause");

    return 0;
}