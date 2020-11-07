#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int height;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

struct Node * LLRotation(struct Node *p){
    struct Node *pl,*plr;
    pl = p->lchild;
    plr = pl->rchild;

    p->lchild = plr;
    pl->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root = p){
        root = pl;
    }

    return pl;
};

struct Node * LRRotation(struct Node *p){
    struct Node *pl,*plr;

    pl = p->lchild;
    plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(p==root){
        root = plr;
    }

    return plr;
};

struct Node * RRRotation(struct Node *p){
    struct Node *pr,*prl;

    pr = p->rchild;
    prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);

    if(root == p){
        root = pr;
    }

    return pr;
};

struct Node * RLRotation(struct Node *p){
    struct Node *pr,*prl;

    pr = p->rchild;
    prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->lchild = p;
    prl->rchild = pr;

    prl->height = NodeHeight(prl);
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root = p){
        root = prl;
    }

    return prl;
};

int BalanceFactor(struct Node *p){
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl-hr;
}

int NodeHeight(struct Node *p){
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl>hr ? hl+1 : hr+1;
 }

struct Node * insert(struct Node *p,int key){
    struct Node *t = NULL;

    if(p==NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->lchild = t->rchild = NULL;
        t->data = key;
        t->height = 1;
        return t;
    }

    if(key < p->data){
        p->lchild = insert(p->lchild,key);
    }else if(key > p->data){
        p->rchild = insert(p->rchild,key);
    }
    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1){
        return LLRotation(p);
    }else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1){
        return RRRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1){
        return RLRotation(p);
    }

    return p;
}

void display(struct Node *p){
    if(p){
        display(p->lchild);
        printf("%d\t",p->data);
        display(p->rchild);
    }
}

int main()
{
    root = insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,25);
    insert(root,28);
    insert(root,27);
    insert(root,5);
    display(root);
    return 0;
}
