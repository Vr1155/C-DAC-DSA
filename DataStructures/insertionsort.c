#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void insertionSort(int *arr, int size);
void printArr(int*, int);
void fillArr(int*, int);


void main(){
	// using random number function to store values randomly.
	srand(time(NULL));
	int arr[NUM];
	fillArr(arr, NUM);
	printf("Before sorting:\n");
	printArr(arr, NUM);

	insertionSort(arr, NUM);

	printf("After sorting:\n");
	printArr(arr, NUM);
}

void insertionSort(int *arr, int size){
	printf("Inside insertion sort function...\n");
	
	for(int i = 1; i<size; i++){
		int j = i-1;
		int elem = arr[i];
		
		while(j>=0 && elem < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = elem;
	}

	printf("Exiting insertion sort function!\n");
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

