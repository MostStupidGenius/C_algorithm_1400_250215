#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"


int main() {
	// 힙 구조
	// 기본값을 0으로 초기화하는 배열 선언
	int heap[100];
	// 현재 값이 들어가 있는 노드의 개수를 담을 변수 선언
	int size = 0;
	
	// 힙에 요소 삽입
	insert(heap, &size, 45);
	insert(heap, &size, 30);
	insert(heap, &size, 50);
	insert(heap, &size, 55);
	insert(heap, &size, 25);
	insert(heap, &size, 35);

	printf("최대힙 구성 후: ");
	// 실제로 값이 들어간 개수인 size-1번째 인덱스까지만 
	// 요소가 출력된다.
	for (int i = 0; i < size; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	// 최대값 확인
	int max = getMax(heap);
	printf("최대값: %d\n", max);

	// 최대값 추출
	// : 마지막 요소의 값을 최대값과 그 위치를 바꾼다.
	// 힙의 크기를 1 줄인다.
	// 마지막 요소가 된 가장 큰 값을 제거하고 그 값을 반환받는다.
	max = extractMax(heap, &size);
	printf("추출된 최대값: %d\n", max);

	printf("최대값 추출 후 힙: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	return 0;
}