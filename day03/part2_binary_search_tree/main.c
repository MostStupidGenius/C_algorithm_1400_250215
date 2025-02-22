#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "tree.h"

typedef struct Node Node;

int main() {
	Node* head = cNode(5);
	int arr[] = { 8, 3, 6, 1, 2, 4, 9, 7};
	for (int i = 0; i < 8; i++){
		head = insertNode(head, arr[i]);
	}

	preorder(head);
	//inorder(head);
	//postorder(head);



	return 0;
}