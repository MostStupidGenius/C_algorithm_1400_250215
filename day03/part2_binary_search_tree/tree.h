// basic.h
#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>

// 비선형 자료구조
// - 이진 트리(Binary Tree)
// 계층 구조를 기반으로 한 트리 구조로, 부모노드가 최대 두 개의
// 자식노드만 가질 수 있는 트리 구조를 이진 트리라고 부른다.

// 이진 트리 노드 구조체 정의
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// 이진 트리의 노드에 데이터를 넣은 노드를 반환하는 함수 - 생성자
struct Node* cNode(int data) {
	// 반환할 노드를 먼저 선언 및 동적 할당
	struct Node* result = (struct Node*)malloc(sizeof(struct Node));
	if (result == NULL) return NULL;

	result->data = data;
	// 자식노드들은 안전하게 널값으로 포인터 값을 지정해놓는다.
	result->right = NULL;
	result->left = NULL;
	return result;
}

struct Node* insertNode(struct Node* head, int data) {
	// 만약 head가 NULL이라면 새로운 노드를 생성하여 반환
	if (head == NULL) return cNode(data);

	// 만약 전달받은 데이터가 head의 데이터보다 작다면
	// 왼쪽 노드를 기준으로 한 재귀함수를 호출
	if (data < head->data) {
		head->left = insertNode(head->left, data);
	}
	else if (data > head->data) {
		head->right = insertNode(head->right, data);
	}
	return head;
}

// 트리 순회
// 전위 순회
// 데이터를 먼저 출력한 뒤, 왼쪽 트리, 오른쪽 트리를 순회하는 방법이다.
void preorder(struct Node* root) {
	if (root != NULL) {
		// root가 NULL이 아니라면 순회
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

#endif // !NODE_H