#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void quickSort(int* arr, int l, int r);
int partition(int* arr, int l, int r);
void swap(int* a, int* b);
void printArr(int*, int);
void fillArr(int*, int);

void main(){
	// using random number function to store values randomly.
	srand(time(NULL));
	int arr[NUM];
	fillArr(arr, NUM);
	printf("Before sorting:\n");
	printArr(arr, NUM);

	quickSort(arr, 0, NUM-1);

	printf("After sorting:\n");
	printArr(arr, NUM);

}

void quickSort(int *arr, int l, int r){
	if(l < r){
		int pivot = partition(arr, l, r);
		quickSort(arr, l, pivot-1);
		quickSort(arr, pivot+1, r);
	}
}

int partition(int* arr, int l, int r){
	int pivot = arr[r];
	
	int i = l-1;
	for(int j = l; j <=r; j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i], &arr[j]);	
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
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
