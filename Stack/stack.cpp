#include<iostream>
 

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d):data{d}, next{NULL}{

    }
};

void push(Node *&top, int data){
    Node *temp = new Node(data); 
    temp->next = top; 
    top = temp;
}
int pop(Node *&top){
    int x = top->data;
    ///getting address to free that particular address
    Node *temp = top;
    top = top->next;
    free(temp);
    return x;
}
void print(Node *top){
    while(top != NULL){
        cout << top->data << endl;
        top = top->next;
    }
    cout << endl;
}

int main(){
    Node *top = new Node(10);
    push(top, 100);
    push(top, 1000);
    push(top, 10000);
    push(top, 100000);
    pop(top);
  
    print(top);

    cout<<top->data<<endl;
}