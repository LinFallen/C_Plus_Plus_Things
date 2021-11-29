/*
有一个类Circle，设计该类的类型转换函数，当将Circle对象转换成int型时，返回圆的半径；当将它转换成double型时，就返回圆的周长；当将它转换成float型时，就返回圆的面积。
*/

/*
类型转换函数没有参数。
类型转换函数没有返回类型。
类型转换函数必须返回将要转换成的type类型数据。
*/

#include <iostream>

using namespace std;;

class Circle {
    double r;
public:
    Circle(double r) {
        this->r = r;
    }

    operator int() {
        return int(r);
    }

    operator double() {
        return 2 * 3.14 * r;
    }

    operator float() {
        return (float)3.14 * r * r;
    }
};

int main() {
    Circle c(25.6);
    int r = c; // call operator int(), convert Circle to int
    double length = c; // call operator double(), convert Circle to double
    float area = c; // call operator float(), convert Circle to float
    double len = (double)c; // convert Circle to double forcedly

    cout << r << endl;
    cout << length << endl;
    cout << len << endl;
    cout << area << endl;

    system("pause");

    return 0;
}