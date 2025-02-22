// basic.h
#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>

// ���� �ڷᱸ��
// - ���� Ʈ��(Binary Tree)
// ���� ������ ������� �� Ʈ�� ������, �θ��尡 �ִ� �� ����
// �ڽĳ�常 ���� �� �ִ� Ʈ�� ������ ���� Ʈ����� �θ���.

// ���� Ʈ�� ��� ����ü ����
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// ���� Ʈ���� ��忡 �����͸� ���� ��带 ��ȯ�ϴ� �Լ� - ������
struct Node* cNode(int data) {
	// ��ȯ�� ��带 ���� ���� �� ���� �Ҵ�
	struct Node* result = (struct Node*)malloc(sizeof(struct Node));
	if (result == NULL) return NULL;

	result->data = data;
	// �ڽĳ����� �����ϰ� �ΰ����� ������ ���� �����س��´�.
	result->right = NULL;
	result->left = NULL;
	return result;
}

struct Node* insertNode(struct Node* head, int data) {
	// ���� head�� NULL�̶�� ���ο� ��带 �����Ͽ� ��ȯ
	if (head == NULL) return cNode(data);

	// ���� ���޹��� �����Ͱ� head�� �����ͺ��� �۴ٸ�
	// ���� ��带 �������� �� ����Լ��� ȣ��
	if (data < head->data) {
		head->left = insertNode(head->left, data);
	}
	else if (data > head->data) {
		head->right = insertNode(head->right, data);
	}
	return head;
}

// Ʈ�� ��ȸ
// ���� ��ȸ
// �����͸� ���� ����� ��, ���� Ʈ��, ������ Ʈ���� ��ȸ�ϴ� ����̴�.
void preorder(struct Node* root) {
	if (root != NULL) {
		// root�� NULL�� �ƴ϶�� ��ȸ
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

#endif // !NODE_H