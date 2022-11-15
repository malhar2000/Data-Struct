#include "Matrix.h"
#include <iostream>
int main(){

    Matrix m(5,4);
    Matrix m1(5, 4);
    int count = 0;
    for(int i = 0; i < 5; i++){
         for(int j = 0; j < 4; j++){
             m.set(i, j, count);
            count++;
         }
    }

    m1 = m; 
    m.print();
    m1.print();
    // m1.set(0, 0, 100);
    std::cout << m1.equals(m) << std::endl;
    
}