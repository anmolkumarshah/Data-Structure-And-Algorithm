#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

using namespace std;

class Node{
public:
    Node *left;
    Node *right;
    int data;
};

class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(int size);
    void enqueue(Node *data);
    Node * dequeue();
    int isEmpty();
};


Queue::Queue(int size){
    this->size = size;
    Q = new Node *[size];
    front = rear = 0;
}

void Queue::enqueue(Node *data){
    if( (rear+1)%size + 1 == front ){
        cout<<"Full"<<endl;
    }else{
        rear = (rear+1)%size;
        Q[rear] = data;
    }
}

Node * Queue::dequeue(){
    Node *x = NULL;
    if(front==rear){
        cout<<"Empty"<<endl;
    }else{
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

int Queue::isEmpty(){
    return rear==front;
}


#endif // QUEUE_H_INCLUDED
