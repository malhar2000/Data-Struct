#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void simple_sort(int A[], int n){
     
    int index_min = -1;
    for(int i = 0; i < n ; i++){
        int min = INT_MAX;
        for(int j = i; j < n; j++){
            if(A[j] < min){
                min = A[j];
                index_min = j;
            }
        }
        int temp = A[i];
        A[i] =  A[index_min];
        A[index_min] = temp;
    }
     
}

int main(){
   int A[] = {2, -2223, 221, 1, 3, -2};
   int size = sizeof(A)/4;
   simple_sort(A, size);
 
   for(int i = 0; i < size; i++){
    printf("%d ", A[i]);
   }
   printf("\n");
}