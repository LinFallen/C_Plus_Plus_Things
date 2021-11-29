/*
 有一销售人员类Sales，其数据成员有姓名name，身份证号id，年龄age。
 重载输入/输出运算符实现对Sales类数据成员的输入和输出。
*/
#include <iostream>
#include <cstring>

using namespace std;

class Sales {
public:
    Sales(string name, string id, int age);

    friend Sales& operator >> (istream& is, Sales& s); // overload >>
    friend Sales& operator << (ostream& os, Sales& s); // overload <<

private:
    string name_;
    string id_;
    int age_;
};

Sales::Sales(string name, string id, int age) {
    name_ = name;
    id_ = id;
    age_ = age;
}

Sales& operator >> (istream& is, Sales& s) {
    cout << "Please input name, id, age: " << endl;
    is >> s.name_ >> s.id_ >> s.age_;
    return s;
}

Sales& operator << (ostream& os, Sales& s) {
    os << "name: " << s.name_ << "\t";
    os << "id: " << s.id_ << "\t";
    os << "age: " << s.age_ << endl;
    return s;
}

int main() {
    Sales sale("Zhangsan", "123456789", 20);

    cout << sale;
    cout << endl;

    cin >> sale;
    cout << sale;

    system("pause");

    return 0;
}