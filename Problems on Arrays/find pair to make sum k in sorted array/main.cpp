#include<stdio.h>

void Find_pair(int arr[],int n,int k){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i] + arr[j] == k){
            printf("%d + %d = %d\n",arr[i],arr[j],k);
            i++;
            j--;
        }
        else if(arr[i]+arr[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
}

int main(){
    int arr[10] = {1,3,4,5,6,8,9,10,12,14};
    Find_pair(arr,10,10);
return 0;
}
