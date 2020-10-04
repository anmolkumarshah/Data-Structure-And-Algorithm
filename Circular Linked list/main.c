#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head;

void Create(int *arr,int n){
    struct Node *last,*t;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = arr[0];
    Head->next = Head;
    last = Head;

    int i;
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=Head);
}

void DisplayR(struct Node *p){
    static int flag = 0;
    if(p!=Head || flag == 0){
            flag = 1;
        printf("%d ",p->data);
        DisplayR(p->next);

    }
    flag = 0;
}

void InsertFirst(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->next = Head;
    t->data = x;
    struct Node *ptr = Head;
    while(ptr->next!=Head){
        ptr=ptr->next;
    }
    ptr->next=t;
    Head=t;
}

void InsertAfter(int index,int x){
   struct Node *t = (struct Node *)malloc(sizeof(struct Node));
   t->data = x;
   int i;
   struct Node *ptr = Head;
   for(i=0;i<index-1;i++){
     ptr=ptr->next;
   }
   t->next = ptr->next;
   ptr->next=t;
}

void Delete(int index){
    int i;
    struct Node *ptr=Head,*q=NULL;
    for(i=0;i<index-1;i++){
        q = ptr;
        ptr=ptr->next;
    }
    q->next = ptr->next;
    free(ptr);
}

void DeleteHead(){
    struct Node *ptr=Head;
    while(ptr->next!=Head){
        ptr=ptr->next;
    }
    ptr->next=Head->next;
    free(Head);
    Head=ptr->next;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    Create(arr,5);
    InsertFirst(10);
    InsertFirst(20);
    InsertAfter(3,30);
    InsertAfter(4,500);
    DisplayR(Head);
    printf("\n");
    Delete(3);
    DisplayR(Head);
    printf("\n");
    DeleteHead();
    DisplayR(Head);
    return 0;
}
