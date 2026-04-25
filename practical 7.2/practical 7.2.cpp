#include <iostream>
#include <vector>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (Complex const &obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
    Complex operator - (Complex const &obj) {
        Complex temp;
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {

    Complex c1(5, 3);
    Complex c2(2, 4);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "First Complex: ";
    c1.display();

    cout << "Second Complex: ";
    c2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    return 0;
}
