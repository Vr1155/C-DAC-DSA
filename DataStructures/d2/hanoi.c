#include<stdio.h>

void hanoi(long long no_of_disks, int from_rod, int to_rod, int aux_rod);

void main(){
	long long n;
	printf("Enter the number of disks!\n");
	scanf("%ld", &n);
	int from_rod = 1, to_rod = 3, aux_rod = 2;

	hanoi(n, from_rod, to_rod, aux_rod);
}

void hanoi(long long n, int from_rod, int to_rod, int aux_rod){
	if(n == 0){
		return;
	}

	hanoi(n-1, from_rod, aux_rod, to_rod);
	printf("Move disk %ld from rod %d to rod %d\n", n, from_rod, to_rod);
	hanoi(n-1, aux_rod, to_rod, from_rod);
}
