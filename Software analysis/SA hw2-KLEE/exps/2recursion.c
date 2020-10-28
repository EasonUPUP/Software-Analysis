#include <klee/klee.h>
#include <stdio.h>
 
int fibonaci(int i)
{
   if(i == 0){
      return 0;
   }
   if(i == 1){
      return 1;
   }
   
   return fibonaci(i-1) + fibonaci(i-2);
}
 
int  main()
{
    int a;
    klee_make_symbolic(&a, sizeof(a), "a");
    if (a > 10){
    	return 0;
    }
    printf("%d\t\n", fibonaci(a));
    
    return 0;
}