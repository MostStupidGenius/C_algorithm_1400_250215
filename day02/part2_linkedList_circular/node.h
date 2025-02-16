// node.h
#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->next = newNode;
	return newNode;
}

// 원형 연결 리스트에 노드 삽입
// 원형 연결 리스트의 기준이 될 head 노드의 주소를 담은 변수를 전달받아
// 그 노드를 next로 가진 노드의 뒤에 새로운 노드를 삽입해야 한다.
void insertNode(Node** head, int data) {
	// 새로운 노드 생성
	Node* newNode = createNode(data);

	// 전달받은 헤드가 비어 있다면
	if (*head == NULL) {
		// 새로운 노드의 주소를 헤드 변수에 저장하고
		*head = newNode;
		// 해당 노드의 다음 노드를 가리키는 next를 스스로로 지정한다.
		newNode->next = *head;
	}
	else {
		// 전달받은 헤드 주소 변수의 노드를 임시 변수에 담는다.
		Node* temp = *head;

		// 노드의 다음 요소가 head에 담긴 노드 주소가 아니라면
		// 계속 반복
		// 마지막 노드를 찾기 위한 반복문
		while (temp->next != *head) {
			// 만약 temp의 다음 노드가 NULL이라면
			// (temp가 head이면서 다음 노드가 NULL)
			//if (temp->next == NULL) break;
			temp = temp->next;
		}
		
		// while문을 탈출했다면 temp 노드의 다음 요소는 head 노드인 것이므로
		// 현재 노드temp의 다음 노드로 새로운 노드를 저장하면 된다.
		temp->next = newNode;

		// 현재 헤드를 새로운 노드의 다음 노드로 설정
		newNode->next = *head;
	}
}

// 노드의 삭제
void deleteNode(Node** head, int data) {
	// 만약 전달된 head 이중 포인터의 주소가 null이라면
	// 함수 종료
	if (*head == NULL) return;

	Node* current = *head, * prev = NULL;
	// 현재 노드의 데이터가 전달받은 데이터와 다르다면
	// 반복적으로 다음 노드로 넘어간다.
	while (current->data != data) {
		// 만약 현재 노드가 가리키는 다음 노드가
		// head의 노드와 같다면
		if (current->next == *head) {
			// 한 바퀴는 순회한 것이므로, 원하는 데이터를
			// 찾지 못한 것이다.
			printf("노드를 찾을 수 없습니다.");
			return;
		}
		// 이전 노드를 가리키는 변수에 현재 노드 주소값 담기
		prev = current;
		// 현재 변수에 다음 노드 주소값 담기
		current = current->next;
		// 다음 반복 준비
	}
	
	// 만약에 다음 노드가 head이고 이전 노드가 비어있다면
	// 원형 연결 리스트에 담긴 노드가 head에 담긴 노드 하나뿐이므로
	// 헤드를 비우고 현재 노드를 메모리 할당 해제해 주어야 한다.
	if (current->next == *head && prev == NULL) {
		*head = NULL;
		free(current);
		return;
	}

	// 만약 현재 노드가 헤드의 노드와 같다면
	if (current == *head) {
		// 이전 노드 변수에 헤드 노드를 담고
		prev = *head;

		// prev의 next가 head가 아닌 동안
		while (prev->next != *head) {
			// prev의 next를 prev에 담는다.
			prev = prev->next;
		}

		// head의 주소를 현재 노드의 다음 노드로 바꿔준다.
		*head = current->next;
		// prev의 next를 current의 next로 바꿔준다.
		prev->next = *head;
		free(current);
	}
	// head가 현재 노드와 다르다면
	else {
		// 앞의 노드의 next에 지우려는 노드의 next 값을 넣어준다.
		prev->next = current->next;
		free(current);
	}
}
#endif // !NODE_H
