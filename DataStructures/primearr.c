#include<stdio.h>
#include<math.h>

// preprocessor directives that can be set by CLI
#ifndef NUM
#define NUM 100
#endif

void printArr(int* , int);
void fillArr(int* , int);
int isPrime(int);
void processArr(int* arr, int size);


int main(){
	int arr[NUM] = {0}; // partial initialization
	printArr(arr, NUM);
	printf("Enter the first value:\n");
	scanf("%d", &arr[0]);
	fillArr(arr, NUM);
	printArr(arr, NUM);

	// retain only prime numbers in that array:
	printf("Retaining only prime numbers:\n");
	processArr(arr, NUM);
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

int isPrime(int num){
	int sq_rt = sqrt(num);

	for(int i=2; i<=sq_rt; i++){
		if(num%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void processArr(int* arr, int size){
	for(int i = 0; i<size; i++){
		if( isPrime(arr[i]) == 0 ){
			arr[i] = 0;
		}
	}
}

