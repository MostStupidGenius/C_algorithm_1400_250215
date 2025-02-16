// node.h
#include <stdlib.h> // ���� �޸� �Ҵ�
// ��� ���� ����
// �ߺ� ���� ������ ���� ��� ����
#ifndef NODE_H
#define NODE_H

// ��� ����ü ����
typedef struct Node {
	int data; // ������ �ʵ�
	struct Node* next; // ���� ��带 ����Ű�� ������
} Node; // ����ü�� "Node"��� ��Ī(alias)�� �ο��Ͽ�
// struct Node ��ſ� Node��� �� �� �ֵ��� ����

// ����� ����ü�� �ٷ� �Լ����� ���� ����
// ��� ����
// ��ȯ�� Node Ÿ��, �Է��� int data
Node* createNode(int data);

// ��� ����
// ��� ���(head)�� data�� ���޹޴´�.
// �̶� ��� ���� ���� ����Ʈ�� ù��° ����� �����͸� ����
// Node** head, int data
// data���� ���� ���ο� ��带 ����� ���� ����Ʈ��
// �������� �߰�
void appendNode(Node* head, int data);

// ��� ����
// ���޵� data�� ������ ��带 ã�Ƽ� ����
void deleteNode(Node* head, int data);

// ������ ������ �Լ��� ����
// ���ο� ��� ���� �Լ�
Node* createNode(int data) {
	// ���� �޸� �Ҵ��� ���� ���ο� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));

	// ���� ���� �� NULL ��ȯ
	if (newNode == NULL) return NULL;
	//printf("data: %d\n", data);
	// ���ο� ��忡 data�� �����ϰ�
	newNode->data = data;
	// ���� ��带 ����Ű�� ������, next�� NULL�� �ʱ�ȭ
	newNode->next = NULL;

	// ���ο� ��带 ��ȯ
	return newNode;
}

// ���Ḯ��Ʈ�� Ư�� ���� ���ο� �����͸� �����Ͽ�
// ���ο��� ���ο� ��带 �����ϰ�
// ���ο� ��带 ���� ������ ����� ���� �����ͷ� �����Ͽ�
// ���Ḯ��Ʈ�� ��ҷ� �߰�.
void appendNode(Node* head, int data) {

	// ���޹��� head�� ���̸� �״�� �Լ� ����
	if (head == NULL) return;

	Node* currentNode = head;

	// ���ǰ� �����ϰ� �ϴ� ����
	do {
		// ���� ���� �ִ� ����� ���� ��� �ּҰ�
		// NULL���� Ȯ���Ѵ�(���� ��Ұ� ������
		// �װ��� ���ο� ��带 �߰�)
		Node* next = currentNode->next;
		if (next == NULL) break; // �ݺ��� Ż��
		// ���� ��尡 �ִٸ� �� ��带 currentNode�� ����
		currentNode = next;

	} while (currentNode->next != NULL);

	// ª�� ���� �� ��
	//while (currentNode->next != NULL) {
	//	currentNode = currentNode->next;
	//}

	// currentNode�� next�� NULL�� ����
	// ���ο� ��� ���� �� �ʱ�ȭ
	Node* newNode = createNode(data);

	// ���ο� ����� �ּҸ� currentNode�� next�� �����Ͽ�
	// ���Ḯ��Ʈ�� ���Խ�Ų��.
	currentNode->next = newNode;
}

// ���޹��� data�� ���� ��� ��,
// ���� ���� ������ ��带 �����ϰ�
// �ش� ��� �յ� ��带 �����Ų��.
void deleteNode(Node* head, int data) {
	if (head == NULL) return;
	Node* current = head;
	Node* prev = NULL;

	while (1) {
	//while(current->data != data){
		// ���� ����� �����Ϳ� ���޹��� �����Ͱ�
		// ������ Ȯ���Ͽ�
		// ������ �ݺ��� Ż��
		if (current->data == data) {
			break;
		}

		// ���� ����� �����Ϳ� ����ġ�ϴµ�,
		// ���� ��尡 �������� �ʴ´ٸ�
		// ���ݱ��� ��ġ�ϴ� �����͸� ã�� ���� ���̹Ƿ�
		// �Լ��� �����Ѵ�.
		if (current->next == NULL) {
			return; // �Լ� Ż��(����)
		}
		prev = current;
		current = current->next;
	}

	// while�� ����� �����͸� ���� ��带 ã������ �ǹ��Ѵ�.
	// �ش� ����� ���� ��尡 ����Ű�� next��
	// ���� ��尡 ����Ű�� next�� �ٲ�� �Ѵ�.

	// ���� head�� data�� ���޹��� data�� ��ġ�Ѵٸ�
	// ���� ��� prev�� NULL�� ���̹Ƿ�
	// ���� ��带 �޸� �Ҵ� ������ ���ָ� �ȴ�.
	if (prev == NULL) {
		free(current);
		return;
	}
	else if (current->next == NULL) {
		// ���� ��尡 ����Ű�� ��尡 ���ٸ�
		// ���� ��常 ���� ��忡�� �����ϰ�
		// �޸� �Ҵ� �������ָ� �ȴ�.
		prev->next = NULL; // ���� ����� next�� NULL��
		free(current);
		return;
	}

	// ���� ��嵵 �����ϰ� ���� ��嵵 �����ϴ� ���
	// �� ��带 �����Ű�� ���ؼ�
	// ���� ����� next ���� ���� ����� next ���� ����־�� �Ѵ�.
	prev->next = current->next;
	// ���� ���� ���̻� ���� ��带 ����Ű�� �ʱ� ������
	// �޸� �Ҵ� ������ ���ָ� ������.
	free(current);
	return;
}
#endif // !NODE_H