#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
// ����� ���� ��� ����
#include "node.h" // ū����ǥ�� ������ �����Ѿ� �Ѵ�.
//#include <node.h> // �⺻ ����� �ƴϹǷ� ����δ�
// ���� �Ұ�

	// �ܺηκ��� ��ȸ�ϰ��� �ϴ� ���Ḯ��Ʈ��
	// ù��° ��� �ּҸ� ����Ű�� ���������͸� ���޹޾�
void printLinkedList(Node* head) {
	// �� ���������Ͱ� ����Ű�� �ּҸ� current�� ���
	Node* current = head;
	// ���� ��尡 NULL�� �ƴ϶�� ���Ḯ��Ʈ ��ȸ
	while (current != NULL) {
		// ���� ����� �����͸� ����ϰ�
		printf("%d -> ", current->data);

		// ���� ��带 ���� ��� ������ ��Ƽ� �̾ ����
		current = current->next;
	}
	// �������� null�� ����Ű�Ƿ� NULL�� ���
	printf("NULL\n");
}

int main() {
	Node* head = createNode(10);
	appendNode(head, 20);
	appendNode(head, 30);
	appendNode(head, 40);
	appendNode(head, 45);
	appendNode(head, 50);

	// ���� ����Ʈ�� �����͵� ���
	printLinkedList(head);
	
	// ����� ����
	// 45���� data�� ������ ��带 ����
	deleteNode(head, 45);
	printLinkedList(head);

	return 0;
}