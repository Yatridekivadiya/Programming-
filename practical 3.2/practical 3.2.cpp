#include <iostream>
using namespace std;


float recursiveSum(float arr[], int n)
{
    if(n == 0)
        return 0;
    else
        return arr[n-1] + recursiveSum(arr, n-1);
}


float iterativeSum(float arr[], int n)
{
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    float arr[n];

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sum using Iteration: " << iterativeSum(arr, n) << endl;
    cout << "Sum using Recursion: " << recursiveSum(arr, n) << endl;

    cout<<"This program is developed by yatri dekivadiya - 25CE021";
    return 0;
}
