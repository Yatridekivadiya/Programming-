#include <iostream>
using namespace std;


class Person {
protected:
    string name;
    int age;

public:
    Person() {}

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


class Employee : public Person {
protected:
    int empID;

public:
    Employee() {}

    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }

    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
    }

    int getID() {
        return empID;
    }
};

class Manager : public Employee {
    string department;

public:
    Manager() {}

    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id) {
        department = dept;
    }

    void displayManager() {
        displayPerson();
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "------------------------\n";
    }
};

int main() {
    int n;

    cout << "Enter number of managers: ";
    cin >> n;

    Manager m[100];

    for (int i = 0; i < n; i++) {
        string name, dept;
        int age, id;

        cout << "\nEnter details of Manager " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Employee ID: ";
        cin >> id;

        cout << "Department: ";
        cin >> dept;

        m[i] = Manager(name, age, id, dept);
    }

    cout << "\n--- All Managers ---\n";
    for (int i = 0; i < n; i++) {
        m[i].displayManager();
    }

    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (m[i].getID() == searchID) {
            cout << "\nManager Found:\n";
            m[i].displayManager();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Manager not found!\n";
    }

    return 0;
}
