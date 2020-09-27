#include<stdio.h>

void Find(int arr[],int n){
    int diff = arr[0] - 0;
    for(int i=0;i<n;i++){
        if(arr[i]-i != diff){
            printf("Missing element is %d",i+diff);
            break;
        }
    }
}

// FINDING MORE THAN ONE MISSING ELEMENT FROM SORTED ARRAY
// HERE, DIFF FIRST CALCULATED AND WHEN IT IS MISMATCH THAN WITH INDEX AND DIFF
// MISSING ELEMENT IS FOUND, MISSING ELEMENT CAN BE SUCCESSIVE
// HENSE, WHILE LOOP UNTILL DIFF GETS EQUAL TO NEXT COMMING DIFF
void Find_Multiple(int arr[],int n){
    int diff = arr[0] - 0;
    for(int i=0;i<n;i++){
        if(arr[i]-i != diff){
            while(diff < arr[i]-i){
                printf("Missing element is %d\n",i+diff);
                diff++;
            }
        }
    }
}

int main(){
    int arr[10] = {1,2,3,5,6,7,10,11};
    Find_Multiple(arr,8);
return 0;
}
