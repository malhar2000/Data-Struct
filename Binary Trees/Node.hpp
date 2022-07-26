#include <iostream>
#include <queue>

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    public:
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
