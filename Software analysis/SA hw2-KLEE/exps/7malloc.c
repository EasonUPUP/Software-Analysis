#include <klee/klee.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allmemory(char name[]){
   char *description;
   strcpy(name, "asdfsdfdsgsdasdasddfdgjsdiofjsaiojfsadiojfosaijgfdsds");

   description = (char *)malloc( 200 * sizeof(char) );
   if( description == NULL ){
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }else{
      strcpy( description, "allocated required memory");
   }

   printf("Name = %s\n", name );
   printf("Description: %s\n", description );
}

int main()
{
   int size;
   klee_make_symbolic(&size, sizeof(size), "size");
   if (size > 10){ // imporant to save for testing
   char name[size];
   klee_make_symbolic(name, sizeof name, "name");
   klee_assume(name[size-1] == '\0');
   allmemory(name);}
   return 0;
}