#include<stdio.h>
#include<stdlib.h>

struct Array{
    int arr[20];
    int size;
    int length;
};

void display(struct Array *arr){
    printf("\n");
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

int get(struct Array *arr,int index){
    if(index < arr->length && index >= 0){
       return arr->arr[index];
    }
}

void set(struct Array *arr,int index ,int data){
    if(index < arr->length && index >= 0){
       arr->arr[index] = data;
       return;
    }
}

int sum(struct Array *arr,int n){
    if(n<0){
        return 0;
    }
    return sum(arr,n-1)+arr->arr[n];
}

float avg(struct Array *arr){
    return sum(arr,arr->length)/arr->length;
}

//REVERSE USING ONE MORE ARRAY HERE IN HEAP;
void Reverse(struct Array *arr){
    int *ptr = (int *)malloc(arr->length*sizeof(int));
    int i,j;
    for(i=arr->length-1,j=0; i>=0,j<arr->length; i--,j++){
        ptr[j] = arr->arr[i];
    }
    for (int i=0,j=0;i<arr->length,j<arr->length;i++,j++){
        arr->arr[i] = ptr[j];
    }
    free(ptr);
    ptr = NULL;
}

//SWAP USING POINTERS AND THIRD VARIABLE
void Swap(int *a, int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

//REVERSE USING NO MORE ARRAY BUT USING A SWAP FUNCTION
void Reverse2(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<=j){
        Swap(&arr->arr[i],&arr->arr[j]);
        i++;
        j--;
    }
}

void left_shift(struct Array *arr){
    int i;
    for(i=0;i<arr->length-1;i++){
        arr->arr[i] = arr->arr[i+1];
    }
    arr->arr[i] = 0;
    display(arr);
}

void right_shift(struct Array *arr){
    int i;
    for(i=arr->length-1;i>0;i--){
        arr->arr[i] = arr->arr[i-1];
    }
    arr->arr[i] = 0;
    display(arr);
}

void bubble(struct Array *arr){
    int n = arr->length;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr->arr[j] > arr->arr[j+1]){
                Swap(&arr->arr[j],&arr->arr[j+1]);
            }
        }
    }
    display(arr);
}

void Insert_in_sorted(struct Array *arr,int data){
    int i = arr->length-1;
    while(i>=0 && arr->arr[i]>data){
        arr->arr[i+1] = arr->arr[i];
        i--;
    }
    arr->arr[i+1] = data;
    arr->length++;
    display(arr);
}

int check_if_sorted(struct Array *arr){
    for(int i=0; i<arr->length-1;i++){
        if(arr->arr[i] > arr->arr[i+1]){
            printf("%d %d\n",arr->arr[i],arr->arr[i+1]);
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->arr[i]>0){i++;}
        while(arr->arr[j]<0){j--;}
        if(i<j){
            Swap(&arr->arr[i],&arr->arr[j]);
        }
    }
    display(arr);
}

struct Array * Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->length = arr1->length+arr2->length;
    arr3->size = 20;
    while(i<arr1->length && j<arr2->length){
        if(arr1->arr[i]<arr2->arr[j]){
            arr3->arr[k++] = arr1->arr[i++];
        }
        else{
            arr3->arr[k++] = arr2->arr[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr3->arr[k++] = arr1->arr[i];
    }
    for(;j<arr2->length;j++){
        arr3->arr[k++] = arr2->arr[j];
    }
    return arr3;
}

struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    arr3->size = 20;
    while(i<arr1->length && j<arr2->length){
        if(arr1->arr[i]<arr2->arr[j]){
            arr3->arr[k++] = arr1->arr[i++];

        }
        else if(arr2->arr[j]<arr1->arr[i]){
            arr3->arr[k++] = arr2->arr[j++];

        }
        else{
            arr3->arr[k++] = arr2->arr[j++];
            i++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->arr[k++] = arr1->arr[i];
    }
    for(;j<arr2->length;j++){
        arr3->arr[k++] = arr2->arr[j];
    }
    arr3->length = k;
    display(arr3);
    return arr3;
}

struct Array * Intersaction(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    arr3->size = 20;
    while(i<arr1->length && j<arr2->length){
        if(arr1->arr[i]<arr2->arr[j]){
            //arr3->arr[k++] = arr1->arr[i++];
            i++;
        }
        else if(arr2->arr[j]<arr1->arr[i]){
            //arr3->arr[k++] = arr2->arr[j++];
            j++;
        }
        else{
            arr3->arr[k++] = arr2->arr[j++];
            i++;
        }
    }
    /*
    for(;i<arr1->length;i++){
        arr3->arr[k++] = arr1->arr[i];
    }
    for(;j<arr2->length;j++){
        arr3->arr[k++] = arr2->arr[j];
    }
    */
    arr3->length = k;
    display(arr3);
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    arr3->size = 20;
    while(i<arr1->length && j<arr2->length){
        if(arr1->arr[i]<arr2->arr[j]){
            arr3->arr[k++] = arr1->arr[i++];
            i++;
        }
        else if(arr2->arr[j]<arr1->arr[i]){
            //arr3->arr[k++] = arr2->arr[j++];
            j++;
        }
        else{
            //arr3->arr[k++] = arr2->arr[j++];
            j++;
            i++;
        }
    }

    for(;i<arr1->length;i++){
        arr3->arr[k++] = arr1->arr[i];
    }
    /*
    for(;j<arr2->length;j++){
        arr3->arr[k++] = arr2->arr[j];
    }
    */
    arr3->length = k;
    display(arr3);
    return arr3;
}

int main(){
    struct Array arr1 = {{2,6,8,10,15,25,30,35,40,59},10,9};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    struct Array *arr3;
    Difference(&arr2,&arr1);

return 0;
}
