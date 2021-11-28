#include <iostream>

using namespace std;

int main() {

    cout << "Hello World!" << endl;

    // judge a number is odd or even
    int num = 0;
    cout << "Please input a number: ";
    cin >> num;
    if (num % 2 == 0) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }
    


    cin.get();

    return 0;
}