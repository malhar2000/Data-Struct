#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

int main( ){
    struct Node *head0 =  (struct Node *) malloc(sizeof(struct Node));
    struct Node *head1 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *head2= (struct Node *) malloc(sizeof(struct Node));
    struct Node *head3= (struct Node *) malloc(sizeof(struct Node));


    head0->val = 1;
    head0->next = head1;
    head1->val = 2;
    head1->next = head2;
    head2->val = 3;
    head2->next = head3;
    head3->val = 4;
    head3->next = NULL;

    struct Node *head01 =  (struct Node *) malloc(sizeof(struct Node));
    struct Node *head11 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *head21= (struct Node *) malloc(sizeof(struct Node));
    struct Node *head31= (struct Node *) malloc(sizeof(struct Node));


    head01->val = 1;
    head01->next = head1;
    head11->val = 3;
    head11->next = head2;
    head21->val = 3;
    head21->next = head3;
    head31->val = 3;
    head31->next = NULL;


    struct Node *temp = head0;

    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}