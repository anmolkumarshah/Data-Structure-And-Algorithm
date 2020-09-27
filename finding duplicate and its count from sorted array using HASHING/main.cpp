#include<stdio.h>
#include<stdlib.h>

int Max(int arr[],int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void Find_Duplicate_count(int arr[],int n){
    int m = Max(arr,n);
    int *b = (int *)malloc((m+1)*sizeof(int));
    for(int i=0;i<m;i++){
        b[i] = 0;
    }
    for(int i=0;i<n;i++){
        b[arr[i]]++;
    }
    for(int i=0;i<=m;i++){
        if(b[i]>1){
            printf("%d is repeating %d times\n",i,b[i]);
        }
    }
}

int main(){
    int arr[10] = {3,6,8,8,10,12,15,15,15,20};
    Find_Duplicate_count(arr,10);
return 0;
}
