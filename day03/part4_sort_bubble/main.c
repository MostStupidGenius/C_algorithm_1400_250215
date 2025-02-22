#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

// 버블 정렬
// 0번째 요소부터 마지막 요소까지 순회하면서 
// 현재 요소와 다음 요소를 비교하여 더 큰 값을 뒤로 보내는 방식으로
// 각 반복마다 가장 큰 값이 가장 뒤로 보내지며,
// 다음 반복 때는 확인하는 요소의 개수를 하나씩 줄여나가
// 마지막 요소를 정렬된 값으로 간주한다.
void bubbleSort(int arr[], int size) {

	// 요소 간의 자리를 바꿀 때, 임시로 담을 변수
	int temp;
	
	// 마지막 두번째 요소는 마지막 요소와 비교하기 때문에
	// 마지막 요소를 대상으로 삼지 않기 위해
	// 인덱스를 1 줄여서 시작한다.
	for (int i = 0; i < size-1; i++) {
		// 정렬 전에 전체 요소 확인
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");

		// 내부 반복은 전체 사이즈에서 정렬된 개수에서 1을 뺀 값 만큼
		// 내부 반복을 시행한다.
		for (int j = 0; j < size-i-1; j++) {
			// 현재 반복의 요소값이 다음 요소 값과 비교했을 때
			// 현재 요소의 값이 크다면
			if (arr[j] > arr[j + 1]) {
				// 두 값을 교환한다.
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		
	}
}

// 선택 정렬 함수
// 정렬되지 않은 배열에서 최소값을 찾아서 맨 앞의 원소와 교환하는 방식으로
// 정렬하는 알고리즘이다.
// 가장 앞부분의 정렬된 부분과 그 뒤의 정렬되지 않은 부분을 나누어
// 정렬되지 않은 부분에서 가장 작은 값을 선택하여
// 정렬된 배열의 가장 앞에 집어넣는 방식이다.

// 두 정수의 주소값을 전달받아 그 값을 서로 바꾸는 함수
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selectionSort(int arr[], int size) {
	int min_idx = 0;
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");

		min_idx = i;
		// 내부 반복문
		// : 가장 작은 값을 가진 인덱스를 찾는 반복문이다.
		for (int j = i + 1; j < size; j++) {
			// 만약 j번째 요소가
			// 최소값인 줄 알았던(min_idx) 요소보다 작다면
			// 최소값의 인덱스를 j로 바꾼다.
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		// 가장 작은 값을 찾은 뒤, 현재 보고 있던
		// i인덱스 값과 가장 작은 인덱스의 값의 위치를 서로 교환한다.
		if (i == min_idx) continue;
		swap(&arr[i], &arr[min_idx]);
	}
}



int main() {
	int arr[] = { 88, 33, 21, 19, 12, 71, 15 };
	// 12, 15, 19, 21, 33, 71, 88
	// 길이 동적 확인
	int size = sizeof(arr) / sizeof(arr[0]);

	// 버블 정렬 시행
	//bubbleSort(arr, size);

	// 선택 정렬 시행
	selectionSort(arr, size);

	// 삽입 정렬 시행

	return 0;
}