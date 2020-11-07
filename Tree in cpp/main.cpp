#include <iostream>
#include "queue.h"

using namespace std;

class Tree{
public:
    Node *root = NULL;
    Tree(){
        Node *p,*t;
        int x;
        Queue q(50);
        root = new Node;
        q.enqueue(root);
        root->left=root->right = NULL;
        cout<<"Enter Root Element"<<endl;
        cin>>root->data;
        while(!q.isEmpty()){
            p = q.dequeue();
            cout<<"Enter left child of "<<p->data<<endl;
            cin>>x;
            if(x!=-1){
               t = new Node;
               t->data = x;
               t->left=t->right = NULL;
               p->left = t;
               q.enqueue(t);
            }

            cout<<"Enter right child of "<<p->data<<endl;
            cin>>x;
            if(x!=-1){
               t = new Node;
               t->data = x;
               t->left=t->right = NULL;
               p->right = t;
               q.enqueue(t);
            }
        }
    }
    void preorder(Node *p);
};

void Tree::preorder(Node *p){
    if(p){
        cout<<p->data<<"  ";
        preorder(p->left);
        preorder(p->right);
    }
}


int main()
{
    Tree t;
    t.preorder(t.root);
    return 0;
}
