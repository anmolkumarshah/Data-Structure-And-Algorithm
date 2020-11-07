#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct Node *root;

void treeCreate(){
    struct Node *p,*t;
    int x;
    root = (struct Node *)malloc(sizeof(struct Node));
    struct Queue q;
    create(&q,20);
    enqueue(&q,root);
    printf("Enter root element\n");
    scanf("%d",&root->data);
    root->left = root->right = NULL;
    while(!isEmpty(&q)){
        p = dequeue(&q);
        printf("Enter left child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            enqueue(&q,t);
            t->left = t->right = NULL;
            p->left = t;
        }

        printf("Enter right child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            enqueue(&q,t);
            t->left = t->right = NULL;
            p->right = t;
        }
    }

}

void preOrder(struct Node *p){
    if(p){
        printf("%d\t",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->left);
        printf("%d\t",p->data);
        inOrder(p->right);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->left);
        postOrder(p->right);
        printf("%d\t",p->data);
    }
}

void levelOrder(struct Node *p){
    printf("\nLevelOrder\n");
    struct Queue l;
    create(&l,20);
    printf("%d\t",p->data);
    enqueue(&l,p);
    while(!isEmpty(&l)){
        p = dequeue(&l);
        if(p->left){
            printf("%d\t",p->left->data);
            enqueue(&l,p->left);
        }
        if(p->right){
            printf("%d\t",p->right->data);
            enqueue(&l,p->right);
        }
    }
}

int count(struct Node *p){
    int x=0,y=0;
    if(p){
        x = count(p->left);
        y = count(p->right);
        return x+y+1;
    }
    return 0;
}

int height(struct Node *p){
    int x=0,y=0;
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

int countDeg2(struct Node *p){
    int x=0,y=0;
    if(p){
        x = countDeg2(p->left);
        y = countDeg2(p->right);
        if(p->left && p->right){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int countLeaf(struct Node *p){
    int x=0,y=0;
    if(p){
        x = countLeaf(p->left);
        y = countLeaf(p->right);
        if(!p->left && !p->right){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int countInner(struct Node *p){
    int x=0,y=0;
    if(p){
        x = countInner(p->left);
        y = countInner(p->right);
        if(p->left || p->right){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int countDeg1(struct Node *p){
    int x=0,y=0;
    if(p){
        x = countDeg1(p->left);
        y = countDeg1(p->right);
        if( (p->left && !p->right) || (!p->left && p->right) ){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}




int main()
{
    treeCreate(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    levelOrder(root);
    printf("\nCount %d\n",count(root));
    printf("\nHeight %d\n",height(root));
    printf("\nCount of deg 2 %d\n",countDeg2(root));
    printf("\nCount of leaf %d\n",countLeaf(root));
    printf("\nCount of deg 1 %d\n",countDeg1(root));
    printf("\nCount of inner nodes %d\n",countInner(root));
    return 0;
}
