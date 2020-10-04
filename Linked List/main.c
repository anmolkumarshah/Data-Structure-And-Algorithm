#include <stdio.h>
#include <stdlib.h>
#define MININT -32768

struct Node{
    int data;
    struct Node *next;
}*first = NULL,*second = NULL, *third = NULL;

/*
    creating a pointer of type struct node first -> which is global
    in create function, creating two node last and t of type struct node
    first node has arr[0] data and points no where
    last node has value of first therefore it is also pointing to node created by first

    in for loop t is creating node with data from array index start from 1 to n
    last is calling t, to give newly created node address to ONE pointed by it and put in its
    next
    after it last ask for t to give all node to it.

    and cycle continue.
*/

void Create(int *arr,int n){
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;

    last = first;
    int i;

    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

void Create2(int *arr,int n){
    struct Node *last, *t;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = arr[0];
    second->next = NULL;

    last = second;
    int i;

    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

void Display(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void Display2(struct Node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        Display2(ptr->next);
    }
}

void Display3(struct Node *ptr){
    if(ptr!=NULL){
       Display3(ptr->next);
       printf("%d ",ptr->data);

    }
}

int Count(struct Node *ptr){
    int c = 0;
    while(ptr!=NULL){
        c ++;
        ptr=ptr->next;
    }
    return c;
}

int Count2(struct Node *ptr){
    if(ptr==NULL){
        return 0;
    }
    return Count2(ptr->next)+1;
}

int Sum(struct Node *ptr){
    int sum=0;
    while(ptr){
        sum+=ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int Sum2(struct Node *ptr){
    if(ptr==NULL){
        return 0;
    }
    return Sum2(ptr->next)+ptr->data;
}

int Max(struct Node *ptr){
    int max = ptr->data;
    while(ptr){
        if(ptr->data > max)
            max = ptr->data;
        ptr=ptr->next;
    }
    return max;
}

int Max2(struct Node *ptr){
    int x;
    if(ptr==NULL){
        return MININT;
    }
    x = Max2(ptr->next);
    return x>ptr->data ?x:ptr->data;
}

struct Node * LinearSearch(struct Node *ptr, int key){
    while(ptr){
        if(ptr->data == key)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

struct Node * LinearSearch2(struct Node *ptr, int key){
    if(ptr==NULL){
        return NULL;
    }
    if(key == ptr->data){
        return ptr;
    }
    return LinearSearch(ptr->next,key);
};

struct Node * ImprovedLinear(struct Node *ptr,int key){
    struct Node * q = NULL;
    while(ptr!=NULL){
        if(key == ptr->data){
            q->next = ptr->next;
            ptr->next = first;
            first = ptr;
            return ptr;
        }
        q = ptr;
        ptr = ptr->next;
    }
    return NULL;
};

void InsertFront(struct Node *ptr, int data){
    struct Node *t =(struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = first;
    first = t;
}

void InsertAfter(struct Node *ptr,int index,int data){
    ptr = first;
    int i;
    struct Node *t =(struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    for(i=0;i<index-1&&ptr;i++){
        ptr = ptr->next;
    }
    if(ptr){
        t->next = ptr->next;
        ptr->next = t;
    }
}

void Insert(struct Node *ptr,int index,int data){
    if(index == 0){
        InsertFront(ptr,data);
    }else if(index > 0){
        InsertAfter(ptr,index,data);
    }
}

void InsertSort(int data){
    struct Node *q,*ptr;
    ptr = first;
    if(ptr->data > data){
        InsertFront(ptr,data);
    }
    struct Node *t =(struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    while(ptr && ptr->data < data){
        q = ptr;
        ptr = ptr->next;
    }
    t->next = q->next;
    q->next = t;
}

void Delete(int index){
    if(index == 0){
        struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
        ptr = first;
        first = first->next;
        free(ptr);
    }else{
        int i;
        struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
        struct Node *q =(struct Node *)malloc(sizeof(struct Node));
        ptr = first;
        q = NULL;
        for(i=0;i<index&&ptr;i++){
            q = ptr;
            ptr=ptr->next;
        }
        q->next = ptr->next;
        free(ptr);
    }
}

int isSorted(struct Node *ptr){
    int x = MININT;
    while(ptr){
        if(ptr->data < x)
            return 0;
        x = ptr->data;
        ptr=ptr->next;
    }
    return 1;
}

void RemoveDuplicate(){ // from sorted only
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    struct Node *q =(struct Node *)malloc(sizeof(struct Node));

    ptr = first;
    q = ptr->next;

    while(q){
        if(ptr->data != q->data){
            ptr = q;
            q = q->next;
        }else{
            ptr->next = q->next;
            free(q);
            q = ptr->next;
        }
    }
}

//REVERING LLIST USING SLIDING POINTER TECHNIQUE
void Reverse(){
    struct Node *p = first;
    struct Node *q = NULL;
    struct Node *r = NULL;

    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

//REVERSE LLIST USING RECURSION
void Reverse2(struct Node *q,struct Node *p){
    if(p){
        Reverse2(p,p->next);
        p->next = q;
    }else{
        first = q;
    }
}

void Concatenate(struct Node *first,struct Node *second){
    struct Node *ptr;
    ptr = first;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = second;
}

void Merge(struct Node *first,struct Node *second){
    struct Node *last;
    if(first->data < second->data){
        last = third = first;
        first = first->next;
        third->next = NULL;
    }else{
        last = third = second;
        second = second->next;
        third->next = NULL;
    }
    while(first!=NULL && second !=NULL){
        if(first->data < second->data){
            last->next = first;
            last = last->next;
            first = first->next;
            last->next = NULL;
        }else{
            last->next = second;
            last = last->next;
            second = second->next;
            last->next = NULL;
        }
    }
    if(first!=NULL){
        last->next = first;
    }
    if(second!=NULL){
        last->next = second;
    }
}

int haveLoop(struct Node *ptr){
    struct Node *p,*q;
    p = q = ptr;
    do{
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : NULL;
    }while(p && q && p!=q);
    return p==q ? 1 : 0;

}


int main()
{
    int arr[] = {1,2,3,4,6,7,8};
    int brr[] = {10,20,30,40,50,60,70,80};
    struct Node *t1,*t2;
        Create(arr,7);
        Create2(brr,8);
    //t1=first->next->next;
    //t2=first->next->next->next->next;
    //t2->next=t1;


    //Display(first);
    Display(second);
    //Concatenate(second,first);
    Display(second);
    Merge(first,second);
    printf("\n%d",haveLoop(third));
    return 0;
}
