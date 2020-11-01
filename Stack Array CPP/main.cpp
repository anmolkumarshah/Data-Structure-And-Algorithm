#include <iostream>

using namespace std;


class Stack{
public:
    int size;
    int top;
    int *ptr;
    Stack(){
        cout<<"Enter Size:\t";
        cin>>this->size;
        this->top = -1;
        this->ptr = new int[this->size];
    }
    void push(int data);
    int pop();
    void display();
};

void Stack::push(int data){
    if(this->top == this->size-1){
        cout<<"Stack overflow"<<endl;
    }else{
        this->top++;
        this->ptr[this->top] = data;
    }
}

int Stack::pop(){
    int x=-1;
    if(this->top == -1){
        cout<<"Stack is empty"<<endl;
    }else{
        x = this->ptr[this->top];
        this->top--;
    }
    return x;
}

void Stack::display(){
    cout<<endl;
    for(int i=this->top;i>=0;i--){
        cout<<this->ptr[i]<<"  ";
    }
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    cout<<endl<<st.pop()<<endl;
    return 0;
}
