#include<iostream>

using namespace std;

void rotate_right(int A[], int n){ 
     int last = A[n-1];
        for(int j=n-1; j > 0; j--){
            A[j] = A[j-1];
        }
        A[0] = last;  
}

int main(){
    int A[] = {1,2,3,4,5,6};
    
    rotate_right(A, 6);
    rotate_right(A, 6);
     
    
    
    for(int i = 0; i < 6; i++){
        std::cout << A[i] <<" ";
    }

}