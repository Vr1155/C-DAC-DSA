#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void selectionSort(int *arr, int size);
void printArr(int*, int);
void fillArr(int*, int);


void main(){
	// using random number function to store values randomly.
	srand(time(NULL));
	int arr[NUM];
	fillArr(arr, NUM);
	printf("Before sorting:\n");
	printArr(arr, NUM);

	selectionSort(arr, NUM);

	printf("After sorting:\n");
	printArr(arr, NUM);

}

void selectionSort(int *arr, int size){
	printf("Inside selection sort function...\n");
	int temp;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i]>arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Exiting selection sort function!\n");
}

void printArr(int* arr, int size){
	int cnt;
	for(cnt=0; cnt<size; ++cnt){
		printf("%d ", arr[cnt]);
	}
	printf("\n");
}

void fillArr(int* arr, int size){
	int cnt;
	for(cnt=0; cnt<size; cnt++){
		arr[cnt] = rand() % (NUM*10);
	}
}

