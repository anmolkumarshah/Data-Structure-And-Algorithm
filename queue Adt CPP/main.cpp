#include <iostream>

using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int size = 0){
        this->size = size;
        this->front = this->rear = -1;
        this->Q = new int[this->size];
    }
    void enqueue(int data);
    int dequeue();
    void display();
};

void Queue::enqueue(int data){
    if(this->rear == this->size-1){
        cout<<"Queue is Full"<<endl;
    }else{
        this->rear++;
        this->Q[this->rear] = data;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(this->rear == this->front){
        cout<<"Queue is empty"<<endl;
    }else{
        this->front++;
        x = this->Q[this->front];
    }
    return x;
}

void Queue::display(){
    cout<<endl;
    for(int i = this->front+1;i<=this->rear;i++){
        cout<<this->Q[i]<<"  ";
    }
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    cout<<endl<<q.dequeue()<<endl;
    q.display();
    return 0;
}
