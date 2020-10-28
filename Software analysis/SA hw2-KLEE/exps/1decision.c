#include <klee/klee.h>
#include <stdio.h>

void intToDate(int a)
{
    printf("input integer number: ");
    
    switch(a)
    {
        case 1:printf("Monday\n");
        break;
        case 2:printf("Tuesday\n");
        break;
        case 3:printf("Wednesday\n");
        break;
        case 4:printf("Thursday\n");
        break;
        case 5:printf("Friday\n");
        break;
        case 6:printf("Saturday\n");
        break;
        case 7:printf("Sunday\n");
        break;
        default:printf("error\n");
    }
}

int main(){
	int a;
	klee_make_symbolic(&a, sizeof(a), "a");
    intToDate(a);
    return 0;
}


