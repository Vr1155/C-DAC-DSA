#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef NUM
#define NUM 10
#endif


void mergeSort(int *arr, int l, int r, int size);
void printArr(int*, int);
void fillArr(int*, int);
void merge(int* arr, int l, int m, int r, int size);

void main(){
	// using random number function to store values randomly.
	srand(time(NULL));
	int arr[NUM];
	fillArr(arr, NUM);
	printf("Before sorting:\n");
	printArr(arr, NUM);

	mergeSort(arr, 0, NUM-1, NUM);

	printf("After sorting:\n");
	printArr(arr, NUM);

}

void mergeSort(int *arr, int l, int r,  int size){
	if(l < r){
		int m = l + (r-l)/2;
		mergeSort(arr, l, m, size);
		mergeSort(arr, m+1, r, size);
		merge(arr, l, m, r, size);
	}
}

void merge(int* arr, int l, int m, int r, int size){
	int x = m - l +1;
	int y = r - m;

	int arr1[x];
	int arr2[y];

	for(int i=0; i<x; i++){
		arr1[i] = arr[l+i];
	}

	for(int i=0; i<y; i++){
		arr2[i] = arr[m+1+i];
	}

	int i = 0, j = 0, k = l;

	while(i<x && j<y){
		if(arr1[i] < arr2[j]){
			arr[k] = arr1[i];
			i++;
			k++;
		}
		else{
			arr[k] = arr2[j];
			j++;
			k++;
		}
	}

	while(i<x){
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while(j<y){
		arr[k] = arr2[j];
		j++;
		k++;
	}
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
