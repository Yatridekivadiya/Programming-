#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {
public:
    string message;

    NegativeNumberException(string msg) {
        message = msg;
    }

    void showError() {
        cout << "Exception: " << message << endl;
    }
};

int main() {

    float num;

    cout << "Enter a number: ";
    cin >> num;

    try {

        if (num < 0) {
            throw NegativeNumberException("Negative number not allowed!");
        }

        cout << "Square root: " << sqrt(num) << endl;
    }
    catch (NegativeNumberException e) {
        e.showError();
    }

    return 0;
}
