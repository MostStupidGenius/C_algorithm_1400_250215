#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

// 데이터 영역
int globalVar = 100; // 초기화된 전역 변수
static int staticVar = 200; // 정적 변수

int main() {
	// 메모리 영역과 동적 메모리 할당
	// 메모리 영역은 크게 네 가지로 나뉜다.
	// 1. 코드 영역: 컴파일 관련
	// 2. data 영역: static과 전역변수
	// 3. 스택 영역: 함수 생성과 소멸 영역
	// 4. 힙 영역: 동적으로 생성되고 할당되는 정보들이
	// 저장되는 영역 -> 개발자가 직접 관리

	// 스택 영역
	int localVar = 150; // 지역 변수
	// 지역변수는 해당 함수 영역이 종료되거나
	// 반환되어 함수가 종료되면 메모리에서 내려간다.

	// 힙 영역
	// 개발자가 직접 메모리에 올리고 내리는
	// 메모리 영역으로, malloc과 free를 이용해
	// 올리고 내리고를 수동으로 해야 한다.
	int* dynamicVar = (int*)malloc(sizeof(int));
	// 동적 할당이 실패하면 1(오류) 반환
	if (dynamicVar == NULL) return 1;

	*dynamicVar = 400;

	// 출력
	printf("전역 변수: %d\n", globalVar);
	printf("정적 변수: %d\n", staticVar);
	printf("지역 변수: %d\n", localVar);
	printf("동적 변수: %d\n", *dynamicVar);

	// 메모리 해제
	free(dynamicVar);
	return 0;
}