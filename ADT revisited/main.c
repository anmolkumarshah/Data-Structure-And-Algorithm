#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int height;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

struct Node * LLRotation(struct Node *p){
    struct Node *pl,*plr;
    pl = p->lchild;
    plr = pl->rchild;

    p->lchild = plr;
    pl->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p==root){
        root = pl;
    }

    return pl;
}

struct Node * RRRotation(struct Node *p){
    struct Node *pr,*prl;
    pr = p->rchild;
    prl = pr->lchild;

    p->rchild = pr->lchild;
    pr->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);



    if(p==root){
        root = pr;
    }

    return pr;
}

struct Node * RLRotation(struct Node *p){
    struct Node *pr,*prl;
    pr = p->rchild;
    prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(p==root){
        root = prl;
    }

    return prl;
};

struct Node * LRRotation(struct Node *p){
    struct Node *pl,*plr;
    pl = p->lchild;
    plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    plr->height = NodeHeight(plr);
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);

    if(p==root){
        root = plr;
    }

    return plr;
}

int NodeHeight(struct Node *p){
    int hl,hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl>hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Node *p){
    int hl,hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl-hr;
}


struct Node * Insert(struct Node*p,int key){
    struct Node *t = NULL;
    if(p==NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1;
        return t;
    }

    if(key < p->data){
        p->lchild = Insert(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = Insert(p->rchild,key);
    }

    p->height = NodeHeight(p);

    if( BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1 ){
        return LLRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    }else if(BalanceFactor(p)== 2 && BalanceFactor(p->lchild == -1)){
        return LRRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }

    return p;
}

struct Node *inPre(struct Node*p){
    if(p && p->rchild){
        p = p->rchild;
    }
    return p;
}

struct Node *inSucc(struct Node *p){
    if(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

struct Node * Delete(struct Node *p,int key){
    struct Node *q;
    if(!p){
        return NULL;
    }
    if((p->data == key) && (!p->lchild && !p->rchild)){
        if(p==root){
            root = NULL;
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
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild)){
                q = inPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild,q->data);
        }else{
                q = inSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild,q->data);
        }
    }

    p->height = NodeHeight(p);
    if( BalanceFactor(p) == 2 && BalanceFactor(p->lchild) <= 1 ){
        return LLRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) >= -1){
        return RRRotation(p);
    }else if(BalanceFactor(p)== 2 && BalanceFactor(p->lchild == -1)){
        return LRRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }
    return p;
};

void InOrder(struct Node *p){
    if(p){
        InOrder(p->lchild);
        printf("%d\t",p->data);
        InOrder(p->rchild);
    }
}

int main()
{
    root=Insert(root,30);
    Insert(root,10);
    Insert(root,40);
    Insert(root,20);
    InOrder(root);
    Delete(root,40);
    printf("\n");
    InOrder(root);
    return 0;
}
