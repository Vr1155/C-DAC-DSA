#include<stdio.h>
#include<string.h>

long long fibo(long long num){
	if (num <= 1){
		return num;
	}
	return fibo(num-1) + fibo(num-2); 
}

void main(){
	long long num;
	printf("Enter the n-th term till were you want to generate fibonacci series:\n");
	scanf("%ld", &num);
	printf("Fibonacci series is as follows:\n");
	for(int i=0; i<num; i++){
		printf("%d ----> %d\n", i+1, fibo(i));
	}
}
