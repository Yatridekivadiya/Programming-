#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    string filename;
    ifstream file;

    while (true) {
        cout << "Enter file name/path: ";
        cin >> filename;

        file.open(filename);

        if (!file) {
            cout << "Error: File not found! Try again.\n";
        } else {
            cout << "File opened successfully!\n\n";
            break;
        }
    }

    string line;
    int lineNo = 0;

    while (getline(file, line)) {
        lineNo++;

        stringstream ss(line);
        double num, sum = 0;
        int count = 0;
        bool valid = true;

        cout << "Processing Line " << lineNo << ": " << line << endl;


        while (ss >> num) {
            sum += num;
            count++;
        }


        if (count == 0) {
            cout << "Corrupted data (no valid numbers). Skipping line.\n\n";
            continue;
        }


        for (char c : line) {
            if ((c < '0' || c > '9') && c != ' ' && c != '.' && c != '-') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "Warning: Line may contain corrupted/non-numeric data.\n";
        }


        cout << "Sum = " << sum << endl;
        cout << "Average = " << sum / count << "\n\n";
    }

    file.close();

    cout << "File processing completed.\n";

    return 0;
}
