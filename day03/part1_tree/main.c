#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "tree.h"

typedef struct Node Node;

int main() {
	Node* head = cNode(1);
	//head->left = cNode(2);
	//head->right = cNode(3);
	int arr[] = { 2, 3, 4, 5, 6, 7 };

	for (int i = 0; i < 6; i++) {
		insertNode(head, arr[i]);
	}

	inorderTrav(head);

	return 0;
}