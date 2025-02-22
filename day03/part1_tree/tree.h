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
	// ���޹��� head ��尡 ����ִٸ� ���ο� ��带 ���� ��ȯ�Ѵ�.
	if (head == NULL) {
		struct Node* newNode = cNode(data);
		return newNode;
	}
	// ���ο��� �־��� ���ǿ� ���� �ݺ����� ����ȴ�.
	// head���� �� �ڽĳ����� �ִ����� �˻��ϰ�
	// �������� ����, �� �κп� ���ο� newNode�� �ּҸ� �����Ѵ�.
	// ����Լ� ������� ������ Ž��

	// ���� �������� ¦����� ���ʿ� ������ ����
	if (rand() % 2 == 0) {
		head->left = insertNode(head->left, data);
	}
	// �������� Ȧ����� �����ʿ� ������ ����
	else {
		head->right = insertNode(head->right, data);
	}

	return head;
}

// ����� ��ȸ
// ���� ��ȸ
// : ���� �ڽ� ��带 Ž���� ��,
// ���� ����ϰ� �� �ڿ� ������ �ڽ� ��带 Ž���Ѵ�
void inorderTrav(struct Node* root) {
	// ���޹��� ��尡 ������� ���� ��쿡�� data ���
	if (root != NULL) {
		// ��������� �Լ� ȣ��
		// ���� �ڽ� ����� Ʈ���� ��������� Ž�� �� ���
		inorderTrav(root->left);
		// ���� ���� �ִ� ����� ���� ���
		printf("%d ", root->data);
		// ������ �ڽ� ����� Ʈ���� ��������� Ž�� �� ���
		inorderTrav(root->right);
	}
}







#endif // !NODE_H