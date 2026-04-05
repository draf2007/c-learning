#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int a,b,t1,t2;
	printf("Input\n");
	scanf("%d %d", &a, &b);
	
	t1=a;
	t2=b;
	
	while (t2 != 0){
		int tmp = t2;
		t2 = t1 % t2;
		t1=tmp;
	}
    
    printf ("%d", t1);
    
	return 0;
}