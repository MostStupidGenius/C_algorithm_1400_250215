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

// ���� ���� ����Ʈ�� ��� ����
// ���� ���� ����Ʈ�� ������ �� head ����� �ּҸ� ���� ������ ���޹޾�
// �� ��带 next�� ���� ����� �ڿ� ���ο� ��带 �����ؾ� �Ѵ�.
void insertNode(Node** head, int data) {
	// ���ο� ��� ����
	Node* newNode = createNode(data);

	// ���޹��� ��尡 ��� �ִٸ�
	if (*head == NULL) {
		// ���ο� ����� �ּҸ� ��� ������ �����ϰ�
		*head = newNode;
		// �ش� ����� ���� ��带 ����Ű�� next�� �����η� �����Ѵ�.
		newNode->next = *head;
	}
	else {
		// ���޹��� ��� �ּ� ������ ��带 �ӽ� ������ ��´�.
		Node* temp = *head;

		// ����� ���� ��Ұ� head�� ��� ��� �ּҰ� �ƴ϶��
		// ��� �ݺ�
		// ������ ��带 ã�� ���� �ݺ���
		while (temp->next != *head) {
			// ���� temp�� ���� ��尡 NULL�̶��
			// (temp�� head�̸鼭 ���� ��尡 NULL)
			//if (temp->next == NULL) break;
			temp = temp->next;
		}
		
		// while���� Ż���ߴٸ� temp ����� ���� ��Ҵ� head ����� ���̹Ƿ�
		// ���� ���temp�� ���� ���� ���ο� ��带 �����ϸ� �ȴ�.
		temp->next = newNode;

		// ���� ��带 ���ο� ����� ���� ���� ����
		newNode->next = *head;
	}
}

// ����� ����
void deleteNode(Node** head, int data) {
	// ���� ���޵� head ���� �������� �ּҰ� null�̶��
	// �Լ� ����
	if (*head == NULL) return;

	Node* current = *head, * prev = NULL;
	// ���� ����� �����Ͱ� ���޹��� �����Ϳ� �ٸ��ٸ�
	// �ݺ������� ���� ���� �Ѿ��.
	while (current->data != data) {
		// ���� ���� ��尡 ����Ű�� ���� ��尡
		// head�� ���� ���ٸ�
		if (current->next == *head) {
			// �� ������ ��ȸ�� ���̹Ƿ�, ���ϴ� �����͸�
			// ã�� ���� ���̴�.
			printf("��带 ã�� �� �����ϴ�.");
			return;
		}
		// ���� ��带 ����Ű�� ������ ���� ��� �ּҰ� ���
		prev = current;
		// ���� ������ ���� ��� �ּҰ� ���
		current = current->next;
		// ���� �ݺ� �غ�
	}
	
	// ���࿡ ���� ��尡 head�̰� ���� ��尡 ����ִٸ�
	// ���� ���� ����Ʈ�� ��� ��尡 head�� ��� ��� �ϳ����̹Ƿ�
	// ��带 ���� ���� ��带 �޸� �Ҵ� ������ �־�� �Ѵ�.
	if (current->next == *head && prev == NULL) {
		*head = NULL;
		free(current);
		return;
	}

	// ���� ���� ��尡 ����� ���� ���ٸ�
	if (current == *head) {
		// ���� ��� ������ ��� ��带 ���
		prev = *head;

		// prev�� next�� head�� �ƴ� ����
		while (prev->next != *head) {
			// prev�� next�� prev�� ��´�.
			prev = prev->next;
		}

		// head�� �ּҸ� ���� ����� ���� ���� �ٲ��ش�.
		*head = current->next;
		// prev�� next�� current�� next�� �ٲ��ش�.
		prev->next = *head;
		free(current);
	}
	// head�� ���� ���� �ٸ��ٸ�
	else {
		// ���� ����� next�� ������� ����� next ���� �־��ش�.
		prev->next = current->next;
		free(current);
	}
}
#endif // !NODE_H
