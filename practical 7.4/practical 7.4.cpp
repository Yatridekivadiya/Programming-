#include <iostream>
#include <vector>
using namespace std;


class Shape {
public:
    virtual float area() {
        return 0;
    }

    virtual void display() {
        cout << "Shape Area: " << area() << endl;
    }

    virtual ~Shape() {}
};

class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float area() override {
        return length * width;
    }
};


class Circle : public Shape {
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() override {
        return 3.14 * radius * radius;
    }
};

int main() {

    cout << "Polymorphism with Dynamic Storage (vector):\n";


    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(10, 5));
    shapes.push_back(new Circle(7));
    shapes.push_back(new Rectangle(4, 6));

    for (int i = 0; i < shapes.size(); i++) {
        cout << "Area: " << shapes[i]->area() << endl;
    }


    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }

    cout << "\nStatic Storage (Array):\n";

    Shape* arr[3];

    arr[0] = new Rectangle(3, 4);
    arr[1] = new Circle(5);
    arr[2] = new Rectangle(6, 2);

    for (int i = 0; i < 3; i++) {
        cout << "Area: " << arr[i]->area() << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}
