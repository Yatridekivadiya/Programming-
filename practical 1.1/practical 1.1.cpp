#include<iostream>
#include<string>
using namespace std;

class wallet
{
private :
    int wallet_id;
    char username[50];
    float balance=0;
    float amount;

public :
    void createwallet()
    {
        cout<<"-------------"<<endl;
        cout<<"Enter wallet id : ";
        cin>>wallet_id;
        cout<<"Enter username :";
        cin>>username;
        cout<<"-------------"<<endl;
    }

    void deposite(float amount)
    {
        if(amount>0)
        {
            balance+=amount;
            cout<<"\nAmount deposite successfully !\n";
        }
        else
        {
            cout<<"\nInvalid amount\n";
        }
    }

    void transferMoney(wallet &w, float amount)
    {
        if(amount>0 && amount<=balance)
        {
            balance-=amount;
            w.balance+=amount;
            cout<<"\nMoney transfer successfully !\n";
        }
        else
        {
            cout<<"\ninvalid amount\n";
        }
    }

    void display()
    {
        cout<<"\n-------wallet details------";
        cout<<"\nWallet id : "<<wallet_id<<endl;
        cout<<"\nUsername : "<<username<<endl;
        cout<<"\nbalance : "<<balance<<endl;
        cout<<"\n---------------------------";
    }
};

int main()
{
    wallet w1,w2;
    int choice;
    float amount;

    cout<<"create wallet 1 "<<endl;
    w1.createwallet();

    cout<<"create wallet 2 "<<endl;
    w2.createwallet();

    do
    {
        cout<<"\nmenu :"<<endl;
        cout<<"1. load money into wallet 1"<<endl;
        cout<<"2. transfer money from wallet 1 to wallet 2"<<endl;
        cout<<"3. transfer money from wallet 2 to wallet 1"<<endl;
        cout<<"4. display wallet 1"<<endl;
        cout<<"5. display wallet 2"<<endl;
        cout<<"6. exit"<<endl;

        cout<<"\nEnter choice :";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\nEnter amount you want to load :";
            cin>>amount;
            w1.deposite(amount);
            break;

        case 2:
            cout<<"\nenter amount you want to transfer :";
            cin>>amount;
            w1.transferMoney(w2,amount);
            break;

        case 3:
            cout<<"\nEnter amount you want to transfer :";
            cin>>amount;
            w2.transferMoney(w1,amount);
            break;

        case 4:
            w1.display();
            break;

        case 5:
            w2.display();
            break;

        case 6:
            cout<<"Exiting..";
            break;

        default :
            cout<<"\nInvalid choice !";
        }
    }
    while(choice!=6);
    cout<<"\nThis program is developed by yatri dekivadiya - 25CE021";
    return 0;
}

