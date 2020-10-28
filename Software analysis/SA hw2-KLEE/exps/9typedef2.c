#include <stdio.h>
#include <klee/klee.h>

typedef char (*PTR_TO_ARR)[30];
typedef int (*PTR_TO_FUNC)(int, int);

char str[3][30] = {
    "Java",
    "C++",
    "C-Language"
};

int main(){
    PTR_TO_ARR parr = str;
    printf("str[%d]: %s\n", 1, *(parr+1));
    int i;
    klee_make_symbolic(&i, sizeof(i), "i");
    klee_assume(i ==1 || i ==2 || i==3);
    printf("str[%d]: %s\n", i, *(parr+i));
    return 0;
}