#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Node * root = NULL;

void treeCreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value\n");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&q,root);

    while(!isEmpty(&q)){
        p = dequeue(&q);
        printf("Enter left child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->left=t->right = NULL;
            p->left = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->left=t->right = NULL;
            p->right = t;
            enqueue(&q,t);
        }
    }

}

void preorder(struct Node *p){
    if(p){
       printf("%d\t",p->data);
       preorder(p->left);
       preorder(p->right);
    }
}

void inorder(struct Node *p){
    if(p){
       inorder(p->left);
       printf("%d\t",p->data);
       inorder(p->right);
    }
}

void postorder(struct Node *p){
    if(p){
       postorder(p->left);
       postorder(p->right);
       printf("%d\t",p->data);
    }
}

int main()
{
    treeCreate();
    printf("\nPreOrder\n");
    preorder(root);
    printf("\nInOrder\n");
    inorder(root);
    printf("\nPostOrder\n");
    postorder(root);
    return 0;
}
