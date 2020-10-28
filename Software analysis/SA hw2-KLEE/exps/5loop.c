#include <klee/klee.h>
#include <stdio.h>
int main(){
	int a;
	klee_make_symbolic(&a, sizeof(a), "a");
	for (int i = 0; i < 1000; i++){
		a = a*(-1);
		if (a < 0){
			a++;
		}
	}
	return 0;
}