#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q){
    q->front = q->rear = 0;
    printf("Enter Size\n");
    scanf("%d",&q->size);
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int data){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full\n");
    }else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue *q){
    int i = q->front+1;
    do{
        printf("%d\t",q->Q[i]);
        i = (i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
    printf('\n');
}

int main()
{
    struct Queue qu;
    create(&qu);
    enqueue(&qu,10);
    enqueue(&qu,20);
    enqueue(&qu,30);
    enqueue(&qu,40);
     printf("\n%d\n",dequeue(&qu));
    display(&qu);

    return 0;
}
