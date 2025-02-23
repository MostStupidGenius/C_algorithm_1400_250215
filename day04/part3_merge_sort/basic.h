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

#endif // !NODE_H