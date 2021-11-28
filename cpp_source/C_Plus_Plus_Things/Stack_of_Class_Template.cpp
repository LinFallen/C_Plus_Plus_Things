#include <iostream>

using namespace std;

template <typename T, int MAXSIZE>

class Stack {
public:
    Stack() {}

    void init() {
        top = - 1;
    }

    bool IsFull() {
        if (top >= MAXSIZE - 1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool IsEmpty() {
        if (top == 1) {
            return true;
        }
        else {
            return false;
        }
    }

    void Push(T e);

    T pop();

private:
    T elems[MAXSIZE];
    int top;
};

template<typename T, int MAXSIZE> void Stack<T, MAXSIZE>::Push(T e) {
    if (IsFull()) {
        elems[++top] = e;
    }
    else {
        cout << "Stack is full, please don't insert elements!" << endl;
        return;
    }
}

template<typename T, int MAXSIZE> T Stack<T, MAXSIZE>::pop() {
    if (!IsEmpty()) {
        return elems[top--];
    }
    else {
        cout << "Stack is empty, please don't pop elements!" << endl;
        return 0;
    }
}

int main() {
    Stack<int, 10> s;
    s.init();

    for (int i = 1; i <= 10; i++) {
        s.Push(i);
    }

    for (int i = 1; i <= 10; i++) {
        cout << s.pop() << endl;
    }

    cout << endl;

    system("pause");

    return 0;
}