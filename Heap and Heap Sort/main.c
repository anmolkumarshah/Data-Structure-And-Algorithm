#include <stdio.h>
#include <stdlib.h>

void insert(int *arr,int n){
    int temp;
    int i=n;
    temp = arr[i];
    while(i>1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void Delete(int *arr,int n){
    int i,j,temp,val;
    val = arr[1];
    arr[1] = arr[n];
    arr[n] = val;
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(arr[j+1] > arr[j])
            j = j+1;
        if(arr[j] > arr[i])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
            break;
    }
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++)
        insert(H,i);

    for(i=7;i>1;i--)
        Delete(H,i);

    for(i=1;i<=7;i++)
        printf("%d\t",H[i]);
    return 0;
}
