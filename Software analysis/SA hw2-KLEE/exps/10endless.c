#include <klee/klee.h>
#include <stdio.h>
int main(){
        int a;
        klee_make_symbolic(&a, sizeof(a), "a");
        while(1){
                a--;
                if (a < 10){
                        a++;
                }
        }
        return 0;
}