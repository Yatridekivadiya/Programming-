#include <iostream>
using namespace std;

int main() {

    int a, b;

    try {
        cout << "Enter numerator: ";
        cin >> a;

        if (cin.fail()) {
            throw "Invalid input! Please enter integers only.";
        }

        cout << "Enter denominator: ";
        cin >> b;

        if (cin.fail()) {
            throw "Invalid input! Please enter integers only.";
        }

        if (b == 0) {
            throw "Division by zero error!";
        }

        cout << "Result: " << (a / b) << endl;
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}
