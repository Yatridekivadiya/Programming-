#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }

    float getRadius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    float area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    cout << "\n--- Using Static Array ---\n";
    Circle staticCircles[100];

    for (int i = 0; i < n; i++) {
        float r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;

        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area = "
             << staticCircles[i].area() << endl;
    }

    cout << "\n--- Using Dynamic Vector ---\n";
    vector<Circle> dynamicCircles;

    for (int i = 0; i < n; i++) {
        Circle c;
        float r;

        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;

        c.setRadius(r);
        dynamicCircles.push_back(c);
    }

    cout << "\nAreas (Dynamic):\n";
    for (int i = 0; i < dynamicCircles.size(); i++) {
        cout << "Circle " << i + 1 << " Area = "
             << dynamicCircles[i].area() << endl;
    }

    return 0;
}
