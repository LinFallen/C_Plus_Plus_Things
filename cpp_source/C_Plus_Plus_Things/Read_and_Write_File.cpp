#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class Person {
public:
    Person() {}
    Person(string name, string id, int math, int chinese, int english) {
        name_ = name;
        id_ = id;
        math_ = math;
        chinese_ = chinese;
        english_ = english;
        sum_ = math + chinese + english;
    }

    void Display() {
        cout << "Name: " << name_ << endl;
        cout << "ID: " << id_ << endl;
        cout << "Math: " << math_ << endl;
        cout << "Chinese: " << chinese_ << endl;
        cout << "English: " << english_ << endl;
        cout << "Sum: " << sum_ << endl;
    }

private:
    string name_;
    string id_;
    int math_;
    int chinese_;
    int english_;
    int sum_;
};

int main() {
    string op;
    string name, id;
    int math, chinese, english;
    
    fstream file; // file stream: read and write
    file.open("cpp_source\\C_Plus_Plus_Things\\doc\\person.txt", ios::out | ios::app); // attention the path format

    // test the file is open or not
    if (!file.is_open()) {
        cout << "Open file failed!" << endl;
        return -1;
    }

    cout << "-----------Establish Students Files----------" << endl;

    do {
        cout << "Please input name: ";
        cin >> name;

        cout << "Please input id: ";
        cin >> id;

        cout << "Please input Math score : ";
        cin >> math;

        cout << "Please input Chinese score: ";
        cin >> chinese;

        cout << "Please input English score: ";
        cin >> english;

        Person person(name, id, math, chinese, english);

        file.write((char*)&person, sizeof(person));

        cout << "Do you want to continue? (y/n) ";
        cin >> op;
    } while (op == "y" || op == "Y");

    file.close(); // remember to close the file

    // read data from file
    file.open("cpp_source\\C_Plus_Plus_Things\\doc\\person.txt", ios::in);
    
    Person student;
    file.read((char*)&student, sizeof(student)); // read the first data

    vector<Person> students;
    while (!file.eof()) { // read the rest data
        students.push_back(student);
        file.read((char*)&student, sizeof(student));
    }

    file.close(); // remember to close the file

    cout << "-----------Display Students Files----------" << endl;

    for (auto student_iter : students) { // iterate the vector
        student_iter.Display();
    }

    system("pause");

    return 0;
}