#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    double balance;
    string log[100];
    int index;

public:
    BankAccount(double b = 0) {
        balance = b;
        index = 0;
        log[index++] = "Account created";
    }

    void addLog(string msg) {
        log[index++] = msg;
    }

    void deposit(double amount) {
        addLog("Entered deposit()");

        if (amount <= 0) {
            addLog("Invalid deposit attempt");
            throw "Deposit amount must be greater than 0";
        }

        balance += amount;
        addLog("Deposit successful");
        cout << "Deposited: " << amount << endl;

        addLog("Exiting deposit()");
    }

    void withdraw(double amount) {
        addLog("Entered withdraw()");

        if (amount <= 0) {
            addLog("Invalid withdraw attempt");
            throw "Withdrawal amount must be greater than 0";
        }

        if (amount > balance) {
            addLog("Insufficient balance error");
            throw "Insufficient balance!";
        }

        balance -= amount;
        addLog("Withdraw successful");
        cout << "Withdrawn: " << amount << endl;

        addLog("Exiting withdraw()");
    }

    void showBalance() {
        cout << "Balance: " << balance << endl;
    }

    void showLogs() {
        cout << "\n--- Transaction Logs (Stack Unwinding Simulation) ---\n";
        for (int i = 0; i < index; i++) {
            cout << log[i] << endl;
        }
    }
};

int main() {

    BankAccount acc(1000);

    try {
        acc.deposit(500);
        acc.withdraw(200);
        acc.withdraw(2000);
    }
    catch (const char* msg) {
        cout << "\nException Caught: " << msg << endl;
    }

    acc.showBalance();
    acc.showLogs();

    return 0;
}
