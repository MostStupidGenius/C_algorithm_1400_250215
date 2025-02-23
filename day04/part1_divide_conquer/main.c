#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

// ���� ���� �˰���
// ū ������ �� ���� �κ� ������ ������ �ذ��ϴ� ���
// ���������� ����Լ��� ����Ͽ� �����ȴ�.

// ���� ���� ����
// �迭�� �ִ밪 ã��

/**
 * ���� ������ ����Ͽ� �迭���� �ִ밪�� ã�� �Լ�
 * @param arr: ���� �迭
 * @param start: ���� �κ� �迭�� ���� �ε���
 * @param end: ���� �κ� �迭�� �� �ε���
 * return: �ش� ���������� �ִ밪(int)
*/
int findMax(int arr[], int start, int end) {
	// ���� ���: ���Ұ� �ϳ��� ��
	if (start == end) {
		// ���� �ε����� �� �ε����� ���� ���,
		// ���Ұ� �ϳ���� �� �� �ִ�.
		return arr[start]; // �׳� �� ���Ҹ� ��ȯ�Ѵ�.
	}

	// 1�ܰ�: ���� - �迭�� �� �κ����� ������.
	// ���� �ε����� �� �ε����� �߰� �ε����� ���Ѵ�.
	int midIndex = (start + end) / 2; // ������ 2�� ������ �� ���´�.
	
	// 2�ܰ�: ���� - ���ʰ� ������ �κп��� ���� �ִ밪�� ã�´�.
	// ���ʰ� �������� �����ϴ� �������� midIndex�� �Ѵ�.
	int leftMax = findMax(arr, start, midIndex);
	int rightMax = findMax(arr, midIndex+1, end);

	// 3�ܰ�: ����(����) - �� �κ��� �ִ밪 �� �� ū ���� ��ȯ
	// ��ʸ�Ʈó�� ���� ����ڸ� �̱� ���� �� �Ʒ���
	// �ݾ� ������ ����Ǵ� ����� ���Ѵ�.
	return (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
	int arr[] = {23, 35, 82, 51, 17, 63, 41, 88};
	int size = sizeof(arr) / sizeof(arr[0]);
	int max = findMax(arr, 0, size - 1);
	printf("�ִ밪: %d\n", max);
	return 0;
}