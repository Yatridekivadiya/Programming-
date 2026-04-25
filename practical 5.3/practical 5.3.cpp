#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void addItem() {
    ofstream file("inventory.txt", ios::app);

    string name;
    int quantity;
    float price;

    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter price: ";
    cin >> price;

    file << name << "," << quantity << "," << price << endl;

    file.close();
    cout << "Item added successfully!\n";
}

void viewItems() {
    ifstream file("inventory.txt");

    string line;

    cout << "\n--- Inventory Items ---\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}


void searchItem() {
    ifstream file("inventory.txt");

    string searchName;
    cout << "Enter item name to search: ";
    cin.ignore();
    getline(cin, searchName);

    string line;
    bool found = false;

    while (getline(file, line)) {
        string name;
        int quantity;
        float price;

        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1 + 1);

        name = line.substr(0, pos1);
        quantity = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        price = stof(line.substr(pos2 + 1));

        if (name == searchName) {
            cout << "\nItem Found:\n";
            cout << "Name: " << name << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: " << price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found!\n";
    }

    file.close();
}


int main() {
    int choice;

    do {
        cout << "\n===== Inventory System =====\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
