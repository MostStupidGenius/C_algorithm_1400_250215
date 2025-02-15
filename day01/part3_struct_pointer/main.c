#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
//#include <string.h>
#include <stdbool.h>

// 구조체 선언 및 정의
// 구조체란 여러 타입의 변수들을 구조체라는 단위로 묶어서 관리하기 위해
// 만들어진 사용자 정의 자료형이다.

// 구조체의 명칭은 대문자로 시작해야 한다.
struct Student { 
	char name[50]; // 이름
	int age; // 나이
	float score; // 학점
};

// 구조체를 가리키기 위한 포인터 변수 선언
struct Student *ptrStudent;

int main() {
	// 구조체 생성 및 주소값 할당
	struct Student hong = { "홍길동", 30, 3.5 };

	// 해당 구조체의 주소값을 추출하여
	// 포인터 변수에 전달

	// 동적 메모리 할당
	ptrStudent = (struct Student*)malloc(
		sizeof(struct Student) // 해당 구조체의 크기에 맞는
		// 동적 메모리 할당
	);
	// 널 포인터 검사(할당 여부 검사)
	if (ptrStudent == NULL) return 1;
	// 구조체 접근방법인 간접참조 연산와
	// 화살표->를 이용하여 내부 요소에 접근
	//*ptrStudent->name = "홍길동";
	ptrStudent->age = 30;
	// 간접참조 연산자로 접근하여 하위접근연산자로
	// 변수에 접근, 사용
	(*ptrStudent).age = 31;

	// 문자열의 경우, 직접 변경이 불가능하기 때문에
	// strcpy()함수를 이용하여 안전하게 그 값을 변경해야 한다.
	// strcpy()함수는 <stdlib.h> 헤더에 포함되어 있다.
	strcpy((*ptrStudent).name, "홍길동");
	
	printf("age: %d\n", ptrStudent->age);
	printf("name: %s\n", ptrStudent->name);

	free(ptrStudent);
	return 0;
}