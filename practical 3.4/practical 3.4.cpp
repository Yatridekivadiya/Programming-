#include<iostream>
using namespace std;

template <class T>
T findMax(T arr[] , int n)
{
    T max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <class T>
void reverseArray(T arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

template <class T>
void display(T arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

template <class T>
void leaders(T arr[], int n)
{
    T max_right = arr[n-1];
    cout<<"Leaders : "<<max_right<<" ";

    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]>max_right)
        {
            max_right = arr[i];
            cout<<max_right<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int n,i;
    int arr1[100];
    float arr2[100];
    char arr3[100];

    cout<<"Enter the number of int array : ";
    cin>>n;

    cout<<"enter elements : ";
    for(i=0; i<n; i++)
    {
        cin>>arr1[i];
    }

    cout<<"Integer Array : "<<endl;
    display(arr1 , n);
    cout<<"\nMax : "<<findMax(arr1, n)<<endl;
    reverseArray(arr1 , n);
    cout<<"Reverse array : ";
    display(arr1 , n);
    cout<<endl;
    leaders(arr1, n);

    cout<<"Enter the number of float array : ";
    cin>>n;

    cout<<"Enter elements : ";
    for(i=0;i<n;i++)
    {
        cin>>arr2[i];
    }

    cout<<"Float Array : "<<endl;
    display(arr2 , n);
    cout<<"\nMax : "<<findMax(arr2, n)<<endl;
    reverseArray(arr2, n);
    cout<<"Reverse : ";
    display(arr2, n);
    cout<<endl;
    leaders(arr2 , n);

    cout<<"enter the number of character array : ";
    cin>>n;

    cout<<"Enter elements : ";
    for(i=0;i<n;i++)
    {
        cin>>arr3[i];
    }

    cout<<"character Array : "<<endl;
    display(arr3 , n);
    cout<<"\nMax : "<<findMax(arr3, n)<<endl;
    reverseArray(arr3, n);
    cout<<"Reverse : ";
    display(arr3, n);
    cout<<endl;
    leaders(arr3 , n);
}

