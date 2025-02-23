#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

int gSize = 0;

// ���޵� �迭�� ����ϴ� �Լ�
void printArr(int arr[], int size) {
	printf("{");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("}\n");
}

// ���� ����(merge sort)
// ���� �迭�� �ϳ��� ��Ҹ� ���� ������ ������ ������
// �̸� ���ĵ� ���·� �����Ͽ� ����������
// ��ü�� ���ĵ� �迭�� ����� ���
// ���� �������� �� �迭�� ��Ҹ� ���Ͽ�
// ���� ������ �� �迭�� �ִ´�.
// �������� ���� ���: ������ ���� ��ҵ��� ����� ��ġ�� ������.
// �׻� O(n log n)�� �ð� ���⵵�� ����
// ���� ����Ʈ�� ���Ŀ� ����

// ����, �߰����� �޸� ������ �ʿ��ϴ�.
// ���� �����ͼ¿��� ȿ���� ������, �� ���ĺ��� ���� �� �ִ�.

// �� �κ� �迭�� �����ϴ� �Լ�
void merge(int arr[], int left, int mid, int right) {
	// left: ������ �κ��� ���� �ε���
	// mid: ������ �κ��� �߰� �ε���
	// right: ������ �κ��� �� �ε���
		
	int i, j, k; // �ݺ������� ����� ���� ����

	// ���� �κ� �迭�� ũ��
	int leftSize = mid - left + 1;
	// ������ �κ� �迭�� ũ��
	int rightSize = right - mid;

	// �ӽ� �迭�� �������� ����
	int* L = (int*)malloc(leftSize * sizeof(int));
	if (L == NULL) return;
	int* R = (int*)malloc(rightSize * sizeof(int));
	if (R == NULL) return;

	// �����͸� �ӽ� �迭�� ����
	for (i = 0; i < leftSize; i++) {
		// ���� �ε������� i����ŭ ���Ͽ� �� ��Ҹ�
		// �ӽ� ���� �迭�� i��° ������ �����Ѵ�.
		L[i] = arr[left + i];
	}
	
	for (j = 0; j < rightSize; j++) {
		// �ӽ� ������ �迭�� j���� 
		// ���� ���� �߾ӿ��� 1�� ���ϰ� j��ŭ �̵��� ��ġ�� ������
		// �����Ѵ�.
		R[j] = arr[(mid + 1) + j];
	}

	// �� �κ� �迭�� ����
	i = 0; j = 0;
	k = left; // ���յ� �迭�� �ε���

	// while���� ���� �� �迭�� ��Ҹ� �����Ͽ�
	// ���ο� �迭�� ����
	while (i < leftSize && j < rightSize) {
		// �� �迭�� �̹� ���ĵ� ���¶�� ���� �Ͽ�,
		// �� ��Ҹ� ���������� ���Ͽ� �����س����� ���
		// ���� �κ� �迭�� ��Ұ� ��� �����Ǿ��ٸ�
		// �ٸ� ���� �κ� �迭�� ��� ����� ����
		// ���յ� ���麸�� ũ�ٴ� �ǹ̰� �Ǿ�
		// �������� �߰��� ���ָ� �ȴ�.
		

		// ���� �ӽ� ���� �迭�� i��° ����
		// �ӽ� ������ �迭�� j��° ������ �۰ų� ���ٸ�
		// ���� �迭�� k��° ���� ����i������ ����
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			// i�� ����
			i++;
		}
		// �ݴ���
		else {
			// ������j���� k��° ������ ����
			arr[k] = R[j];
			j++;
		}
		// �� ���� �� �ϳ��� ������ 
		// k���� 1 ����
		k++;
	}
	// i�� j �� �ϳ��� �� �ε����� �����ϸ� �ݺ����� �����.
	// ���Ŀ� ���� ��ҵ��� �����ʿ� ���� �ٿ� �ָ� �ȴ�.
	
	// ���� ��ҵ��� ����
	// ���� �κ� �迭�� ���� ���
	while (i < leftSize) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// ������ �κ� �迭�� ���� ���
	while (j < rightSize) {
		arr[k] = R[j];
		j++;
		k++;
	}
	// �ӽ� �迭 �޸� ����.
	free(L);
	free(R);
}

// ���� ���� �Լ�
void mergeSort(int arr[], int left, int right) {
	// ������ �迭, ���� �ε���, �� �ε���
	if (left < right) {
		// ���� �ε����� �� �ε��� ������ �߾� �ε����� ���ϴ� �κ�
		int mid = (left + right) / 2;
		//int mid = left + (right - left) / 2;

		// ����
		// ��������� mergeSort ȣ��
		mergeSort(arr, left, mid); // ���� �迭 �κ�
		mergeSort(arr, mid + 1, right); // ������ �迭 �κ�

		// ����
		merge(arr, left, mid, right);
	}
}

int main() {
	// �迭 ����
	int arr[] = { 65, 34, 25, 12, 22, 11, 80 };
	int size = sizeof(arr) / sizeof(*arr);
	gSize = size;
	printf("���� �� �迭: \n");
	printArr(arr, size);

	mergeSort(arr, 0, size - 1);

	printf("\n���� �� �迭: \n");
	printArr(arr, size);
	
	return 0;
}