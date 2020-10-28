#include <klee/klee.h>
#include <stdio.h>
int *sum(int a,int b);
int pointerTest (int a);

int pointerTest (int a){
   int  var;
   int  *ptr;
   int  **pptr;

   var = 1996;

   // get var address
   ptr = &var;
   pptr = &ptr;
   if (a < 0){
     	printf("Value of var = %d\n", var );
   }

   if (a == 0){
   		printf("Value available at *ptr = %d\n", *ptr );
   }

   if (a > 0){
   		printf("Value available at **pptr = %d\n", **pptr);
   }

   return 0;
}

int *sum(int a,int b){
	static int sum=0;
	sum=a+b;

	return &sum;
}

int main(){
	int a;
	klee_make_symbolic(&a, sizeof(a), "a");
	pointerTest(a);
	int b;
	klee_make_symbolic(&b, sizeof(b), "b");
  int *p = sum(a, b);
  return 0;
}
