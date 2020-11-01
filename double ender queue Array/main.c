#include <stdio.h>
#include <stdlib.h>

struct DEQueue{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct DEQueue *de){
    printf("Enter Size of Queue\n");
    scanf("%d",&de->size);
    de->Q = (int *)malloc(sizeof(de->size*sizeof(int)));
    de->rear=-1;
    de->front=-1;
}

void enqueue(struct DEQueue *de,int data,int c){
    if(c==1){
        if(de->rear == de->size-1){
            printf("Queue is full\n");
        }else{
            de->rear++;
            de->Q[de->rear] = data;
        }
    }else{
        if(de->front == -1){
            printf("Cannot perform action\n");
        }else{
            de->Q[de->front] = data;
            de->front--;
        }
    }
}

int deque(struct DEQueue *de,int c){
    int x=-1;
    if(c == 1){
        x = de->Q[de->rear];
        de->rear--;
    }else{
        if(de->front==de->rear){
            printf("Queue is empty\n");
        }else{
            de->front++;
            x=de->Q[de->front];
        }
    }
    return x;
}

void display(struct DEQueue *de){
    int i=0;
    printf("\n");
    for(i=0;i<=de->rear;i++){
        printf("%d\t",de->Q[i]);
    }
}

int main()
{
    struct DEQueue d;
    create(&d);
    enqueue(&d,10,1);
    enqueue(&d,20,1);
    enqueue(&d,30,1);
    display(&d);
    printf("\n%d\n",deque(&d,0));
    enqueue(&d,100,0);
    display(&d);
    enqueue(&d,300,1);
    display(&d);
    return 0;
}
