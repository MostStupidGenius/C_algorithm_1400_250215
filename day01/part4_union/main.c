#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// 공용체(union)
// 하나의 공간에 여러 타입으로 값을 저장할 수 있는
// 사용자 정의 자료형(데이터 타입)
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

	// 공용체에서 현재 사용중인 자료형 값은 정상적으로 출력되지만
	// 현재 사용하지 않는 자료형 값은 기본값(정수0, 실수0.0)이나
	// 정상적이지 않은 값이 출력 된다.
	data.d = 3.14;
	printf("data.i: %d\n", data.i); // 실수값은 정수형으로 해석한
	// 이상한 값이 출력된다.

	// 공용체의 동적 메모리 할당
	// 이때 할당되는 메모리의 크기는
	// 공용체의 멤버 중 가장 큰 자료형의 크기를 따른다.
	union Data* data2_ptr = (union Data*)malloc(sizeof(union Data));
	// 댕글링 포인터 방지를 위한 널 값 검사
	if (data2_ptr == NULL) return 1;

	data2_ptr->i = 31;
	union Data data3 = *data2_ptr;
	printf("data3.i: %d\n", data3.i);

	return 0;
}