#include<stdio.h>
#include<string.h>
struct library
{
    int book_id;
    char title[50];
    char author[50];
    int copies;
};

int main()
{
    struct library book[20];
    int choice,n=0,id,i;

    do
    {
        printf("\n===================");
        printf("\nMenu :");
        printf("\n===================");
        printf("\n1. add new book");
        printf("\n2. issue new book");
        printf("\n3. Return issued book");
        printf("\n4. displaying total books in the library");
        printf("\n5. exit");

        printf("\n   ");

        printf("\nEnter your choice :");
        scanf("%d",&choice);

        printf("    \n");

        switch(choice)
        {
        case 1:
            printf("Enter book id :");
            scanf("%d",&book[n].book_id);
            printf("Enter book title :");
            scanf("%s",book[n].title);
            printf("Enter author name :");
            scanf("%s",book[n].author);
            printf("Enter the number of copies :");
            scanf("%d",&book[n].copies);
            n++;
            break;

        case 2:
            printf("Enter book id to issue book : ");
            scanf("%d",&id);
            for(i=0;i<n;i++)
            {
                if(book[i].book_id==id)
                {
                    if(book[i].copies>0)
                    {
                        book[i].copies--;
                        printf("\nbook issued successfully !");
                    }
                    else
                    {
                        printf("\nbook not available !");
                    }
                }
            }
            break;

        case 3:
            printf("Enter book id to return the book :");
            scanf("%d",&id);
            for(i=0;i<n;i++)
            {
                if(book[i].book_id==id)
                {
                    book[i].copies++;
                    printf("\nBook return successfull ! ");
                }
            }
            break;

        case 4:
            for(i=0;i<n;i++)
            {
                printf("\nid : %d",book[i].book_id);
                printf("\ntitle : %s",book[i].title);
                printf("\nAuthor name : %s",book[i].author);
                printf("\ncopies : %d",book[i].copies);
            }
            break;

        case 5:
            printf("\nExiting..");
            break;

        default :
            printf("\nEnter valid choice");
        }
    }
    while(choice!=5);
    return 0;
}
