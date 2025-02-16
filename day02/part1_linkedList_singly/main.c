#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
// 사용자 정의 헤더 포함
#include "node.h" // 큰따옴표로 파일을 가리켜야 한다.
//#include <node.h> // 기본 헤더가 아니므로 꺾쇠로는
// 포함 불가

	// 외부로부터 순회하고자 하는 연결리스트의
	// 첫번째 노드 주소를 가리키는 이중포인터를 전달받아
void printLinkedList(Node* head) {
	// 그 이중포인터가 가리키는 주소를 current로 담고
	Node* current = head;
	// 현재 노드가 NULL이 아니라면 연결리스트 순회
	while (current != NULL) {
		// 현재 노드의 데이터를 출력하고
		printf("%d -> ", current->data);

		// 다음 노드를 현재 노드 변수에 담아서 이어서 진행
		current = current->next;
	}
	// 마지막은 null을 가리키므로 NULL을 출력
	printf("NULL\n");
}

int main() {
	Node* head = createNode(10);
	appendNode(head, 20);
	appendNode(head, 30);
	appendNode(head, 40);
	appendNode(head, 45);
	appendNode(head, 50);

	// 연결 리스트의 데이터들 출력
	printLinkedList(head);
	
	// 노드의 삭제
	// 45값을 data에 보유한 노드를 제거
	deleteNode(head, 45);
	printLinkedList(head);

	return 0;
}