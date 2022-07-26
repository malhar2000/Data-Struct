#include<iostream>
#include<vector>

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    public:
        Node(int data) : data(data), left(NULL), right(NULL) {}
};