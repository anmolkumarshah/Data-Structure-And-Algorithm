#include <iostream>

using namespace std;

void minToMax(int *arr,int n)
{
    int i,temp;
    i = n;
    temp = arr[i];
    while(temp < arr[i/2] && i>1)
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

int main()
{
    int arr[] = {0, 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=2;i<n;i++)
        minToMax(arr,i);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}
