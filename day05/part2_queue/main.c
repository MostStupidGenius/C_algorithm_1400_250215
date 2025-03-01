// part2_queue
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// 큐의 최대 크기 설정
#define MAX_SIZE 10

// 큐 구조체 선언
typedef struct {
	int data[MAX_SIZE];
	int front;
	int rear;
} Queue;

// 노드 구조체(연결 리스트)
//typedef struct {
//	int data;
//	Node* next;
//} Node;

// 큐 구조체 초기화
void initQueue(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

// 큐가 비어있는지 확인하는 함수
bool isEmpty(Queue* queue) {
	// front와 rear가 같은 위치에 있으면 큐가 비어있음을
	// 의미한다.
	return (queue->front == queue->rear);
}
// 큐가 꽉차 있는지 확인하는 함수
bool isFull(Queue* queue) {
	return ((queue->rear + 1) % MAX_SIZE == queue->front);
}


// 데이터 삽입
bool enqueue(Queue* queue, int value) {
	if (isFull(queue)) {
		printf("큐가 가득 찼습니다.\n");
		return false;
	}

	queue->rear = (queue->rear + 1) % MAX_SIZE;
	queue->data[queue->rear] = value; // 데이터 저장
	return true;
}

// 데이터 삭제
// 1. 큐가 비어있는지 확인
// 2. front를 다음 위치로 이동
// 3. 해당 위치의 데이터를 반환
// 
bool dequeue(Queue* queue, int* value) {
	// 비어있다면
	if (isEmpty(queue)) {

		return false;
	}
	// front 이동
	// front의 값을 1 증가시켜 이전 front로의 접근을 막는다.
	queue->front = (queue->front + 1) % MAX_SIZE; 
	// 기존 front에 있던 값을 value에 담아보내고
	*value = queue->data[queue->front]; // 데이터 반환
	return true;
}

// 데이터 조회
// 큐의 맨 앞에 있는 데이터를 확인하는 함수
bool peek(Queue* queue, int* value) {
	// 비어있으면 false 반환
	if (isEmpty(queue)) {

		return false;
	}

	*value = queue->data[(queue->front+1) % MAX_SIZE];

	return true;
}

void displayQueue(Queue* queue) {
	if (isEmpty(queue)) {

		return false;
	}
	// 배열의 실제 인덱스를 구한다.
	int i = (queue->front+1) % MAX_SIZE;
	printf("큐 요소: ");

	while (i != (queue->rear + 1) % MAX_SIZE) {
		printf("%d ", queue->data[i]);
		i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}


int main() {
	// 큐 자료구조 사용
	Queue queue;
	int value; // 값을 담아올 변수 선언

	// 큐 초기화
	initQueue(&queue);

	// 큐에 데이터 삽입
	enqueue(&queue, 10);
	printf("queue->rear: %d\n", queue.rear);
	enqueue(&queue, 20);
	printf("queue->rear: %d\n", queue.rear);
	enqueue(&queue, 30);
	printf("queue->rear: %d\n", queue.rear);
	enqueue(&queue, 40);
	printf("queue.rear: %d\n", queue.rear);
	printf("queue.front: %d\n", queue.front);
	printf("queue.data: %d\n", queue.data[1]);
	printf("queue.data: %d\n", queue.data[2]);

	printf("%d\n", isEmpty(&queue));

	// 큐 내용 출력
	displayQueue(&queue);

	// 큐 데이터 제거
	if (dequeue(&queue, &value)) {
		printf("프론트에서 제거한 값: %d\n", value);
	}

	// 큐의 가장 앞에 있는 값 확인
	if (peek(&queue, &value)) {
		printf("가장 앞에 있는 값: %d\n", value);
	}
	printf("=======\n");
	displayQueue(&queue);

	return 0;
}