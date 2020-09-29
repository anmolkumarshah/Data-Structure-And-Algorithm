#include<stdio.h>
#include<stdlib.h>

// in unsorted array

void Find_pair(int arr[], int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == k){
                printf("%d + %d = %d\n",arr[i],arr[j],k);
            }
        }
    }
}

// --------------------------------------------------------- //

int Max(int arr[],int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void Find_pair2(int arr[],int n,int k){
    int m = Max(arr,n);
    int *b = (int *)malloc((m+1)*sizeof(int));
    for(int i=0;i<m;i++){
        b[i] = 0;
    }

    for(int i=0;i<n;i++){
       if(b[k-arr[i]] != 0 && k-arr[i]>0){
          printf("%d + %d = %d\n",k-arr[i],arr[i],k);
       }
       b[arr[i]]++;
    }
}

int main(){
    int arr[10] = {6,3,8,10,16,7,5,2,9,14};
    Find_pair2(arr,10,10);

return 0;
}
