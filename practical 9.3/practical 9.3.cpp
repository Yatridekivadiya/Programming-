#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {

    set<int> s;
    vector<int> v;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << "\nUnique Elements (using set iterator): ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        v.push_back(*it);
    }

    cout << "\n\nUnique Elements (in vector): ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}
