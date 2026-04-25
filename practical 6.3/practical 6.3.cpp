#include <iostream>
#include <vector>
using namespace std;


class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        fuelType = f;
    }
};


class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }
};

class Car : public Fuel, public Brand {
public:

    Car(string f, string b) : Fuel(f), Brand(b) {}


    void display() {
        cout << "Brand: " << brandName << ", Fuel: " << fuelType << endl;
    }
};


void processCarsVector() {
    cout << "\nUsing Vector (Structured Method):\n";

    vector<Car> cars = {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Hyundai"),
        Car("Electric", "Tesla")
    };

    for (int i = 0; i < cars.size(); i++) {
        cars[i].display();
    }
}


void processCarsDirect() {
    cout << "\nUsing Direct Method:\n";

    Car c1("Petrol", "Toyota");
    Car c2("Diesel", "Hyundai");
    Car c3("Electric", "Tesla");

    c1.display();
    c2.display();
    c3.display();
}

int main() {
    processCarsVector();
    processCarsDirect();

    return 0;
}
