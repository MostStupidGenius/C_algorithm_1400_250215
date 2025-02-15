#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// ����ü(union)
// �ϳ��� ������ ���� Ÿ������ ���� ������ �� �ִ�
// ����� ���� �ڷ���(������ Ÿ��)
union Data {
	int i;
	double d;
	char c[50];
};


int main() {
	union Data data = {10};
	printf("%d\n", data.i);
	printf("%lf\n", data.d);
	printf("%s\n", data.c);

	// ����ü���� ���� ������� �ڷ��� ���� ���������� ��µ�����
	// ���� ������� �ʴ� �ڷ��� ���� �⺻��(����0, �Ǽ�0.0)�̳�
	// ���������� ���� ���� ��� �ȴ�.
	data.d = 3.14;
	printf("data.i: %d\n", data.i); // �Ǽ����� ���������� �ؼ���
	// �̻��� ���� ��µȴ�.

	// ����ü�� ���� �޸� �Ҵ�
	// �̶� �Ҵ�Ǵ� �޸��� ũ���
	// ����ü�� ��� �� ���� ū �ڷ����� ũ�⸦ ������.
	union Data* data2_ptr = (union Data*)malloc(sizeof(union Data));
	// ��۸� ������ ������ ���� �� �� �˻�
	if (data2_ptr == NULL) return 1;

	data2_ptr->i = 31;
	union Data data3 = *data2_ptr;
	printf("data3.i: %d\n", data3.i);

	return 0;
}