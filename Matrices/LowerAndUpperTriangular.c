#include<stdio.h>
#include<stdlib.h>

struct Matrix{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x){
     i -= 1;
     j -= 1;
     if(i >= j){
         printf("i: %d, j: %d,\n", i,j);
         m->A[i*(i-1)/2+(j-1)] = x; 
         
     }
}

int get(struct Matrix m, int i, int j){
     i -= 1;
     j -= 1;
     if(i >= j){
         return m.A[i*(i-1)/2+(j-1)];
     }
     else{
         return 0;
     }
}

void display(struct Matrix m){
     for(int i=0; i<m.n; i++){
         for(int j=0; j<m.n; j++){
             if(i >= j){
                 printf("%d ", m.A[i*(i-1)/2+(j-1)]);
             }else{
                 printf("0 ");
             }
         }
         printf("\n");
     }
}

int main(){
    struct Matrix m;
    scanf("%d", &m.n); 
    m.A = (int*)malloc(sizeof(int) * (m.n*(m.n+1)/2));
    set(&m,1,1,5);
    set(&m,2,1,5);
    set(&m,2,2,5);
    set(&m,3,1,5);
    set(&m,3,2,5);
    set(&m,3,3,5);
    set(&m,4,1,5);
    set(&m,4,2,5);
    set(&m,4,3,5);
    set(&m,4,4,5);
    set(&m,5,1,5);
    set(&m,5,2,5);
    set(&m,5,3,5);
    set(&m,5,4,5);
    set(&m,5,5,5);
    display(m);

    
}