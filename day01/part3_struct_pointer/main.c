#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
//#include <string.h>
#include <stdbool.h>

// ����ü ���� �� ����
// ����ü�� ���� Ÿ���� �������� ����ü��� ������ ��� �����ϱ� ����
// ������� ����� ���� �ڷ����̴�.

// ����ü�� ��Ī�� �빮�ڷ� �����ؾ� �Ѵ�.
struct Student { 
	char name[50]; // �̸�
	int age; // ����
	float score; // ����
};

// ����ü�� ����Ű�� ���� ������ ���� ����
struct Student *ptrStudent;

int main() {
	// ����ü ���� �� �ּҰ� �Ҵ�
	struct Student hong = { "ȫ�浿", 30, 3.5 };

	// �ش� ����ü�� �ּҰ��� �����Ͽ�
	// ������ ������ ����

	// ���� �޸� �Ҵ�
	ptrStudent = (struct Student*)malloc(
		sizeof(struct Student) // �ش� ����ü�� ũ�⿡ �´�
		// ���� �޸� �Ҵ�
	);
	// �� ������ �˻�(�Ҵ� ���� �˻�)
	if (ptrStudent == NULL) return 1;
	// ����ü ���ٹ���� �������� �����
	// ȭ��ǥ->�� �̿��Ͽ� ���� ��ҿ� ����
	//*ptrStudent->name = "ȫ�浿";
	ptrStudent->age = 30;
	// �������� �����ڷ� �����Ͽ� �������ٿ����ڷ�
	// ������ ����, ���
	(*ptrStudent).age = 31;

	// ���ڿ��� ���, ���� ������ �Ұ����ϱ� ������
	// strcpy()�Լ��� �̿��Ͽ� �����ϰ� �� ���� �����ؾ� �Ѵ�.
	// strcpy()�Լ��� <stdlib.h> ����� ���ԵǾ� �ִ�.
	strcpy((*ptrStudent).name, "ȫ�浿");
	
	printf("age: %d\n", ptrStudent->age);
	printf("name: %s\n", ptrStudent->name);

	free(ptrStudent);
	return 0;
}