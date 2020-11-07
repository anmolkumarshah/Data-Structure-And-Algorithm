#include <iostream>
#include "queue.h"

using namespace std;

class Tree{
private:
    Node *root = NULL;
public:
    Tree();
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    void levelOrder(Node *p);
    Node *getRoot();
    int count(Node *p);
    int height(Node *p);
};

Node * Tree::getRoot(){
    return this->root;
}

Tree::Tree(){
    Queue q(20);
    Node *p,*t;
    int x;
    root = new Node;
    cout<<"Enter Root element"<<endl;
    cin>>root->data;
    root->left = root->right = NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        if(p){

            cout<<"Enter left child of "<<p->data<<endl;
            cin>>x;
            if(x!=-1){
                t = new Node;
                t->data = x;
                t->left = t->right = NULL;
                p->left = t;
                q.enqueue(t);
            }

            cout<<"Enter right child of "<<p->data<<endl;
            cin>>x;
            if(x!=-1){
                t = new Node;
                t->data = x;
                t->left = t->right = NULL;
                p->right = t;
                q.enqueue(t);
            }

        }
    }
}

void Tree::preOrder(Node *p){

    if(p){
        cout<<p->data<<"\t";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void Tree::inOrder(Node *p){

    if(p){
        inOrder(p->left);
        cout<<p->data<<"\t";
        inOrder(p->right);
    }
}

void Tree::postOrder(Node *p){
    if(p){
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<"\t";
    }
}

void Tree::levelOrder(Node *p){
    if(p){
        Queue q(20);
        Node *r;
        q.enqueue(p);
        cout<<p->data<<"\t";
        while(!q.isEmpty()){
            r = q.dequeue();
            if(r->left){
                cout<<r->left->data<<"\t";
                q.enqueue(r->left);
            }
            if(r->right){
                cout<<r->right->data<<"\t";
                q.enqueue(r->right);
            }
        }
    }
}

int Tree::count(Node *p){
    int x = 0,y = 0;
    if(p){
        x = count(p->left);
        y = count(p->right);
        return x+y+1;
    }
    return 0;
}

int Tree::height(Node *p){
    int x = 0,y = 0;
    if(p){
        x = height(p->left);
        y = height(p->right);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}



int main()
{
    Tree t;
    cout<<endl<<"PreOrder"<<endl;
    t.preOrder(t.getRoot());
    cout<<endl<<"InOrder"<<endl;
    t.inOrder(t.getRoot());
    cout<<endl<<"PostOrder"<<endl;
    t.postOrder(t.getRoot());
    cout<<endl<<"LevelOrder"<<endl;
    t.levelOrder(t.getRoot());
    cout<<endl<<"Count of Nodes"<<endl;
    cout<<t.count(t.getRoot());
    cout<<endl<<"Height of Tree"<<endl;
    cout<<t.height(t.getRoot());
    return 0;
}
