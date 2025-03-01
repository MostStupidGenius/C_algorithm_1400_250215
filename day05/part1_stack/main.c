// part1_stack
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
// 스택의 최대 크기 정의
#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct {
	int data[MAX_SIZE]; // 데이터를 저장할 최대 크기 배열
	int top; // 스택의 가장 위의 인덱스를 가리킬 변수
} Stack;

// 스택 초기화 함수
void initStack(Stack *stack) {
	stack->top = -1; // 빈 스택의 top은 -1로 설정하여
	// 비어있는지 여부를 확인하는 용도로 쓰인다.

}

// 스택이 비어있는지 여부를 반환하는 함수
bool isEmpty(Stack* stack) {
	return stack->top == -1;
}

// 스택이 가득 차있는지 여부를 반환하는 함수
bool isFull(Stack* stack) {
	return stack->top == MAX_SIZE - 1;
}

// 스택에 데이터를 추가하는 함수(push)
// 스택에 데이터가 무사히 추가되었다면 true를 반환.
bool push(Stack* stack, int value) {
	// 스택이 가득 차있다면
	if (isFull(stack)) {
		// 가득차있음을 알리고 false를 반환한다.
		printf("스택 오버플로우: 스택이 가득 찼습니다.\n");
		return false;
	}

	// 탑 인덱스의 다음 인덱스에 새로운 데이터를 추가하는 코드
	// 1. 풀어씀.
	stack->top += 1;
	int newTopIndex = stack->top;

	// 2. 증감연산자 사용
	//int newTopIndex = ++(stack->top);

	// 데이터 추가
	stack->data[newTopIndex] = value;

	// 데이터 추가가 무사히 완료되었음을 알리는 true 반환
	return true;
}

// 스택에서 데이터를 제거하고(top) 반환하는 함수(pop)
bool pop(Stack* stack, int* value) {
	// int* value라는 매개변수는, 제거한 데이터를 담아갈
	// 변수의 주소다.
	// 반환하는 값은 제거 여부에 대한 값만 반환
	// 제거한 데이터는 전달된 변수에 담겨서 외부에서 사용할 수 있다.

	// 만약 요소를 뽑으려는 스택이 비어있다면
	if (isEmpty(stack)) {
		printf("스택 언더플로우\n");
		return false;
	}

	// 탑의 인덱스의 값을 value에 담고
	// 탑 인덱스 값을 1 줄인다.
	*value = stack->data[(stack->top)--];

	// 데이터 추출이 정상적으로 완료
	return true;
}

// 스택의 가장 위의 데이터를 제거하지 않고
// 확인하는 함수(peek)
bool peek(Stack* stack, int* value) {
	if (isEmpty(stack)) {
		printf("스택 언더플로우\n");
		return false;
	}

	// 탑의 인덱스의 값을 value에 담는다
	*value = stack->data[(stack->top)];

	// 데이터 확인이 정상적으로 완료
	return true;
}

// 스택의 모든 요소를 순차적으로 출력하는 함수
void printStack(Stack* stack) {
	// 스택이 비어있다면
	if (isEmpty(stack)) {
		printf("스택이 비어있습니다.\n");
		return;
	}

	// 비어있지 않다면
	printf("스택 내용: ");
	for (int i = 0; i <= stack->top; i++) {
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}


int main() {
	// 스택 테스트
	Stack stack;
	int value;

	// 스택 초기화
	initStack(&stack);

	// 데이터 삽입
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	
	// 스택 내용 출력
	printStack(&stack);

	// 요소 추출(제거)
	// 전달된 value 변수의 주소값을 통해
	// main함수에서 value에 담긴 값을 활용할 수 있다.
	if (pop(&stack, &value)) {
		printf("제거한(pop) 요소: %d\n", value);
	}

	// peek 연산
	// 스택의 top 요소를 확인
	if (peek(&stack, &value)) {
		printf("스택의 가장 위의 요소: %d\n", value);
	}

	// 다시 스택 전체 출력
	printStack(&stack);

	return 0;
}