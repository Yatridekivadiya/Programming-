#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;
    vector<double> history;

public:
    Account(int a, double b) {
        accNo = a;
        balance = b;
    }

    void deposit(double amt) {
        balance += amt;
        history.push_back(amt);
        cout << "Deposited: " << amt << endl;
    }

    virtual void withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            history.push_back(-amt);
            cout << "Withdrawn: " << amt << endl;
        } else {
            cout << "Insufficient balance!\n";
        }
    }


    void undo() {
        if (!history.empty()) {
            double last = history.back();
            balance -= last;
            history.pop_back();
            cout << "Last transaction undone!\n";
        } else {
            cout << "No transaction to undo!\n";
        }
    }

    void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }

    ~Account() {
        cout << "Account closed.\n";
    }
};


class Savings : public Account {
    double interestRate;

public:
    Savings(int a, double b, double r) : Account(a, b) {
        interestRate = r;
    }

    void display() {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};


class Current : public Account {
    double overdraft;

public:
    Current(int a, double b, double o) : Account(a, b) {
        overdraft = o;
    }


    void withdraw(double amt) {
        if (amt <= balance + overdraft) {
            balance -= amt;
            history.push_back(-amt);
            cout << "Withdrawn: " << amt << endl;
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void display() {
        Account::display();
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main() {
    Savings s(101, 1000, 5);
    s.deposit(500);
    s.withdraw(200);
    s.undo();
    s.display();

    cout << "\n";

    Current c(102, 1000, 500);
    c.deposit(300);
    c.withdraw(1400);
    c.undo();
    c.display();

    return 0;
}
