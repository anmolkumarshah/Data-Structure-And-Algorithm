#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int data){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Stack Overflow\n");
        return;
    }else{
        t->data = data;
        t->next = top;
        top=t;
    }
}

int pop(){
    int x=-1;
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }else{
        struct Node *p = top;
        top=top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int peek(int pos){
    int i;
    struct Node *p = top;
    for(i=0;i<pos-1 && p!= NULL;i++){
        p=p->next;
    }
    if(p){
        return p->data;
    }else{
        return -1;
    }
}

void isFull(){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t){
        printf("\nStack is not full yet\n");
    }else{
        printf("\nStack is full\n");
    }
    free(t);
}

void display(){
    struct Node *t=top;
    printf("\n");
    while(t){
        printf("%d\t",t->data);
        t=t->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    printf("\n%d",peek(3));
    isFull();
    return 0;
}
