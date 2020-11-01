#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue{
    int data;
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size){
    q->size = size;
    q->Q = (struct Node**)malloc(q->size*sizeof(struct Node *));
    q->rear=q->front=0;
}

void enqueue(struct Queue *q,struct Node * data){
    if( (q->rear+1) % q->size == q->front){
        printf("Queue is full\n");
    }else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = data;
    }
}

struct Node * dequeue(struct Queue *q){
    struct Node * x = NULL;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }else{
        q->front = (q->front+1)%q->size;
        x= q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue *q){
    return q->front==q->rear;
}



#endif // QUEUE_H_INCLUDED
