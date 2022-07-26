#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 

int main( ){
 
   int rows = 3;
char **c = calloc (rows,sizeof(char*));
c[0] = "cat";
c[1] = "dog";
c[2] = "mouse";

   
   
    

   printf( "%s ", c);
}