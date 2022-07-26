#include <stdio.h>


void swap(int *i1, int *i2){
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp; 
}

void Selection(int A[], int n){
    int i,j,k;

    for(i = 0; i < n-1; i++){
        j = i+1;
        k = i;
        while(j < n ){
            if(A[j] < A[k]){
                k = j; 
            }
            j++;
        }
        swap(&A[i], &A[k]);
         
    }   
}
int main(){
    int A[] = {4, 5,2, 1, 7, 4, 11};
    Selection(A, 7);

    for(int i=0; i<7; i++){
        printf("%d ", A[i]);
    }
}