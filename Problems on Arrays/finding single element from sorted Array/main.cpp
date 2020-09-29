#include<stdio.h>

int sum(int arr[],int n){
    if(n<0){
        return 0;
    }
    return sum(arr,n-1)+arr[n];
}

void Find(int arr[],int n){
    int s = n*(n+1)/2;
    printf("Missing element is %d",s - sum(arr,4));
}


int main(){
    int arr[5] = {1,2,3,5,6};
    int n = 5;
    Find(arr,arr[4]);

return 0;
}
