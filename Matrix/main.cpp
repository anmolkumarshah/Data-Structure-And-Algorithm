#include <iostream>

using namespace std;

class Diagonal_Matrix{
private:
    int n;
    int *arr;
public:
    Diagonal_Matrix(int n){
        this->n = n;
        this->arr = new int[n];
    }
    void Set(int row,int col,int data);
    int Get(int row,int col);
    friend ostream & operator<<(ostream &o,Diagonal_Matrix &m);

};

void  Diagonal_Matrix::Set(int row,int col,int data){
    if(row == col){
        this->arr[row-1] = data;
    }
}

int Diagonal_Matrix::Get(int row,int col){
    if(row == col){
        return this->arr[row-1];
    }
}

ostream & operator<<(ostream &o,Diagonal_Matrix &m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i==j){
                cout<<m.arr[i]<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal_Matrix m(5);
    m.Set(1,1,10);m.Set(2,2,20);m.Set(3,3,30);m.Set(4,4,40);m.Set(5,5,50);
    cout<<m;
    cout<<m.Get(3,3);
    return 0;
}
