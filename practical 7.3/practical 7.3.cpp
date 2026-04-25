#include <iostream>
#include <vector>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    operator Fahrenheit();

    void display() {
        cout << temp << " °C" << endl;
    }
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    void display() {
        cout << temp << " °F" << endl;
    }

    bool operator == (Fahrenheit f) {
        return temp == f.temp;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}


int main() {

    Celsius c1(25);
    Fahrenheit f1 = c1;

    Fahrenheit f2(77);
    Celsius c2 = f2;

    cout << "Conversions:\n";
    c1.display();
    cout << "-> ";
    f1.display();

    f2.display();
    cout << "-> ";
    c2.display();


    Fahrenheit a(100), b(100);
    if (a == b)
        cout << "\nTemperatures are equal\n";
    else
        cout << "\nNot equal\n";


    vector<Fahrenheit> queue;
    queue.push_back(Fahrenheit(32));
    queue.push_back(Fahrenheit(68));
    queue.push_back(Fahrenheit(86));

    cout << "\nQueue (FIFO):\n";
    for (int i = 0; i < queue.size(); i++) {
        queue[i].display();
    }

    Fahrenheit arr[3] = { Fahrenheit(50), Fahrenheit(60), Fahrenheit(70) };

    cout << "\nArray Storage:\n";
    for (int i = 0; i < 3; i++) {
        arr[i].display();
    }

    return 0;
}
