#include<stdio.h>

long long power(long long base, long long expo){
	if(expo == 0){
		return 1;
	}
	return base*power(base, expo-1);
}

void main(){
	long long base, expo;
	printf("Enter the base and the exponent (both non-negative integer):\n");
	scanf("%ld %ld", &base, &expo);

	printf("%ld raised to %ld is %ld\n", base, expo, power(base, expo));
}
