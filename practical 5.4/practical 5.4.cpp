#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& os) {
    os << "Rs.";
    return os;
}

int main() {
    string names[] = {"A", "B", "C"};
    int marks[] = {85, 92, 78};
    float fees[] = {12345.5, 15000.75, 11000.0};

    int n = 3;

    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');
    cout << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(25) << "Fees" << endl;
    cout << setfill(' ') << setw(50) << "" << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(15) << names[i]
             << setw(10) << marks[i]
             << setw(10) << currency
             << setw(15) << fixed << setprecision(2) << fees[i]
             << endl;
    }

    cout << setfill('=') << setw(50) << "" << endl;

    return 0;
}
