#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// �������� ť ����
// ����: ����ü ���ο��� ���ο� ���� �߰��ǰų� ������ ������
// �� ���̿� ���� ���ο� �迭�� �����Ͽ� ���� ��Ҹ� �ְ�
// ����ü ���ο��� �迭�� ���̸� �����ϴ� �������
// ���� ���� ť�� ������ �� �ִ�.

typedef struct {
	int* data;
	int length;
} Queue;

// ť �ʱ�ȭ �Լ�
void initQueue(Queue* queue) {
	queue->data = NULL;
	queue->length = 0;
}

// ����ִ��� ���� Ȯ�� �Լ�
bool isEmpty(Queue* queue) {
	return queue->data == NULL;
}

// ���ο� ������ ����
void enqueue(Queue* queue, int value) {
	// data�� NULL���� �˻�
	if (isEmpty(queue)) {
		// ���̸� 1�� �����ϰ�
		queue->length = 1;
		// �� ���̸�ŭ�� ��Ҹ� ���� �迭�� ����
		int* arr = (int*)malloc(sizeof(int) * queue->length);
		if (arr == NULL) return;
		// ������� �迭�� data�� ����
		queue->data = arr;
		// data�� 0��° ������ ���޹��� value�� ���� ����
		queue->data[0] = value;
		return;
	}

	// ������ �迭�� �ִٸ�
	// ���� �Ҵ��� ���� ���ο� �迭 ����
	int newSize = queue->length + 1;
	int* arr = (int*)malloc(sizeof(queue->data[0]) * newSize);
	if (arr == NULL)return;
	for (int i = 0; i < queue->length; i++) {
		arr[i] = queue->data[i];
	}

	// ������ ��ҷ� ���ο� ���� ����
	arr[queue->length] = value;

	// ���� ���� ��� �ű�� �� ��, ť�� ���̸� 1����
	queue->length++;

	// ������ ��� �ִ� ���� �Ҵ��� �Ҵ����� ���ش�.
	free(queue->data);

	// ť�� �迭�� ���ο� �迭�� �ٲ۴�.
	queue->data = arr;
}
// 0��° ��� ���� �� ��ȯ
bool dequeue(Queue* queue, int* value) {
	// ��� ������
	if (isEmpty(queue)) {
		printf("ť�� ����ֽ��ϴ�.\n");
		return false;
	}

	// ������ ��Ҹ� ���̸� �̿��� ������ value�� ��´�.
	*value = queue->data[0];

	// ť�� ���̸� 1 ���δ�.
	queue->length--;

	// ���̰� �ϳ� �پ�� ���ο� �迭�� ���� �Ҵ�
	int* newArr = (int*)malloc(sizeof(int) * queue->length);
	if (newArr == NULL) return false;

	// ���� �迭�� ��ҵ��� ���ο� �迭�� ����
	for (int i = 0; i < queue->length; i++) {
		newArr[i] = queue->data[i+1];
	}

	// ���� ������ �迭 �Ҵ� ����
	free(queue->data);

	// ���ο� ������ �迭�� ť�� ����
	queue->data = newArr;

	// ���� ����
	return true;
}

// 0��° ��� ��ȯ
int peek(Queue* queue, int* value) {
	// ��� ������
	if (isEmpty(queue)) {
		printf("ť�� ����ֽ��ϴ�.\n");
		return false;
	}

	// ������ ��Ҹ� ���̸� �̿��� ������ value�� ��´�.
	*value = queue->data[0];

	// ���� ����
	return true;
}
// ť�� ��� ��Ҹ� ����ϴ� �Լ�
void displayQueue(Queue* queue) {
	printf("element: ");
	for (int i = 0; i < queue->length; i++) {
		printf("%d ", queue->data[i]);
	}
	printf("\n");
}

int main() {
	// ���� ���� ť
	Queue queue;
	int value;

	// ť �ʱ�ȭ
	initQueue(&queue);

	// ť ������ ����
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);
	dequeue(&queue, &value);
	enqueue(&queue, 50);

	// ť�� ��ü ���
	displayQueue(&queue);

	// ť�� ���� ���� �����͸� Ȯ��
	peek(&queue, &value);
	printf("0��° ���: %d\n", value);

	// ����� ���� �� ��ȯ
	dequeue(&queue, &value);
	printf("������ ��: %d\n", value);

	// ť�� ��ü ���
	displayQueue(&queue);

	return 0;
}