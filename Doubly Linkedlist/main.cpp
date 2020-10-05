#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void Create(int *arr,int n){
    int i;
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    last = first;
    first->next = first->prev = NULL;


    for(i=1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *ptr){
    while(ptr){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void Length(struct Node *ptr){
    int l=0;
    while(ptr){
        l++;
        ptr=ptr->next;
    }
    printf("\nlength is %d\n",l);
}

void InsertFirst(struct Node *ptr,int data){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->next = ptr;
    t->prev = ptr->prev;
    ptr->prev = t;
    first = t;
}

void InsertAfter(int index,int data){
    struct Node *ptr = first;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    int i=0;
    for(i=0;i<index-1;i++){
        ptr=ptr->next;
    }
    t->next = ptr->next;
    t->prev = ptr;
    if(ptr->next)
        ptr->next->prev = t;
    ptr->next = t;

}

void DeleteFirst(struct Node *ptr){
    first = ptr->next;
    if(first){ // CHECKING IF NEXT IS THERE OR NOT
        first->prev = NULL;
    }
    free(ptr);
}

void Delete_after_index(struct Node *ptr,int index){
    int i;
    for(i=0;i<index-1;i++){
        ptr=ptr->next;
    }
            ptr->prev->next = ptr->next;
        if(ptr->next){  // CHECKING IF NEXT IS THERE OR NOT
            ptr->next->prev = ptr->prev;
        }
        free(ptr);
}

void Reverse(struct Node *ptr){
        struct Node *temp;
    while(ptr){
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr=ptr->prev;
        if(ptr && ptr->next == NULL){
            first = ptr;
        }
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    Create(arr,5);
    Length(first);
    InsertFirst(first,10);
    InsertFirst(first,30);
    InsertAfter(3,400);
    InsertAfter(5,500);
    Display(first);
    DeleteFirst(first);
    Display(first);
    Delete_after_index(first,2);
    Display(first);
    Reverse(first);
    Display(first);
return 0;
}
