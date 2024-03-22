#include<stdio.h>

void recur(int);

int main(){
	recur(1);
	printf("\n");
}

void recur(int num){
	if(num<=5){
		printf("%d ", num);
		recur(num+1);
		printf("%d ", num);
	}
}

// this function will print 1 2 3 4 5 5 4 3 2 1
// Notice that we are not using a loop,
// to iterate through the numbers.
// Instead we are using recursion to call the same
// function again and again.

// Important to notice 3 important things:
// 1. we are initializing the number in the first recursive call.
// 2. we are also incrementing the number in the function argument of each recursive call
// 3. There is a terminating condition that stops the recursion.

// If you observe closely, you can see the similarities with the for and while loops.

