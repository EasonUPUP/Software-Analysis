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
    PTR_TO_ARR parr ;
    klee_make_symbolic(parr, sizeof(parr), "parr");
    int i;
    char[30] str1 = *(parr+i);
    return 0;
}