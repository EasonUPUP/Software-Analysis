#include <klee/klee.h>
#include <stdio.h>
int getmax(int num1, int num2);

int main ()
{
   int a;
   int b;
   klee_make_symbolic(&a, sizeof(a), "a");
   klee_make_symbolic(&b, sizeof(b), "b");

   return getmax(a, b);
}

int getmax(int num1, int num2)
{
   if (num1 > num2)
      return num1;
   else
      return num2;
}