#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"
// 퀵 정렬
// 분할 정복 알고리즘에서 중앙 요소를 선택하여 해당 요소를 기준으로
// 좌우로 나눴던 것처럼, 퀵 정렬은 pivot이라는 특정 값을 선택하여
// pivot을 포함한 세 개의 파트로 나눠 정렬하는 방식이다.

// 전달된 배열을 출력하는 함수
void printArr(int arr[], int size) {
	printf("{");
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("}\n");
}


int partition(int arr[], int low, int high, int size);

void quickSort(int arr[], int low, int high, int size) {

	// 전달받은 값이 정상적이라면
	if (low < high) {
		// 피봇을 선택
		// 피봇을 선택함과 동시에, 정렬을 수행
		int pivot = partition(arr, low, high, size);
		printf("pivot: %d\n", pivot);
		// 재귀적으로 함수 호출
		quickSort(arr, low, pivot - 1, size);
		quickSort(arr, pivot + 1, high, size);
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high, int size) {
	// 피봇은 가장 마지막 요소를 선택
	int pivot = arr[high];
	
	// 내부에서 요소간의 교환을 위해 사용할 인덱스 변수
	int i = (low - 1);// 지속적으로 증가

	// 가장 작은 인덱스부터 마지막 인덱스까지 반복
	for (int j = low; j < high; j++) {
		// 만약 부분 배열의 현재 보고 있는 요소의 값이
		// pivot보다 작다면 i와 j번째의 요소 값을 교환한다.
		if (arr[j] < pivot) {
			// 요소를 찾았으므로, 오른쪽으로 한 칸 이동
			i++;
			// 이동한 인덱스의 요소와 현재 보고 있는 요소의 값을 교환한다.
			swap(&arr[i], &arr[j]);
			printArr(arr, size);
		}
	}
	// 증가하여 우측으로 이동한 i보다 1만큼 더 오른쪽의 요소와
	// 가장 마지막에 있었던 요소를 서로 교환한다.
	swap(&arr[i + 1], &arr[high]);
	printf("파티셔닝 끝:\n");
	printArr(arr, size);
	printf("\n");
	return (i + 1); // 가운데 요소 인덱스를 찾아 반환
}

int main() {
	int arr[] = { 4, 7, 2, 9, 3, 5, 6, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size-1, size);

	printf("최종 정렬:\n");
	printArr(arr, size);

	return 0;
}