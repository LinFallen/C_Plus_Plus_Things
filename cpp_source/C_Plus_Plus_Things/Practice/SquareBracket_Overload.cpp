#include <iostream>
#include <cstring>

using namespace std;

struct Person { // 职工基本信息的结构体
    double salary;
    char* name;
};

class SalaryMange {
    Person* employ; // 职工基本信息的指针数组
    int max; // 职工基本信息的数组的最大长度
    int n; // 职工基本信息数组中的实际职工人数

public:
    SalaryMange(int Max = 0) {
        max = Max;
        n = 0;
        employ =  new Person[max];
    }

    // 返回引用特性是可以直接在放在左值，直接使用
    double& operator[](const char *Name) { // 重载[]运算符，返回引用（添加const以便char*与string转换）
        Person* p;
        for (p = employ; p < employ + n; p++) {
            if (strcmp(p->name, Name) == 0) {  // 如果找到了，则返回该职工的工资
                return p->salary;
            }
        }

        // 不存在的情况处理
        p = employ + n++;
        p->name = new char[strlen(Name) + 1];
        strcpy(p->name, Name);
        p->salary = 0;

        return p->salary;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << employ[i].name << ": " << employ[i].salary << endl;
        }
    }

    ~SalaryMange() {
        delete employ;
    }
};

int main() {
    SalaryMange s(3);
    s["Tom"] = 2188.88;
    s["Jack"] = 1230.07;
    s["Mary"] = 3100.29;

    cout << s["Tom"] << endl;
    cout << s["Jack"] << endl;
    cout << s["Mary"] << endl;

    cout << "--------This is display output------" << endl;

    s.display();

    cin.get();

    return 0;
}