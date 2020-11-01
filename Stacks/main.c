#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
};

void Create(struct Stack *st){
    printf("Enter Size\t");
    scanf("%d",&st->size);
    st->s =(int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void Display(struct Stack *st){
    int i;
    for(i=st->top;i>=0;i--){
        printf("%d\t",st->s[i]);
    }
    printf("\n");
}

void Push(struct Stack *st,int data){
    if(st->top == st->size-1){
        printf("Stack Overflow\n");
    }else{
        st->top++;
        st->s[st->top] = data;
    }
}

int Pop(struct Stack *st){
    int x=-1;
    if(st->top == -1){
        printf("Stack Empty\n");
    }else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int main()
{
    struct Stack s1;
    Create(&s1);
    Push(&s1,50);
    Push(&s1,51);
    Push(&s1,52);
    Push(&s1,53);
    Display(&s1);
    printf("\n%d\n",Pop(&s1));
    Display(&s1);
    Push(&s1,53);
    Push(&s1,53);
    Push(&s1,53);
    Display(&s1);
    return 0;
}
