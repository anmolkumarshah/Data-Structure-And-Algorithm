#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void Create(struct Sparse *s){
    printf("Enter Dimensions\t");
    scanf("%d %d",&s->m,&s->n);
    printf("Enter Non Zero Elements\t");
    scanf("%d",&s->num);
    s->e = (struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter Elements\n");
    for(int i=0;i<s->num;i++){
        //printf("\nAnmol\n");
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void Display(struct Sparse *s){
    int k=0;
    for(int i=0;i<s->m;i++){
        for(int j=0;j<s->n;j++){
            if(i==s->e[k].i && j==s->e[k].j){
                printf("%d ",s->e[k++].x);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse * Add(struct Sparse *s1, struct Sparse *s2){
    if(s1->m != s2->m && s1->n != s2->n){
        return 0;
    }
    struct Sparse *s3 =(struct Sparse*)malloc(sizeof(struct Sparse));
    s3->e = (struct Element *)malloc( (s1->num+s2->num) * sizeof(struct Element));
    int i,j,k;
    i=j=k = 0;
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i < s2->e[j].i){
            s3->e[k++] = s1->e[i++];
        }else if(s2->e[i].i < s1->e[i].i){
            s3->e[k++] = s2->e[j++];
        }else{
            if(s1->e[i].j < s2->e[i].j){
                s3->e[k++] = s1->e[i++];
            }else if(s2->e[i].j < s1->e[i].j){
                s3->e[k++] = s2->e[j++];
            }else{
                s3->e[k] = s1->e[i];
                s3->e[k++].x = s2->e[j++].x + s1->e[i++].x;
            }
        }
    }
    for(;i<s1->num;i++){
        s3->e[k++] = s1->e[i];
    }
    for(;j<s1->num;j++){
        s3->e[k++] = s2->e[j];
    }
    s3->m = s1->m;
    s3->n = s1->n;
    s3->num = k;

    printf("\n");
    for(int i=0;i<s3->num;i++){
        printf("%d ",s3->e[i]);
    }
    printf("\n");

    return s3;
}

int main(){
    struct Sparse s1,s2,*s3;
    Create(&s1);
    Display(&s1);

    Create(&s2);
    Display(&s2);

    s3 = Add(&s1,&s2);
    printf("\nResults\n");
    Display(s3);
return 0;
}
