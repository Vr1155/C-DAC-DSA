#include<stdio.h>

// preprocessor directives that can be set by CLI
#ifndef NUM
#define NUM 100
#endif

void printArr(int* , int);
void fillArr(int* , int);

int main(){
	int arr[NUM] = {0}; // partial initialization
	printArr(arr, NUM);
	printf("Enter the first value: ");
	scanf("%d", &arr[0]);
	fillArr(arr, NUM);
	printArr(arr, NUM);
}

void fillArr(int *arr, int size){
	int cnt;
	for(cnt = 1; cnt < size; ++cnt){
		arr[cnt] = arr[0] + cnt;
	}
}

void printArr(int* arr, int size){
	int cnt;
	for(cnt = 0; cnt < size; ++cnt){
		printf("%d ", arr[cnt]);
	}
	printf("\n");
}
