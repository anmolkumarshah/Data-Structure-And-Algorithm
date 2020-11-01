#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int *arr,int n){
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    int i=0;
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = last->next;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    create(arr,5);
    Display(first);
    return 0;
}
