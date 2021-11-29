#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T compareMax(T a, T b) {
    return a > b ? a : b;
}

template <>
const char* compareMax(const char* a, const char* b) {
    cout << "[for debug]" << " call compareMax template" << endl;
    return strcmp(a, b) > 0 ? a : b; // 根据字符串的大小比较（相同则根据字典序）
}

int main() {
    cout << compareMax(1, 2) << endl;
    cout << compareMax("asda", "awqe") << endl;

    system("pause");

    return 0;
}