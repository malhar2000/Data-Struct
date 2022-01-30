#include "Stack.h"

int main(){
    struct Stack arr;
    
    arr.size = 5;
    arr.S = malloc(5*sizeof(int));
    arr.top = -1;
    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30);
    push(&arr, 40);

    printf("Peek at position 3: %d\n", peek(arr, 3));
    Display(arr);
}