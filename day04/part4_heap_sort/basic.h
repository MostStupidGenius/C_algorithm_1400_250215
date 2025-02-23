// basic.h
#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>

void printArr(int arr[], int size) {
	printf("{");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("}\n");
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}



#endif // !NODE_H