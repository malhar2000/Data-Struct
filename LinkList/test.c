#include <stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
}; 
 

void insert(struct Node **head, int data){
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    
    if(head==NULL){
        *head = malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }else{
        temp->next = *head;
        *head = temp;
        
    }

}

int main(){
    struct Node *head = NULL;
     
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("Done!\n");
}