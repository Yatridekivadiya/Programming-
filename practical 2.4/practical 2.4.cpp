#include<iostream>
using namespace std;

class store
{
private :
    int ID;
    string name;
    float price;
    int quantity;

public :

    store()
    {
        name = "NA";
        ID = 0;
        price = 0;
        quantity = 0;
    }

    store(string n, int id, float p, int qua)
    {
        name = n;
        ID = id;
        price = p;
        quantity = qua;
    }

    void additem(int qua)
    {
        if(qua > 0)
        {
            quantity += qua;
            cout<<"Item added successfully ";
        }
        else
        {
            cout<<"invalid number !";
        }
    }

    void sellitem(int qua)
    {
        if(qua > 0)
        {
            quantity -= qua;
            cout<<"Item sell successfully ";
        }
        else
        {
            cout<<"Invalid number !";
        }
    }

    void display()
    {
        cout<<"----Item details---";
        cout<<"Name : "<<name<<endl;
        cout<<"ID : "<<ID<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"quantity : "<<quantity<<endl;
    }
};

int main()
{
    store item[20];

    int n,i,id,qua,choice,index,amt;
    string name;
    float price;

    cout<<"Enter number of items : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Enter name : "<<endl;
        cin>>name;
        cout<<"enter id : "<<endl;
        cin>>id;
        cout<<"enter price : "<<endl;
        cin>>price;
        cout<<"enter quantity of items : "<<endl;
        cin>>qua;

        item[i]=store(name, id, price, qua);
    }

    do
    {
        cout<<"Menu : ";
        cout<<"1. add item"<<endl;
        cout<<"2. sell item"<<endl;
        cout<<"3. display item "<<endl;
        cout<<"4. exit"<<endl;

        cout<<"enter choice : ";
        cin>>choice;

        if(choice>=1 && choice<=3)
        {
            cout<<"Enter item index ( 1 to "<<n<<" ) : ";
            cin>>index;


        if(index < 0 || index > n)
        {
            cout<<"Invalid index !";
        }
        }

        switch(choice)
        {
        case 1:
            cout<<"Enter quantity to add : ";
            cin>>amt;
            item[index].additem(amt);
            break;

        case 2:
            cout<<"Enter quantity to sell : ";
            cin>>amt;
            item[index].sellitem(amt);
            break;

        case 3:
            item[index].display();
            break;

        case 4:
            cout<<"Exiting...";
            break;

        default :
            cout<<"Invalid choice !";
        }
    }
    while(choice != 4);
}
