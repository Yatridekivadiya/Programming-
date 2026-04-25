#include <iostream>
#include <vector>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    float add(int a, float b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    vector<float> results;


    results.push_back(calc.add(2, 3));
    results.push_back(calc.add(2.5f, 3.5f));
    results.push_back(calc.add(5, 2.5f));
    results.push_back(calc.add(1, 2, 3));

    cout << "Results:\n";
    for (int i = 0; i < results.size(); i++) {
        cout << "Result " << i + 1 << ": " << results[i] << endl;
    }

    return 0;
}
