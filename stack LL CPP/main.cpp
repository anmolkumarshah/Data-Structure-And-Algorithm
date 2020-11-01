#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        this->top=NULL;
    }
    void push(int data);
    int pop();
    void display();
};

void Stack::push(int data){
    Node *t = new Node;
    if(t==NULL){
        cout<<"Stack Overflow"<<endl;
    }else{
        t->data = data;
        t->next = this->top;
        top=t;
    }
}

int Stack::pop(){
    int x=-1;
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
    }else{
        Node *p = this->top;
        this->top = this->top->next;
        x = p->data;
        delete(p);
    }
    return x;
}

void Stack::display(){
    Node *p = top;
    cout<<endl;
    while(p){
        cout<<p->data<<"  ";
        p = p->next;
    }
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    cout<<endl<<st.pop();
    st.display();
    return 0;
}
