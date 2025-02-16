#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "node.h"

void printLinkedList(Node** head) {
	// 그 이중포인터가 가리키는 주소를 current로 담고
	Node* current = *head;
	// 현재 노드가 NULL이 아니라면 연결리스트 순회
	while (current != NULL) {
		// 현재 노드의 데이터를 출력하고
		printf("%d -> ", current->data);

		if (current->next == *head) break;

		// 다음 노드를 현재 노드 변수에 담아서 이어서 진행
		current = current->next;
	}
	// 마지막은 null을 가리키므로 NULL을 출력
	printf("head\n");
}


int main() {
	// 원형 연결 리스트의 초기화
	Node* head = createNode(10);

	// 노드 추가
	insertNode(&head, 20);
	insertNode(&head, 30);
	insertNode(&head, 35);
	insertNode(&head, 40);
	printLinkedList(&head);

	// 노드 삭제
	deleteNode(&head, 35);

	printLinkedList(&head);


	return 0;
}