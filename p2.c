// p2.c
// include needed headerfiles here
// ...
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// return a list containing nodes with data n-1,n-2,...2,1,0
// check for any preconditions
struct Node *create(int n)
{ 
    n--;
    if (head == NULL)
        {
            head = malloc(sizeof(struct Node *));
            head->data = n;
            head->next = NULL;
            n--; 
        }
        
    while (n >= 0)
    {  
        struct Node *temp = malloc(sizeof(struct Node*));
        temp->data = n;
        temp->next = head;
        head = temp;
        n--;
    }

    return head;
}

// deallocate list by freeing all nodes in list starting with node
void deallocate(struct Node *node)
{
    // ...
    struct Node *prev;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
        free(prev);
    }
}

// print list
void print(struct Node *node)
{
    struct Node *temp = node;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        // print(node->next);
        temp = temp->next;
    }
}

int main()
{
    // test code
    create(10);
    
    print(head);

    deallocate(head);

    // check whether above functions work by creating a list and printing it

    // also use valgrind for detecting memory leaks

    // ...

    return 0;
}