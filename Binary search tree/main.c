#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

struct Node * insert(struct Node *p,int key){
    struct Node *t;
    if(p==NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = insert(p->lchild,key);
    }else if(key > p->data){
        p->rchild = insert(p->rchild,key);
    }
    return p;
}


void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        printf("%d\t",p->data);
        inOrder(p->rchild);
    }
}

int height(struct Node *p){
    int x,y;
    if(p){
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}

struct Node * inPre(struct Node *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}

struct Node * inSucc(struct Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

struct Node * Delete(struct Node *p,int key){
    if(p==NULL){
        return;
    }
    if(!p->lchild && !p->rchild){
        if(p == root){
            return NULL;
        }
        free(p);
        return NULL;
    }
    struct Node *q;
    if(key < p->data){
        p->lchild = Delete(p->lchild,key);
    }else if(key > p->data){
        p->rchild = Delete(p->rchild,key);
    }else{
        if(height(p->lchild) > height(p->rchild)){
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }else{
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    root = insert(root,30);
    insert(root,20);
    insert(root,34);
    insert(root,10);
    insert(root,25);
    insert(root,40);
    insert(root,35);
    insert(root,50);
    insert(root,33);

    Delete(root,32);

    inOrder(root);
    return 0;
}
