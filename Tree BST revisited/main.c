#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

struct Node* Insert(struct Node *p,int key){
    struct Node *t;
    if(p==NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data){
        p->lchild =  Insert(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild =  Insert(p->rchild,key);
    }
return p;
}

struct Node* Search(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    else if(key == p->data){
        return p;
    }
    else if(key < p->data){
        Search(p->lchild,key);
    }
    else if(key > p->data){
        Search(p->rchild,key);
    }
};

void InOrder(struct Node *p){
    if(p){
        InOrder(p->lchild);
        printf("%d\t",p->data);
        InOrder(p->rchild);
    }
}

int Height(struct Node *p){
    int x,y;
    if(p){
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x+1 : y+1;
    }
    return 0;
}

struct Node * Inpre(struct Node *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
};

struct Node * InSucc(struct Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
};

struct Node* Delete(struct Node *p,int key){
    struct Node *q;
    if(p==NULL){
        return NULL;
    }
    if( (p->data == key) && (p->lchild == NULL && p->rchild == NULL) ){
            if(p==root){
                root == NULL;
            }
        free(p);
        return NULL;
    }
    if(key < p->data){
        p->lchild = Delete(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }else{
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}



int main()
{
    root = Insert(root,30);
    Insert(root,50);
    Insert(root,33);
    Insert(root,80);
    Insert(root,23);
    InOrder(root);
    Search(root,88) ? printf("Found") : printf("Not fount");
    Delete(root,80);
    printf("\n");
    Delete(root,81);
    InOrder(root);
    return 0;
}
