#include <stdio.h>
#include <stdlib.h>


struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st);
void Display(struct Stack st);
void push(struct Stack *st, int x);
int pop(struct Stack *st);
int peek(struct Stack st, int index);
int isFull(struct Stack st);
int stackTop(struct Stack st);

//-----------------------------------Stack with LinkList
struct Node
{
    int data;
    struct Node *next;
};


void pushL(int x);
int popL();
void DisplayL();