#include "Matrix.h"
#include<iostream>
#include<cassert>

Matrix::Matrix(int _r, int _c){
    assert(_r > 0);
    assert(_c > 0);
    r = _r;
    c = _c;
    p = new int[r*c]; 
    int count = 0;
    for(int i = 0; i < r; i++){
         for(int j = 0; j < c; j++){
            set(i, j, 0);
            count++;
         }
    }
}

// release all resources
Matrix::~Matrix(){
    delete [] p;
}

// CC
Matrix::Matrix(const Matrix &rhs){
    p = new int[rhs.r*rhs.c]; 
    int count = 0;
    for(int i = 0; i < rhs.r; i++){
         for(int j = 0; j < rhs.c; j++){
            p[count] = rhs.get(i, j);
            count++;
         }
    }
}

// AO
// pre-condition: rhs must have same size
Matrix &Matrix::operator=(const Matrix &rhs){
    int count = 0; 
    for(int i = 0; i < rhs.r; i++){
         for(int j = 0; j < rhs.c; j++){
            p[count] = rhs.get(i, j);
            count++;
         }
    }
    return *this;
}

// return size (number of total elements)
int Matrix::size() const{
    return r*c;
}

// set matrix element (r,c) to value
// (indexes start with 0)
// pre-condition: r,c within range
void Matrix::set(int r, int c, int value){
 
   p[r*this->c+c] = value;
}

// return matrix element (r,c)
// (indexes start with 0)
// pre-condition: r,c within range
int Matrix::get(int r, int c) const{
    //row major techinque
 
    return p[r*this->c+c];
}

// print all elements to stdout - row by row, using space as separator
void Matrix::print() const{
    for(int i = 0; i < this->r; i++){
        for(int j = 0; j < this->c; j++){
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

// return true iff m has the same size (rows and cols) as maxtrix and identical
// elements
bool Matrix::equals(const Matrix &m) const{
    bool flag = 0;
    if(m.c*m.r == r*c){
        flag = 1;
    }
    for(int i = 0; i < 4; i++){
         for(int j = 0; j < 5; j++){
             if(m.get(i, j) != get(i, j)){
                flag = 0;
             }
         }
    }
    if(flag == 1){
        return flag;
    }
    return flag;
}

 