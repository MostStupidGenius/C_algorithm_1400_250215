#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"
// �� ����
// ���� ���� �˰��򿡼� �߾� ��Ҹ� �����Ͽ� �ش� ��Ҹ� ��������
// �¿�� ������ ��ó��, �� ������ pivot�̶�� Ư�� ���� �����Ͽ�
// pivot�� ������ �� ���� ��Ʈ�� ���� �����ϴ� ����̴�.

// ���޵� �迭�� ����ϴ� �Լ�
void printArr(int arr[], int size) {
	printf("{");
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("}\n");
}


int partition(int arr[], int low, int high, int size);

void quickSort(int arr[], int low, int high, int size) {

	// ���޹��� ���� �������̶��
	if (low < high) {
		// �Ǻ��� ����
		// �Ǻ��� �����԰� ���ÿ�, ������ ����
		int pivot = partition(arr, low, high, size);
		printf("pivot: %d\n", pivot);
		// ��������� �Լ� ȣ��
		quickSort(arr, low, pivot - 1, size);
		quickSort(arr, pivot + 1, high, size);
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high, int size) {
	// �Ǻ��� ���� ������ ��Ҹ� ����
	int pivot = arr[high];
	
	// ���ο��� ��Ұ��� ��ȯ�� ���� ����� �ε��� ����
	int i = (low - 1);// ���������� ����

	// ���� ���� �ε������� ������ �ε������� �ݺ�
	for (int j = low; j < high; j++) {
		// ���� �κ� �迭�� ���� ���� �ִ� ����� ����
		// pivot���� �۴ٸ� i�� j��°�� ��� ���� ��ȯ�Ѵ�.
		if (arr[j] < pivot) {
			// ��Ҹ� ã�����Ƿ�, ���������� �� ĭ �̵�
			i++;
			// �̵��� �ε����� ��ҿ� ���� ���� �ִ� ����� ���� ��ȯ�Ѵ�.
			swap(&arr[i], &arr[j]);
			printArr(arr, size);
		}
	}
	// �����Ͽ� �������� �̵��� i���� 1��ŭ �� �������� ��ҿ�
	// ���� �������� �־��� ��Ҹ� ���� ��ȯ�Ѵ�.
	swap(&arr[i + 1], &arr[high]);
	printf("��Ƽ�Ŵ� ��:\n");
	printArr(arr, size);
	printf("\n");
	return (i + 1); // ��� ��� �ε����� ã�� ��ȯ
}

int main() {
	int arr[] = { 4, 7, 2, 9, 3, 5, 6, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size-1, size);

	printf("���� ����:\n");
	printArr(arr, size);

	return 0;
}