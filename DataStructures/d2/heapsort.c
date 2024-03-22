#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void heapSort(int* arr, int n);
int heapify(int* arr, int n, int i);
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

	heapSort(arr, NUM);

	printf("After sorting:\n");
	printArr(arr, NUM);

}

void heapSort(int *arr, int n){
	for(int i = n/2 -1; i>=0; i--){
		heapify(arr, n, i);
	}

	for(int i=n-1; i>=0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int heapify(int* arr, int n, int i){
	int largest = i;
	
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}

	if(largest != i){
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}
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
