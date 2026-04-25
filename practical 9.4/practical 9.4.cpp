#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    while (true) {
        cout << "\n--- Directory System ---\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter folder name: ";
            cin >> folder;

            directory[folder];

            cout << "Folder added.\n";
        }

        else if (choice == 2) {
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) != directory.end()) {
                cout << "Enter file name: ";
                cin >> file;

                directory[folder].push_back(file);
                cout << "File added.\n";
            }
            else {
                cout << "Folder not found!\n";
            }
        }

        else if (choice == 3) {
            cout << "\n--- Directory Contents ---\n";

            for (auto it = directory.begin(); it != directory.end(); it++) {
                cout << "Folder: " << it->first << endl;

                vector<string> files = it->second;

                if (files.empty()) {
                    cout << "  (No files)\n";
                } else {
                    for (int i = 0; i < files.size(); i++) {
                        cout << "  - " << files[i] << endl;
                    }
                }
            }
        }

        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
