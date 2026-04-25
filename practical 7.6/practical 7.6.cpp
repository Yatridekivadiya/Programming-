#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() {
        cout << "Base1 Constructor\n";
    }

    ~Base1() {
        cout << "Base1 Destructor\n";
    }
};

class Derived1 : public Base1 {
    int* data;

public:
    Derived1() {
        data = new int(10);
        cout << "Derived1 Constructor (memory allocated)\n";
    }

    ~Derived1() {
        cout << "Derived1 Destructor (memory freed)\n";
        delete data;
    }
};

class Base2 {
public:
    Base2() {
        cout << "Base2 Constructor\n";
    }

    virtual ~Base2() {
        cout << "Base2 Destructor\n";
    }
};

class Derived2 : public Base2 {
    int* data;

public:
    Derived2() {
        data = new int(20);
        cout << "Derived2 Constructor (memory allocated)\n";
    }

    ~Derived2() {
        cout << "Derived2 Destructor (memory freed)\n";
        delete data;
    }
};


int main() {

    cout << "\n--- CASE 1: WITHOUT VIRTUAL DESTRUCTOR ---\n";
    Base1* b1 = new Derived1();
    delete b1;

    cout << "\n--- CASE 2: WITH VIRTUAL DESTRUCTOR ---\n";
    Base2* b2 = new Derived2();
    delete b2;

    return 0;
}
