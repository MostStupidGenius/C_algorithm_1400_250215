// node.h
#include <stdlib.h> // 동적 메모리 할당
// 헤더 가드 시작
// 중복 포함 방지를 위한 헤더 가드
#ifndef NODE_H
#define NODE_H

// 노드 구조체 정의
typedef struct Node {
	int data; // 데이터 필드
	struct Node* next; // 다음 노드를 가리키는 포인터
} Node; // 구조체에 "Node"라는 별칭(alias)을 부여하여
// struct Node 대신에 Node라고만 쓸 수 있도록 변경

// 노드라는 구조체를 다룰 함수들의 원형 선언
// 노드 생성
// 반환은 Node 타입, 입력은 int data
Node* createNode(int data);

// 노드 삽입
// 헤드 노드(head)와 data를 전달받는다.
// 이때 헤드 노드는 연결 리스트의 첫번째 노드의 포인터를 담은
// Node** head, int data
// data값을 담은 새로운 노드를 만들어 연결 리스트의
// 마지막에 추가
void appendNode(Node* head, int data);

// 노드 삭제
// 전달된 data를 보유한 노드를 찾아서 삭제
void deleteNode(Node* head, int data);

// 위에서 선언한 함수들 정의
// 새로운 노드 생성 함수
Node* createNode(int data) {
	// 동적 메모리 할당을 통해 새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));

	// 생성 실패 시 NULL 반환
	if (newNode == NULL) return NULL;
	//printf("data: %d\n", data);
	// 새로운 노드에 data를 저장하고
	newNode->data = data;
	// 다음 노드를 가리키는 포인터, next를 NULL로 초기화
	newNode->next = NULL;

	// 새로운 노드를 반환
	return newNode;
}

// 연결리스트의 특정 노드와 새로운 데이터를 전달하여
// 내부에서 새로운 노드를 생성하고
// 새로운 노드를 가장 마지막 노드의 다음 포인터로 지정하여
// 연결리스트의 요소로 추가.
void appendNode(Node* head, int data) {

	// 전달받은 head가 널이면 그대로 함수 종료
	if (head == NULL) return;

	Node* currentNode = head;

	// 조건과 무관하게 일단 진입
	do {
		// 현재 보고 있는 노드의 다음 요소 주소가
		// NULL인지 확인한다(다음 요소가 없으면
		// 그곳에 새로운 노드를 추가)
		Node* next = currentNode->next;
		if (next == NULL) break; // 반복문 탈출
		// 다음 노드가 있다면 그 노드를 currentNode에 저장
		currentNode = next;

	} while (currentNode->next != NULL);

	// 짧게 쓰면 세 줄
	//while (currentNode->next != NULL) {
	//	currentNode = currentNode->next;
	//}

	// currentNode의 next는 NULL인 상태
	// 새로운 노드 생성 및 초기화
	Node* newNode = createNode(data);

	// 새로운 노드의 주소를 currentNode의 next에 저장하여
	// 연결리스트에 편입시킨다.
	currentNode->next = newNode;
}

// 전달받은 data를 가진 노드 중,
// 가장 먼저 만나는 노드를 삭제하고
// 해당 노드 앞뒤 노드를 연결시킨다.
void deleteNode(Node* head, int data) {
	if (head == NULL) return;
	Node* current = head;
	Node* prev = NULL;

	while (1) {
	//while(current->data != data){
		// 현재 노드의 데이터와 전달받은 데이터가
		// 같은지 확인하여
		// 같으면 반복문 탈출
		if (current->data == data) {
			break;
		}

		// 현재 노드의 데이터와 불일치하는데,
		// 다음 노드가 존재하지 않는다면
		// 지금까지 일치하는 데이터를 찾지 못한 것이므로
		// 함수를 종료한다.
		if (current->next == NULL) {
			return; // 함수 탈출(종료)
		}
		prev = current;
		current = current->next;
	}

	// while문 종료는 데이터를 가진 노드를 찾았음을 의미한다.
	// 해당 노드의 이전 노드가 가리키는 next를
	// 현재 노드가 가리키는 next로 바꿔야 한다.

	// 만약 head의 data가 전달받은 data와 일치한다면
	// 이전 노드 prev가 NULL일 것이므로
	// 현재 노드를 메모리 할당 해제만 해주면 된다.
	if (prev == NULL) {
		free(current);
		return;
	}
	else if (current->next == NULL) {
		// 현재 노드가 가리키는 노드가 없다면
		// 현재 노드만 이전 노드에서 제거하고
		// 메모리 할당 해제해주면 된다.
		prev->next = NULL; // 이전 노드의 next를 NULL로
		free(current);
		return;
	}

	// 이전 노드도 존재하고 다음 노드도 존재하는 경우
	// 두 노드를 연결시키기 위해서
	// 이전 노드의 next 값에 현재 노드의 next 값을 집어넣어야 한다.
	prev->next = current->next;
	// 이전 노드는 더이상 현재 노드를 가리키지 않기 때문에
	// 메모리 할당 해제를 해주면 끝난다.
	free(current);
	return;
}
#endif // !NODE_H