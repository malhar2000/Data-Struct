#include<stdio.h>
#include<stdlib.h>

/*
Left child = 2*i;
Right child = 2*i + 1;
*/

/**
 * Swap helper function to swap the children and parent.
 * i1 - index of parent
 * i2 - index of child
*/
void swap(int A[], int i1, int i2){
    int temp = A[i1];
    A[i1] = A[i2];
    A[i2] = temp; 
}

/**
 * delet function works to delete's the root and return value we can return or either store in the empty location of the
 * array and get a sorted array
 * n = size of the array
*/
int delete(int A[], int n){
    int i = 1, j = 2*i; int x;
    x = A[1];

    //assign the root the last element of the array
    A[1] = A[n];
    while(j <= n-1){
        //comparing the two children from the top i.e when i = 1, j = 2 so A[2] < A[3]
        if(A[j] < A[j+1]){
            j += 1;
        }

        //if the value at the root was smaller then its children we swap and then assign i = j becoz 
        // j has the position of the children i.e. left or right child we swapped with.
        // we change the value of j = j * 2;becoz now we are going to look at the values of next children.
        if(A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2 * j;
        }else{
            break;
        }
    }
    return x;
}

void Insert(int A[], int n){
    int temp, i = n;
    //we pick the one we want to number you want to insert....
    temp = A[n];

    //here we check if the # we want to insert is greater than its parent
    //if so then we move the its parent to the index of the # we want to insert
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}


void createHeap(int *A, int n){
    for(int i = 2; i < n; i++){
        Insert(A, i);
    }
}

 
int main(){
    // int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    
    // createHeap(A, sizeof(A)/4);
    int n = 0;
    printf("Please entere the size of the heap: ");
    scanf("%d", &n);
    int *A = malloc(sizeof(int)*n);

    
    // starting at 1 becoz we want the 0 index to be zero.
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
        Insert(A, i);
    }

    for(int i = 0; i <=  n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");

    for(int i = n; i > 0; i--){
        int value = delete(A, i);
        printf("%d ", value);
    }
    free(A);
}

 