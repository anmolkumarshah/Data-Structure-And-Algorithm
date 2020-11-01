#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *ptr;
};

void create(struct Stack *s){
    s->top = -1;
    printf("Enter Size of Stack\t");
    scanf("%d",&s->size);
    s->ptr = (struct Stack *)malloc(s->size*sizeof(int));
}

void push(struct Stack *s,int data){
    if(s->top == s->size-1){
        printf("Stack Overflow\n");
        return;
    }else{
        s->top++;
        s->ptr[s->top] = data;
    }
}

int pop(struct Stack *s){
    int x = -1;
    if(s->top == -1){
        printf("Stack underflow\n");
        return;
    }else{
        x = s->ptr[s->top];
        s->top--;
        return x;
    }
}

void peek(struct Stack s,int index){
     printf("\n");
    if(s.top-index+1 < 0){
        printf("Invalid index\n");
    }else{
        printf("%d\n",s.ptr[s.top-index+1]);
    }
}

void display(struct Stack s){
    int i;
    printf("\n");
    for(i=s.top;i>=0;i--){
        printf("%d\t",s.ptr[i]);
    }
}

int isEmpty(struct Stack s){
    if(s.top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Stack s){
    if(s.top == s.size-1){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,20);
    push(&st,40);
    push(&st,60);
    push(&st,80);
    push(&st,160);
    push(&st,650);
    display(st);
   // pop(&st);
   // pop(&st);
    display(st);
    peek(st,2);
    return 0;
}
