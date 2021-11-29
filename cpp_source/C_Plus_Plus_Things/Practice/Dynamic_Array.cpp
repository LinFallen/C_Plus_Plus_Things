#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char* sPtr;
    const char* s = "Hello";
    
    sPtr = new char[strlen(s) + 1];
    strncpy(sPtr, s, strlen(s));

    cout << sPtr << endl;

    delete sPtr;

    system("pause");

    return 0;
}