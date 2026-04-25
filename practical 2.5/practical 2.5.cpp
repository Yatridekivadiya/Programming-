#include<iostream>
#include<math.h>
using namespace std;

class loan
{
private :
    int id;
    string name;
    double amount;
    float annual_interest_rate;
    int months;
    float emi;
    double monthly_rate;

public :
    loan()
    {
        id = 1;
        name = "ABC";
        amount = 50000;
        annual_interest_rate = 10;
        months = 12;
        calculateEMI();
    }

    loan(int ID, string N, double amt, float rate, int M)
    {
        id = ID;
        name = N;
        amount = amt;
        annual_interest_rate = rate;
        months = M;
        calculateEMI();
    }

    void calculateEMI()
    {
        monthly_rate = annual_interest_rate/(12*100);

        emi = (amount * monthly_rate * pow(1 + monthly_rate, months))/(pow(1 + monthly_rate, months) - 1);
    }

    void display()
    {
        cout<<"------------------------"<<endl;
        cout<<"loan id : "<<id<<endl;
        cout<<"application name : "<<name<<endl;
        cout<<"total loan amount : "<<amount<<endl;
        cout<<"Annual interest rate : "<<annual_interest_rate<<endl;
        cout<<"months : "<<months<<endl;
        cout<<"emi : "<<emi<<endl;
        cout<<"------------------------"<<endl;
    }
};

int main()
{
    loan l1;
    cout<<"Default loan details : "<<endl;
    l1.display();

    loan l2(21, "yatri", 500000, 8.5, 60);
    cout<<"parameterized loan details : "<<endl;
    l2.display();
}
