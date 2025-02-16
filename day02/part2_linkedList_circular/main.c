#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "node.h"

void printLinkedList(Node** head) {
	// �� ���������Ͱ� ����Ű�� �ּҸ� current�� ���
	Node* current = *head;
	// ���� ��尡 NULL�� �ƴ϶�� ���Ḯ��Ʈ ��ȸ
	while (current != NULL) {
		// ���� ����� �����͸� ����ϰ�
		printf("%d -> ", current->data);

		if (current->next == *head) break;

		// ���� ��带 ���� ��� ������ ��Ƽ� �̾ ����
		current = current->next;
	}
	// �������� null�� ����Ű�Ƿ� NULL�� ���
	printf("head\n");
}


int main() {
	// ���� ���� ����Ʈ�� �ʱ�ȭ
	Node* head = createNode(10);

	// ��� �߰�
	insertNode(&head, 20);
	insertNode(&head, 30);
	insertNode(&head, 35);
	insertNode(&head, 40);
	printLinkedList(&head);

	// ��� ����
	deleteNode(&head, 35);

	printLinkedList(&head);


	return 0;
}