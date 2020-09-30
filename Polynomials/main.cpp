#include<stdio.h>
#include<stdlib.h>

struct Term{
    int coef;
    int power;
};

struct Poly{
    int n;
    struct Term *term;
};

void Create(Poly *ptr){
    printf("Enter no. of terms\n");
    scanf("%d",&ptr->n);
    ptr->term = (Term *)malloc(ptr->n*sizeof(struct Term));
    printf("Enter coefficients & powers\n");
    for(int i=0;i<ptr->n;i++){
            scanf("%d %d",&ptr->term[i].coef,&ptr->term[i].power);
    }
}

void Display(Poly *ptr){
    for(int i=0;i<ptr->n;i++){
        printf("%dx^%d + ",ptr->term[i].coef,ptr->term[i].power);
    }
    printf("\n");
}

Poly * Add(Poly *a, Poly *b){
    int i,j,k;
    i=j=k = 0;
    Poly *result = (Poly *)malloc(sizeof(struct Poly));

    result->term = (Term *)malloc((a->n+b->n)*sizeof(struct Term));
    while(i<a->n && j<b->n){
        if(a->term[i].power > b->term[j].power){
            result->term[k++] = a->term[i++];
        }else if(b->term[j].power > b->term[i].power){
            result->term[k++] = b->term[j++];
        }else{
            result->term[k] = a->term[i];
            result->term[k++].coef = a->term[i++].coef + b->term[j++].coef;
        }
    }
    for(;i<a->n;i++){
        result->term[k++] = a->term[i];
    }
    for(;j<b->n;j++){
        result->term[k++] = b->term[j];
    }
    result->n = k;
    return result;
}



int main(){

    struct Poly p1,p2;
    Create(&p1);
    Display(&p1);
    Create(&p2);
    Display(&p2);

    struct Poly *res =  Add(&p1,&p2);
    Display(res);

return 0;
}
