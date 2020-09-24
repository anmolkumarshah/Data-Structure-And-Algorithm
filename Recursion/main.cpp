#include<stdio.h>

// SUM OF n NATURNAL NUMBERS
int sum(int n){
    if(n == 0){
        return 0;
    }
    return sum(n-1)+n;
}

// FACTORIAL n!
int fact(int n){
    if(n == 1){
        return 1;
    }
    return fact(n-1)*n;
}
// POWER FUNCTION m^n
int power(int m, int n){
    if(n == 0){
        return 1;
    }
    return power(m,n-1)*m;
}
// COMBINATION FORMULA nCr
int c(int n, int r){
    if(n==r || r==0){
        return 1;
    }
    return c(n-1,r-1)+c(n-1,r);
}

// TAYLOR SERIES e^x
double e(int x, int n){
    static double s = 1;
    if(n==0){
        return s;
    }
    s = 1+(x*s)/n;
    return e(x,n-1);
}

void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("Mave %d to %d\t",A,C);
        TOH(n-1,B,A,C);
    }
}


int main(){

    printf("%d\n",sum(10));
    printf("%d\n",fact(5));
    printf("%d\n",power(2,5));
    printf("%d\n",c(4,2));
    printf("%lf\n",e(1,10));
    TOH(3,1,2,3);

return 0;
}
