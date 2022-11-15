#include <iostream>


using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

};
Node *head = NULL;

void insert(int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        d--;
    }
    Node *prev = head;
    while (d > 0)
    {
        Node *temp = new Node(d);
        // 1 2 3 4 5 6 7 8 9 10 
        temp->next = head;
        head = temp;
        // 10 9 8 7 6 5 4 3 2 1
        // prev->next = temp;
        // prev = temp;
        d--;
    }
}

void insertAt(int pos, int data){
    Node *n = new Node(data);
    if(pos == 0){
         
        n->next = head;
        head = n;
        return;
    }
    Node *temp = head;
    while(pos > 1){
        temp = temp->next;
        pos--;
    }
    n->next = temp->next;
    temp->next = n;
}

void reverse(){
    Node *temp = head;
    Node *holder = NULL;
    Node *temp_next;

    while(temp != NULL){
        temp_next = temp->next;
        temp->next = holder;
        holder = temp;
        temp = temp_next;
    }

    head = holder;

}


Node * kReverse(Node *head, int k){

  
    Node *temp = head;
    Node *holder = NULL;
    Node *temp_next;
    int cnt = 1;

    while(temp != NULL && cnt <= k){
        temp_next = temp->next;
        temp->next = holder;
        holder = temp;
        temp = temp_next;
        cnt++;
    }

    if(temp != NULL){ 
        head->next = kReverse(temp, k);
    }

    return holder;

}

int main()
{ 
    insert(10);

    cout << head->data << endl;

    // insertAt(0, 12);
    // insertAt(3,400);
    head = kReverse(head,3);
    while(head != NULL){
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;


    return 0;
}