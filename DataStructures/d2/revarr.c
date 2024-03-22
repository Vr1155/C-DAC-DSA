#include<stdio.h>

void revarr(int* arr, int first, int last);

void main(){
	int size;
	printf("Enter the size of an array:\n");
	scanf("%d", &size);
	int arr[size];
	printf("Enter value of each array element:\n");
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	printf("\nArray before reversing:\n");
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\nArray after reversing:\n");
	
	revarr(arr, 0, size-1);
	
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

}

void revarr(int* arr, int first, int last){
	if(first >= last)
		return;

	arr[first] ^= arr[last];
	arr[last] ^= arr[first];
	arr[first] ^= arr[last];
	
	revarr(arr, first+1, last-1);
	return;
}
