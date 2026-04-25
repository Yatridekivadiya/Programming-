#include<iostream>
#include<string.h>
using namespace std;

class library
{
private :
    int book_id;
    char title[50];
    char author[50];
    int copies;

public :
    void addbook()
    {
        cout << "Enter book id : ";
        cin >> book_id;
        cout << "Enter book title : ";
        cin >> title;
        cout << "Enter author name : ";
        cin >> author;
        cout << "Enter the number of copies : ";
        cin >> copies;
    }

    int getId()
    {
        return book_id;
    }

    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "\nBook issued successfully!";
        }
        else
        {
            cout << "\nBook not available!";
        }
    }

    void returnBook()
    {
        copies++;
        cout << "\nBook return successful!";
    }

    void display()
    {
        cout << "\nId : " << book_id;
        cout << "\nTitle : " << title;
        cout << "\nAuthor : " << author;
        cout << "\nCopies : " << copies << endl;
    }
};

int main()
{
    library book[20];
    int choice,n=0,id,i;

    do
    {
        cout<<"\n===================";
        cout<<"\nMenu :";
        cout<<"\n===================";
        cout<<"\n1. add new book";
        cout<<"\n2. issue new book";
        cout<<"\n3. Return issued book";
        cout<<"\n4. displaying total books in the library";
        cout<<"\n5. exit";

        cout<<"\n   ";

        cout<<"\nEnter your choice :";
        cin>>choice;

        cout<<"    \n";

        switch(choice)
        {
        case 1:
            book[n].addbook();
            n++;
            break;

        case 2:
            cout<<"Enter book id to issue book : ";
            cin>>id;
            for(i=0;i<n;i++)
            {
                if(book[i].getId()==id)
                {
                    book[i].issueBook();
                }
            }
            break;

        case 3:
            cout<<"Enter book id to return the book :";
            cin>>id;
            for(i=0;i<n;i++)
            {
                if(book[i].getId()==id)
                {
                    book[i].returnBook();
                }
            }
            break;

        case 4:
            for(i=0;i<n;i++)
            {
                book[i].display();
            }
            break;

        case 5:
            cout<<"\nExiting..";
            break;

        default :
            cout<<"\nEnter valid choice";
        }
    }
    while(choice!=5);
    cout<<"this program is developed by yatri dekivadiya - 25CE021";
    return 0;
}

