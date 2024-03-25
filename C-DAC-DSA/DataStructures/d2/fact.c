#include<stdio.h>

long long fact(long long f){
	if(f <= 1){
		return 1;
	}
	return f*fact(f-1);
}

void main(){
	long long f;
	printf("Enter a number for finding factorial:\n");
	scanf("%ld", &f);

	printf("Factorial of %ld is %ld\n", f, fact(f));
}
