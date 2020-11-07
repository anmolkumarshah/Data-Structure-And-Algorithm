#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(int size){
        this->size = size;
        this->front=this->rear = 0;
        this->Q = new Node*[this->size];
    }
    void enqueue(Node *data);
    Node * dequeue();
    int isEmpty();
};

void Queue::enqueue(Node *data){
    if(this->rear+1 == this->front){
        cout<<"Queue is Full"<<endl;
    }else{
        this->rear = (this->rear + 1)%this->size;
        this->Q[this->rear] = data;
    }
}

Node * Queue::dequeue(){
    Node *x = NULL;
    if(this->front==this->rear){
        cout<<"Queue is Empty"<<endl;
    }else{
        this->front = (this->front + 1)%this->size;
        x = this->Q[this->front];
    }
    return x;
}

int Queue::isEmpty(){
    return this->front==this->rear;
}


#endif // QUEUE_H_INCLUDED
