#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int data){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is Empty\n");
    }else{
        t->data = data;
        t->next = NULL;
        if(front == NULL){
            front=rear=t;
        }else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    if(front == NULL){
        printf("Queue is Empty\n");
    }else{
        struct Node *t = front;
        x = front->data;
        front = front->next;
        free(t);
    }
    return x;
}

void display(){
    printf("\n");
    struct Node *p = front;
    while(p){
        printf("%d\t",p->data);
        p=p->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    return 0;
}
