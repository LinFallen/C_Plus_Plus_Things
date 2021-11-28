#include <iostream>
#include <cstring>

using namespace std;

#define MAXSIZE 5

template <class T>

class Array {
public:
    Array() {
        for (int i = 0; i < MAXSIZE; i++)
            array[i] = 0;
    }

    T& operator[](int index);


    void Sort();

private:
    T array[MAXSIZE];
};

// 重载运算符[]
template <class T> T& Array<T>::operator[](int index) {
    if (index < 0 || index >= MAXSIZE) { // 如果下标越界
        cout << "Index out of bounds" << endl;
        exit(0);
    }

    return array[index];
}

// 从大到小排序
template <class T> void Array<T>::Sort() {
    int p, j;
    for (int i = 0; i < MAXSIZE; i++) {
        p = i;
        for (j = i + 1; j < MAXSIZE; j++) {
            if (array[p] < array[j])
                p = j;
        }

        T tmp = array[i];
        array[i] = array[p];
        array[p] = tmp;
    }
}

// 从小到大排序
template <> void Array<char*>::Sort() {
    int p, j;
    for (int i = 0; i < MAXSIZE - 1; i++) {
        p = i;
        for (j = i + 1; j < MAXSIZE; j++) {
            if (strcmp(array[p], array[j]) > 0)
                p = j;
        }

        char* tmp = array[i];
        array[i] = array[p];
        array[p] = tmp;
    }
}

int main() {
    Array<int> a;
    Array<char*> b;

    a[0] = 1, a[1] = 23, a[2] = 31, a[3] = 14, a[4] = 25;
    a.Sort();

    for (int i = 0; i < MAXSIZE; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    b[0] = "Hello", b[1] = "World", b[2] = "C++", b[3] = "Things", b[4] = "Array";
    b.Sort();

    for (int i = 0; i < MAXSIZE; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}