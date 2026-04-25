#include<iostream>
using namespace std;

class student
{
private :
    int roll_no;
    string name;
    float marks[3];
    float total=0;
    float avg;
    float average;
    int i;

public :
    student()
    {
       roll_no = 1;
       name = "yatri";
       marks[0] = 0;
       marks[1] = 0;
       marks[2] = 0;
       avg = 0;
    }

    void getdata()
    {
        cout<<"Enter roll no. : ";
        cin>>roll_no;
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter marks of subjects 1 : ";
        cin>>marks[0];
        cout<<"Enter marks of subjects 2 : ";
        cin>>marks[1];
        cout<<"Enter marks of subjects 3 : ";
        cin>>marks[2];
    }

    float calculateAverage()
    {
            total = marks[0] + marks[1] + marks[2];

        average = total/3.0;
        return average;
    }

    void display()
    {
        cout << "Roll number: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Average mark: " << avg << endl;
    }
};

int main()
{
    student s[100],s1;

    int n,i;
    float avg;
    float average;

    cout<<"Average for default values : "<<endl;
    s1.display();

    cout<<"Enter the number of students : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        s[i].getdata();
        s[i].calculateAverage();
        cout<<"Average : "<<s[i].calculateAverage()<<endl;
    }
}
