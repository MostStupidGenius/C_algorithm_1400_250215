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
	// 전달받은 head 노드가 비어있다면 새로운 노드를 만들어서 반환한다.
	if (head == NULL) {
		struct Node* newNode = cNode(data);
		return newNode;
	}
	// 내부에서 주어진 조건에 따라 반복문이 종료된다.
	// head부터 그 자식노드들이 있는지를 검사하고
	// 랜덤값에 따라, 그 부분에 새로운 newNode의 주소를 삽입한다.
	// 재귀함수 방식으로 순차적 탐색

	// 만약 랜덤값이 짝수라면 왼쪽에 데이터 삽입
	if (rand() % 2 == 0) {
		head->left = insertNode(head->left, data);
	}
	// 랜덤값이 홀수라면 오른쪽에 데이터 삽입
	else {
		head->right = insertNode(head->right, data);
	}

	return head;
}

// 노드의 순회
// 중위 순회
// : 왼쪽 자식 노드를 탐색한 뒤,
// 값을 출력하고 그 뒤에 오른쪽 자식 노드를 탐색한다
void inorderTrav(struct Node* root) {
	// 전달받은 노드가 비어있지 않은 경우에만 data 출력
	if (root != NULL) {
		// 재귀적으로 함수 호출
		// 왼쪽 자식 노드의 트리를 재귀적으로 탐색 및 출력
		inorderTrav(root->left);
		// 현재 보고 있는 노드의 값을 출력
		printf("%d ", root->data);
		// 오른쪽 자식 노드의 트리를 재귀적으로 탐색 및 출력
		inorderTrav(root->right);
	}
}







#endif // !NODE_H