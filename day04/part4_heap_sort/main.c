#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

// �� ����(heap sort)
// �ִ� �� ����(heapify)�� ���� ��Ʈ ���(�ֻ������)�� ����
// �ִ밪���� ������ ��, �� ���� ������ ��ҿ� ��ȯ,
// ���� ũ�⸦ �ٿ� ������ ��ҷ� �� �ִ밪��
// �� ������ ���ܽ�Ų��(���ĵ� ������ ����)
// �̸� �ݺ��Ͽ� ���� ũ�Ⱑ 1�� �� ������ �ݺ��ϸ�
// ������ ��Ұ� ���� ū ���� ������ �迭 ������ �Ϸ� �ȴ�.

// �ִ� �� ������ �ϴ� �Լ�
void heapify(int arr[], int size, int rootIndex) {
	// ��Ʈ ����� �ε������� ���� ū ���� ���� �ε����� �ʱ�ȭ
	int largest = rootIndex;

	// ���� �ڽ� �ε���
	int left = 2 * rootIndex + 1;

	// ������ �ڽ� �ε���
	int right = 2 * rootIndex + 2;

	// ���� �ڽ��� ��Ʈ���� ū ���
	// ���� �ڽ��� �ε����� largest�� �����Ѵ�.
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}

	// ������ �ڽ� �˻�
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	// ������ ���� �ϳ��� ��ȯ�� �Ͼ�ٸ� 
	// largest�� ���� ���� ��Ʈ �ε����� ���� ��ȯ�Ͽ�
	// �ִ� ���� �����ؾ� �Ѵ�.
	if (largest != rootIndex) {
		swap(&arr[rootIndex], &arr[largest]);
		heapify(arr, size, largest);
	}
}

// �� ���� �Լ�
void heapSort(int arr[], int size) {
	// �ʱ� �� ����
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	// ������ ���Ҹ� �ϳ��� ����
	for (int i = size - 1; i >= 0; i--) {
		// 0��° ����� ���� i��° ����� ���� ��ȯ
		swap(&arr[0], &arr[i]);
		// 0��°���� i��° ��ұ��� �ִ� �� ���� ����
		heapify(arr, i, 0);
	}
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(*arr);

	printf("���� �� �迭\n");
	printArr(arr, size);

	heapSort(arr, size);

	printf("\n���� �� �迭\n");
	printArr(arr, size);

	return 0;
}