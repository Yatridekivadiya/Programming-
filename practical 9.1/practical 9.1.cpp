#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    cout << "\nOriginal Vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\n\nAfter std::reverse(): ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }

    vector<int> v2 = v;

    auto start = v2.begin();
    auto end = v2.end() - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "\n\nManual Iterator Reversal: ";
    for (auto it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
