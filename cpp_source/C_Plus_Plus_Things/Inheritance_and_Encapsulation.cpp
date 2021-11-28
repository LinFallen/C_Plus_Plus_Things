#include <iostream>
#include <cstring>

using namespace std;

class Employee {
public:
    Employee(const char* name, const char* id) {
        strcpy(name_, name);
        strcpy(id_, id);
    }

    char* GetName() {
        return name_;
    }

    char* GetId() {
        return id_;
    }

    void Display() {
        cout << "Name: " << name_ << endl;
        cout << "ID: " << id_ << endl;
    }

private:
    char name_[20];
    char id_[20];
};

class Manager : public Employee {
public:
    Manager(const char* name, const char* id, int week) : Employee(name, id) {
        week_salary_= week * 1000;
    }

    void Display() {
        cout << "Manager: " << GetName() << "\t" << GetId() << "\t" << week_salary_ << endl;
    }

private:
    int week_salary_ = 0;    
};

class SaleWorker : public Employee {
public:
    SaleWorker(const char* name, const char* id, int profit, int sale_number) : Employee(name, id) {
        worker_money_ = base_money_ + sale_number * 0.05 * profit;
    }

    void Display() {
        cout << "SaleWorker: " << GetName() << "\t" << GetId() << "\t" << worker_money_ << endl;
    }

private:
    float base_money_ = 800.0;
    float worker_money_ = 0.0;
};

class HourWorker : public Employee {
public:
    HourWorker(const char* name, const char* id, int hour) : Employee(name, id) {
        total_money_ = hour * hour_money_;
    }

    void Display() {
        cout << "HourWorker: " << GetName() << "\t" << GetId() << "\t" << total_money_ << endl;
    }

private:
    float hour_money_ = 100.0;
    float total_money_ = 0.0;
};

int main() {
    cout << "Please input week: ";
    int week;
    cin >> week;

    Manager manager("Tom", "001", week);
    manager.Display();

    cout << "Please input profit: ";
    int profit;
    cin >> profit;

    cout << "Please input sale numbers: ";
    int sale_number;
    cin >> sale_number;

    SaleWorker sale_worker("Jerry", "002", profit, sale_number);
    sale_worker.Display();

    cout << "Please input hour: ";
    int hour;
    cin >> hour;

    HourWorker hour_worker("Jack", "003", hour);
    hour_worker.Display();

    system("pause");

    return 0;
}
