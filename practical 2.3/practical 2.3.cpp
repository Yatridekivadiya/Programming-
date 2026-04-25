#include<iostream>
using namespace std;

class savingaccount
{
private :
    string name;
    int account_id;
    double balance;

public :
    savingaccount()
    {
        name = "NA";
        account_id = 0;
        balance = 0;
    }

    savingaccount(string n, int id, double bal=0)
    {
        name = n;
        account_id = id;
        balance = bal;
    }

    void deposite(double amount)
    {
        if(amount>0)
        {
            balance += amount;
            cout<<"Amount deposite successfully ";
        }
        else
        {
            cout<<"Invalid amount ! ";
        }
    }

    void withdraw(double amount)
    {
        if(amount<0 || amount>balance)
        {
            cout<<"Invalid amount !";
        }
        else
        {
            balance -= amount;
            cout<<"Amount withdraw successfully ";
        }
    }

    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Account id : "<<account_id<<endl;
        cout<<"balance : "<<balance<<endl;
    }
};

int main()
{
    int n,i,choice;
    string name;
    int id;
    double bal;

    savingaccount a[20];

    cout<<"Enter number of accounts : ";
    cin>>n;


    for(i=0;i<n;i++)
    {
        cout<<"Enter details for account "<<i+1<<" : "<<endl;
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter account id : ";
        cin>>id;
        cout<<"enter balance : ";
        cin>>bal;

        a[i]= savingaccount(name, id, bal);
    }
        int  index;
        double amt;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            cout << "Enter account index (1 to " << n << "): ";
            cin >> index;

            if (index < 0 || index >= n)
            {
                cout << "Invalid account index!\n";
                continue;
            }
        }

        switch (choice)
        {
        case 1:
            cout << "Enter deposite amount: ";
            cin >> amt;
            a[index].deposite(amt);
            break;

            case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amt;
            a[index].withdraw(amt);
            break;

        case 3:
            a[index].display();
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
