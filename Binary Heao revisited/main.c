#include <stdio.h>
#include <stdlib.h>

int * Insert(int *arr,int n){
    int i,temp;
    i = n;
    temp = arr[i];
    while(i>1&&temp>arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
    return arr;
}

int * Delete(int *arr,int n){
    int x,i,j,temp;
    x = arr[1];
    arr[1] = arr[n];
    arr[n] = x;
    i=1,j=2*i;
    while(j<n-1)
    {
        if(arr[j+1] > arr[j])
            j = j+1;
        if(arr[j] > arr[i])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i = j;
            j = 2*i;
        }
        else
            break;
    }

    return arr;
}

int main()
{
    int arr[] = {0,10,20,30,25,5,40,35};
    int *res,*res2;
    int i;
    for(i=2;i<=7;i++){
        Insert(arr,i);
    }
    for(i=1;i<=7;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for(i=7;i>1;i--){
        Delete(arr,i);
    }
    for(i=1;i<=7;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
