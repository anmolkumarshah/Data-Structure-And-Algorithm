#include<stdio.h>

// FINDIND DUPLICATE ELEMENTS AND PRINTING ONCE WITH HELP OF PREV_DUPLICATE VARIABLE
void Find_Duplicate(int arr[],int n){
    int prev_duplicate = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1] && arr[i]!= prev_duplicate){
            printf("%d\t",arr[i]);
            prev_duplicate = arr[i];
        }
    }
}

// FINDING COUNT WITH HELP OF J AND THE DIFFERENCE OF INDEXES
void Find_Duplicate_Count(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        if(arr[i] == arr[i+1]){
            j=i;
            while(arr[j]== arr[i]){
                j++;
            }
            int count = j-i;
            printf("%d is repeating %d times\n",arr[i],count);
            i = j-1;
        }
    }
}

int main(){
    int arr[10] = {3,6,8,8,10,12,15,15,15,20};
    Find_Duplicate_Count(arr,10);
return 0;
}
