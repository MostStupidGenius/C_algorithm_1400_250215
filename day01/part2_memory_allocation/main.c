#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

// ������ ����
int globalVar = 100; // �ʱ�ȭ�� ���� ����
static int staticVar = 200; // ���� ����

int main() {
	// �޸� ������ ���� �޸� �Ҵ�
	// �޸� ������ ũ�� �� ������ ������.
	// 1. �ڵ� ����: ������ ����
	// 2. data ����: static�� ��������
	// 3. ���� ����: �Լ� ������ �Ҹ� ����
	// 4. �� ����: �������� �����ǰ� �Ҵ�Ǵ� ��������
	// ����Ǵ� ���� -> �����ڰ� ���� ����

	// ���� ����
	int localVar = 150; // ���� ����
	// ���������� �ش� �Լ� ������ ����ǰų�
	// ��ȯ�Ǿ� �Լ��� ����Ǹ� �޸𸮿��� ��������.

	// �� ����
	// �����ڰ� ���� �޸𸮿� �ø��� ������
	// �޸� ��������, malloc�� free�� �̿���
	// �ø��� ������ �������� �ؾ� �Ѵ�.
	int* dynamicVar = (int*)malloc(sizeof(int));
	// ���� �Ҵ��� �����ϸ� 1(����) ��ȯ
	if (dynamicVar == NULL) return 1;

	*dynamicVar = 400;

	// ���
	printf("���� ����: %d\n", globalVar);
	printf("���� ����: %d\n", staticVar);
	printf("���� ����: %d\n", localVar);
	printf("���� ����: %d\n", *dynamicVar);

	// �޸� ����
	free(dynamicVar);
	return 0;
}