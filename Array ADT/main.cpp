#include<stdio.h>

struct Array{
    int arr[20];
    int size;
    int length;
};

void display(struct Array *arr){
    for(int i=0; i<arr->length;i++){
        printf("%d\t",arr->arr[i]);
    }
    printf("\n");
}

void append(struct Array *arr, int data){
    if(arr->length == arr->size){
        printf("\nArray is full\n");
        return;
    }
    arr->arr[arr->length] = data;
    arr->length++;
}

void insert(struct Array *arr, int index, int data){
    if(index > arr->length || arr->length >= arr->size){
        printf("\ninvalid index\n");
    }
    for(int i=arr->length; i>index; i--){
        arr->arr[i] = arr->arr[i-1];
    }
    arr->arr[index] = data;
    arr->length++;
}

void Delete(struct Array *arr, int index){
    if(index > arr->length || index < 0){
        printf("\ninvalid index\n");
    }
    for(int i = index; i<arr->length-1;i++){
        arr->arr[i] = arr->arr[i+1];
    }
    arr->length--;
}

int binary(int arr[], int low, int high, int key){
    int mid = (low+high)/2;
    while(low<=high){
        if(arr[mid] == key){
            return mid;
        }
        else if(key < arr[mid]){
            return binary(arr, low, mid-1, key);
        }
        else if (key > arr[mid]){
            return binary(arr, mid+1, high, key);
        }
    }
    return -1;
}


int main(){
    struct Array a = {{1,2,3,4,5},20,5};
    insert(&a,3,300);
    display(&a);
    append(&a,100);
    display(&a);
    Delete(&a,2);
    display(&a);
    printf("\nindex is %d",binary(a.arr,0,a.length-1,300));
return 0;
}
