#include "Stack.h"

struct Node *link_Top = NULL;
void pushL(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = link_Top;
        link_Top = t;
    }
}

int popL()
{
    struct Node *t;
    int x = -1;
    if (link_Top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = link_Top;
        link_Top = link_Top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void DisplayL()
{
    struct Node *p;
    p = link_Top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
