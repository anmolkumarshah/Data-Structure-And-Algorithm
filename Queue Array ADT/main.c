#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *que){
    printf("Enter Size of Queue\n");
    scanf("%d",&que->size);
    que->front = que->rear = -1;
    que->Q = (int *)malloc(que->size*sizeof(int));
}

void enqueue(struct Queue *que,int data){
    if(que->rear == que->size-1){
        printf("Queue is full\n");
    }else{
        que->rear++;
        que->Q[que->rear] = data;
    }
}

int dequeue(struct Queue *que){
    int x=-1;
    if(que->front == que->rear){
        printf("Queue is empty\n");
    }else{
        que->front++;
        x = que->Q[que->front];
    }
    return x;
}

void display(struct Queue *que){
    int i;
    printf("\n");
    for(i=que->front+1;i<=que->rear;i++){
        printf("%d  ",que->Q[i]);
    }
}

int main()
{
    struct Queue q;
    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(&q);
    printf("\n%d\n",dequeue(&q));
    display(&q);
    return 0;
}
