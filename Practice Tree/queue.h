#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<stdio.h>

struct Node{
    struct Node *left;
    struct Node *right;
    int data;
};

struct Queue{
    int front;
    int rear;
    int size;
    int **Q;
};

void create(struct Queue *q,int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,struct Node *data){
    if( (q->rear+1)%q->size == q->front){
        printf("Queue is full\n");
    }else{
        q->rear = (q->rear + 1)%q->size;
        q->Q[q->rear] = data;
    }
}

struct Node * dequeue(struct Queue *q){
    struct Node *x = NULL;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue *q){
    return q->front==q->rear;
}

#endif // QUEUE_H_INCLUDED
