// part2_queue
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// ť�� �ִ� ũ�� ����
#define MAX_SIZE 10

// ť ����ü ����
typedef struct {
	int data[MAX_SIZE];
	int front;
	int rear;
} Queue;

// ��� ����ü(���� ����Ʈ)
//typedef struct {
//	int data;
//	Node* next;
//} Node;

// ť ����ü �ʱ�ȭ
void initQueue(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(Queue* queue) {
	// front�� rear�� ���� ��ġ�� ������ ť�� ���������
	// �ǹ��Ѵ�.
	return (queue->front == queue->rear);
}
// ť�� ���� �ִ��� Ȯ���ϴ� �Լ�
bool isFull(Queue* queue) {
	return ((queue->rear + 1) % MAX_SIZE == queue->front);
}


// ������ ����
bool enqueue(Queue* queue, int value) {
	if (isFull(queue)) {
		printf("ť�� ���� á���ϴ�.\n");
		return false;
	}

	queue->rear = (queue->rear + 1) % MAX_SIZE;
	queue->data[queue->rear] = value; // ������ ����
	return true;
}

// ������ ����
// 1. ť�� ����ִ��� Ȯ��
// 2. front�� ���� ��ġ�� �̵�
// 3. �ش� ��ġ�� �����͸� ��ȯ
// 
bool dequeue(Queue* queue, int* value) {
	// ����ִٸ�
	if (isEmpty(queue)) {

		return false;
	}
	// front �̵�
	// front�� ���� 1 �������� ���� front���� ������ ���´�.
	queue->front = (queue->front + 1) % MAX_SIZE; 
	// ���� front�� �ִ� ���� value�� ��ƺ�����
	*value = queue->data[queue->front]; // ������ ��ȯ
	return true;
}

// ������ ��ȸ
// ť�� �� �տ� �ִ� �����͸� Ȯ���ϴ� �Լ�
bool peek(Queue* queue, int* value) {
	// ��������� false ��ȯ
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
	// �迭�� ���� �ε����� ���Ѵ�.
	int i = (queue->front+1) % MAX_SIZE;
	printf("ť ���: ");

	while (i != (queue->rear + 1) % MAX_SIZE) {
		printf("%d ", queue->data[i]);
		i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}


int main() {
	// ť �ڷᱸ�� ���
	Queue queue;
	int value; // ���� ��ƿ� ���� ����

	// ť �ʱ�ȭ
	initQueue(&queue);

	// ť�� ������ ����
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

	// ť ���� ���
	displayQueue(&queue);

	// ť ������ ����
	if (dequeue(&queue, &value)) {
		printf("����Ʈ���� ������ ��: %d\n", value);
	}

	// ť�� ���� �տ� �ִ� �� Ȯ��
	if (peek(&queue, &value)) {
		printf("���� �տ� �ִ� ��: %d\n", value);
	}
	printf("=======\n");
	displayQueue(&queue);

	return 0;
}