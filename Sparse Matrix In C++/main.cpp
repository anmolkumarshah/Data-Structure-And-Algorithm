#include <iostream>

using namespace std;

class Element{
public:
    int i;
    int j;
    int x;
};

class Sparse{
private:
    int row;
    int col;
    int num;
    Element *e;
public:
    Sparse(int row, int col, int num){
        this->row = row;
        this->col = col;
        this->num = num;

        this->e = new Element[num];
    }
    ~Sparse(){
        delete []e;
    }

    friend ostream & operator<<(ostream &o, Sparse &s);
    friend istream & operator>>(istream &in, Sparse &s);
    Sparse  operator+(Sparse &s2);
};

istream & operator>>(istream &in, Sparse &s){
     cout<<"Enter Elements"<<endl;
        for(int i=0;i<s.num;i++){
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }
    return in;
}


ostream & operator<<(ostream &o, Sparse &s){
      o<<endl;
     int k=0;
        for(int i=0;i<s.row;i++){
            for(int j=0;j<s.col;j++){
                if(i==s.e[k].i && j==s.e[k].j){
                    o<<s.e[k++].x<<" ";
                }else{
                    o<<"0 ";
                }
            }
            o<<endl;
        }
        o<<endl;
        return o;
}
Sparse  Sparse::operator+(Sparse &s2){
        int i,j,k;
        i = j = k = 0;
        if(row != s2.row && col != s2.col){
            cout<<"Error"<<endl;
        }
        Sparse sum(row,col,num+s2.num);
        while(i<num && j<s2.num){
            if(e[i].i < s2.e[j].i){
                sum.e[k++] = e[i++];
            }else if(s2.e[j].i < e[i].i){
                sum.e[k++] = s2.e[j++];
            }else{
                if(e[i].j < s2.e[j].j){
                    sum.e[k++] = e[i++];
                }else if(s2.e[j].j < e[i].j){
                    sum.e[k++] = s2.e[j++];
                }else{
                    sum.e[k] = e[i];
                    sum.e[k++].x = e[i++].x + s2.e[j++].x;
                }
            }
        }
        for(;i<num;i++){
            sum.e[k++] = e[i];
        }
        for(;j<s2.num;j++){
            sum.e[k++] = s2.e[j];
        }

        return sum;
    }

int main()
{
    Sparse s1(5,5,5),s2(5,5,5);
    cin>>s1;
    cout<<s1;
    cin>>s2;
    cout<<s2;
    Sparse s3 = s1+s2;
    cout<<s3;

    return 0;
}
