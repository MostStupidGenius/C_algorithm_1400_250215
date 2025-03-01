#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// 가변길이 큐 구현
// 원리: 구조체 내부에서 새로운 값이 추가되거나 삭제될 때마다
// 그 길이에 맞춘 새로운 배열을 생성하여 이전 요소를 넣고
// 구조체 내부에서 배열의 길이를 관리하는 방식으로
// 가변 길이 큐를 구현할 수 있다.

typedef struct {
	int* data;
	int length;
} Queue;

// 큐 초기화 함수
void initQueue(Queue* queue) {
	queue->data = NULL;
	queue->length = 0;
}

// 비어있는지 여부 확인 함수
bool isEmpty(Queue* queue) {
	return queue->data == NULL;
}

// 새로운 데이터 삽입
void enqueue(Queue* queue, int value) {
	// data가 NULL인지 검사
	if (isEmpty(queue)) {
		// 길이를 1로 설정하고
		queue->length = 1;
		// 그 길이만큼의 요소를 넣을 배열을 생성
		int* arr = (int*)malloc(sizeof(int) * queue->length);
		if (arr == NULL) return;
		// 만들어진 배열을 data에 삽입
		queue->data = arr;
		// data의 0번째 값으로 전달받은 value의 값을 저장
		queue->data[0] = value;
		return;
	}

	// 기존에 배열이 있다면
	// 동적 할당을 통해 새로운 배열 생성
	int newSize = queue->length + 1;
	int* arr = (int*)malloc(sizeof(queue->data[0]) * newSize);
	if (arr == NULL)return;
	for (int i = 0; i < queue->length; i++) {
		arr[i] = queue->data[i];
	}

	// 마지막 요소로 새로운 값을 삽입
	arr[queue->length] = value;

	// 기존 값을 모두 옮기고 난 뒤, 큐의 길이를 1증가
	queue->length++;

	// 기존에 담겨 있던 동적 할당을 할당해제 해준다.
	free(queue->data);

	// 큐의 배열을 새로운 배열로 바꾼다.
	queue->data = arr;
}
// 0번째 요소 제거 및 반환
bool dequeue(Queue* queue, int* value) {
	// 비어 있으면
	if (isEmpty(queue)) {
		printf("큐가 비어있습니다.\n");
		return false;
	}

	// 마지막 요소를 길이를 이용해 가져와 value에 담는다.
	*value = queue->data[0];

	// 큐의 길이를 1 줄인다.
	queue->length--;

	// 길이가 하나 줄어든 새로운 배열을 동적 할당
	int* newArr = (int*)malloc(sizeof(int) * queue->length);
	if (newArr == NULL) return false;

	// 기존 배열의 요소들을 새로운 배열에 삽입
	for (int i = 0; i < queue->length; i++) {
		newArr[i] = queue->data[i+1];
	}

	// 기존 데이터 배열 할당 해제
	free(queue->data);

	// 새로운 데이터 배열을 큐에 삽입
	queue->data = newArr;

	// 정상 종료
	return true;
}

// 0번째 요소 반환
int peek(Queue* queue, int* value) {
	// 비어 있으면
	if (isEmpty(queue)) {
		printf("큐가 비어있습니다.\n");
		return false;
	}

	// 마지막 요소를 길이를 이용해 가져와 value에 담는다.
	*value = queue->data[0];

	// 정상 종료
	return true;
}
// 큐의 모든 요소를 출력하는 함수
void displayQueue(Queue* queue) {
	printf("element: ");
	for (int i = 0; i < queue->length; i++) {
		printf("%d ", queue->data[i]);
	}
	printf("\n");
}

int main() {
	// 가변 길이 큐
	Queue queue;
	int value;

	// 큐 초기화
	initQueue(&queue);

	// 큐 데이터 삽입
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);
	dequeue(&queue, &value);
	enqueue(&queue, 50);

	// 큐의 전체 출력
	displayQueue(&queue);

	// 큐의 먼저 나갈 데이터를 확인
	peek(&queue, &value);
	printf("0번째 요소: %d\n", value);

	// 요소의 제거 및 반환
	dequeue(&queue, &value);
	printf("추출한 값: %d\n", value);

	// 큐의 전체 출력
	displayQueue(&queue);

	return 0;
}