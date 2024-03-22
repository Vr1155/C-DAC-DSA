#include<stdio.h>
#include<string.h>

long long fibo(long long num){
	if (num == 1){
		return 0;
	}
	else if(num == 2) {
		return 1;
	}
	long long ans = fibo(num-1) + fibo(num-2);
	return ans;
}

void main(){
	long long num;
	printf("Enter the n-th term till were you want to generate fibonacci series:\n");
	scanf("%ld", &num);
	printf("Fibonacci series is as follows:\n");
	long long ans = fibo(num);
	printf("%ld\n", ans);
}
