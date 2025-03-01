// part1_stack
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
// ������ �ִ� ũ�� ����
#define MAX_SIZE 100

// ���� ����ü ����
typedef struct {
	int data[MAX_SIZE]; // �����͸� ������ �ִ� ũ�� �迭
	int top; // ������ ���� ���� �ε����� ����ų ����
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack *stack) {
	stack->top = -1; // �� ������ top�� -1�� �����Ͽ�
	// ����ִ��� ���θ� Ȯ���ϴ� �뵵�� ���δ�.

}

// ������ ����ִ��� ���θ� ��ȯ�ϴ� �Լ�
bool isEmpty(Stack* stack) {
	return stack->top == -1;
}

// ������ ���� ���ִ��� ���θ� ��ȯ�ϴ� �Լ�
bool isFull(Stack* stack) {
	return stack->top == MAX_SIZE - 1;
}

// ���ÿ� �����͸� �߰��ϴ� �Լ�(push)
// ���ÿ� �����Ͱ� ������ �߰��Ǿ��ٸ� true�� ��ȯ.
bool push(Stack* stack, int value) {
	// ������ ���� ���ִٸ�
	if (isFull(stack)) {
		// ������������ �˸��� false�� ��ȯ�Ѵ�.
		printf("���� �����÷ο�: ������ ���� á���ϴ�.\n");
		return false;
	}

	// ž �ε����� ���� �ε����� ���ο� �����͸� �߰��ϴ� �ڵ�
	// 1. Ǯ�.
	stack->top += 1;
	int newTopIndex = stack->top;

	// 2. ���������� ���
	//int newTopIndex = ++(stack->top);

	// ������ �߰�
	stack->data[newTopIndex] = value;

	// ������ �߰��� ������ �Ϸ�Ǿ����� �˸��� true ��ȯ
	return true;
}

// ���ÿ��� �����͸� �����ϰ�(top) ��ȯ�ϴ� �Լ�(pop)
bool pop(Stack* stack, int* value) {
	// int* value��� �Ű�������, ������ �����͸� ��ư�
	// ������ �ּҴ�.
	// ��ȯ�ϴ� ���� ���� ���ο� ���� ���� ��ȯ
	// ������ �����ʹ� ���޵� ������ ��ܼ� �ܺο��� ����� �� �ִ�.

	// ���� ��Ҹ� �������� ������ ����ִٸ�
	if (isEmpty(stack)) {
		printf("���� ����÷ο�\n");
		return false;
	}

	// ž�� �ε����� ���� value�� ���
	// ž �ε��� ���� 1 ���δ�.
	*value = stack->data[(stack->top)--];

	// ������ ������ ���������� �Ϸ�
	return true;
}

// ������ ���� ���� �����͸� �������� �ʰ�
// Ȯ���ϴ� �Լ�(peek)
bool peek(Stack* stack, int* value) {
	if (isEmpty(stack)) {
		printf("���� ����÷ο�\n");
		return false;
	}

	// ž�� �ε����� ���� value�� ��´�
	*value = stack->data[(stack->top)];

	// ������ Ȯ���� ���������� �Ϸ�
	return true;
}

// ������ ��� ��Ҹ� ���������� ����ϴ� �Լ�
void printStack(Stack* stack) {
	// ������ ����ִٸ�
	if (isEmpty(stack)) {
		printf("������ ����ֽ��ϴ�.\n");
		return;
	}

	// ������� �ʴٸ�
	printf("���� ����: ");
	for (int i = 0; i <= stack->top; i++) {
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}


int main() {
	// ���� �׽�Ʈ
	Stack stack;
	int value;

	// ���� �ʱ�ȭ
	initStack(&stack);

	// ������ ����
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	
	// ���� ���� ���
	printStack(&stack);

	// ��� ����(����)
	// ���޵� value ������ �ּҰ��� ����
	// main�Լ����� value�� ��� ���� Ȱ���� �� �ִ�.
	if (pop(&stack, &value)) {
		printf("������(pop) ���: %d\n", value);
	}

	// peek ����
	// ������ top ��Ҹ� Ȯ��
	if (peek(&stack, &value)) {
		printf("������ ���� ���� ���: %d\n", value);
	}

	// �ٽ� ���� ��ü ���
	printStack(&stack);

	return 0;
}