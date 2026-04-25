#include<iostream>
using namespace std;

class rectangle
{
private :
    float length;
    float breadth;
    float perimeter;
    float area;

public :
    void getdata()
    {
        cout<<"Enter length : ";
        cin>>length;
        cout<<"Enter breadth : ";
        cin>>breadth;
    }

    void calculatePerimeter()
    {
        perimeter=2*(length + breadth);
    }

    void calculateArea()
    {
        area=length*breadth;
    }

    void displaydata()
    {
        calculatePerimeter();
        calculateArea();

        cout<<"=================\n";
        cout<<"length is : "<<length;
        cout<<"\nBreadth is : "<<breadth;
        cout<<"\nPerimeter of rectangle :"<<perimeter;
        cout<<"\nArea of rectangle : "<<area;
        cout<<"\n=================\n";
    }
};

int main()
{
    rectangle r[20];
    int n,i;

    cout<<"Enter the number : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter length and breadth for rectangle "<<i+1<<endl;
        r[i].getdata();
        r[i].displaydata();
    }
    cout<<"\nThis program is developed by yatri dekivadiya - 25CE021";
}
