#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"


int main() {
	// �� ����
	// �⺻���� 0���� �ʱ�ȭ�ϴ� �迭 ����
	int heap[100];
	// ���� ���� �� �ִ� ����� ������ ���� ���� ����
	int size = 0;
	
	// ���� ��� ����
	insert(heap, &size, 45);
	insert(heap, &size, 30);
	insert(heap, &size, 50);
	insert(heap, &size, 55);
	insert(heap, &size, 25);
	insert(heap, &size, 35);

	printf("�ִ��� ���� ��: ");
	// ������ ���� �� ������ size-1��° �ε��������� 
	// ��Ұ� ��µȴ�.
	for (int i = 0; i < size; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	// �ִ밪 Ȯ��
	int max = getMax(heap);
	printf("�ִ밪: %d\n", max);

	// �ִ밪 ����
	// : ������ ����� ���� �ִ밪�� �� ��ġ�� �ٲ۴�.
	// ���� ũ�⸦ 1 ���δ�.
	// ������ ��Ұ� �� ���� ū ���� �����ϰ� �� ���� ��ȯ�޴´�.
	max = extractMax(heap, &size);
	printf("����� �ִ밪: %d\n", max);

	printf("�ִ밪 ���� �� ��: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	return 0;
}