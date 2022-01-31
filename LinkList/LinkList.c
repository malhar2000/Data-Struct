#include "H1.h"

struct Node *head = NULL;

void insert(int x, int pos){
    struct Node *temp;
    struct Node *p = head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if(p == NULL){
        temp->next = p;
        head = temp;
    }
    else{
        int i = 0;
        while(i < pos-1){
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void display(){
    struct Node *p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p ->next;
    }
}

int delete(int pos){
    struct Node *p = head;
    struct Node *temp ;
    int i = 0;
    int x;
    if(pos == 0){
        head = p->next;
        x = p -> data;
        free(p);
        return x;
    }
    while(i < pos && p->next != NULL){
        temp = p;
        p = p->next;
        i++;
    }
    x = p->data;
    temp->next = p->next;
    free(p);
    return x;
}
int main(){
    insert(10, 0);
    insert(20, 1);
    insert(50, 2);
    insert(30, 3);
    insert(40, 4);
    insert(100, 3);
    int x = delete(1);
    x = delete(0);
    x = delete(4);
    printf("%d\n", x);
    display();
}