#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Matrix{
    int n;
    int *arr = (int *)malloc(n*sizeof(int));

};

void Set(Matrix *m, int i,int j,int x){
    if(i==j){
        m->arr[i] = x;
    }
}

int Get(Matrix *m, int i, int j){
    if(i==j){
        return m->arr[i];
    }else{
        return 0;
    }
}

int Display(Matrix *m){
    for(int i=0;i<m->n;i++){
        for(int j=0;j<m->n;j++){
            if(i==j){
                cout<<Get(m,i,j)<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    Matrix m;
    m.n = 3;
    Set(&m,0,0,10);Set(&m,1,1,20);Set(&m,2,2,30);
    Display(&m);
    return 0;
}
