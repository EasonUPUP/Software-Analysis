#include <klee/klee.h>
#include <stdio.h>
#include <string.h>

typedef struct Student
{
   char  name[50];
   int   age;
   char  sex[100];
} Stu;

int main( )
{
   Stu p1;
   klee_make_symbolic(&p1.age, sizeof(p1.age), "p1.age");
   printf( "Student age : %d\n", p1.age);

   if (p1.age > 10){
   Stu p2;
   klee_make_symbolic(&p2.age, sizeof(p2.age), "p2.age");
   printf( "Student age : %d\n", p2.age);
   }
   return 0;
}