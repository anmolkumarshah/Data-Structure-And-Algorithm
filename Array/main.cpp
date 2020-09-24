#include<stdio.h>
#include<stdlib.h>


int main(){

   // 2D ARRAY USING STATIC DECLARATION
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");

 // 2D ARRAY USING DYNAMIC DECLARATION

 int *B[3];
 B[0] = (int *)malloc(3*sizeof(int));
 B[1] = (int *)malloc(3*sizeof(int));
 B[2] = (int *)malloc(3*sizeof(int));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
 // three arrays in the heap and one array of pointers in the stack pointing to respective array
 // making three dimensional

 int **C = (int **)malloc(3*sizeof(int *));
 C[0] = (int *)malloc(3*sizeof(int));
 C[1] = (int *)malloc(3*sizeof(int));
 C[2] = (int *)malloc(3*sizeof(int));

   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");


return 0;
}
