#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

// 힙 정렬(heap sort)
// 최대 힙 구성(heapify)을 통해 루트 노드(최상위노드)의 값을
// 최대값으로 설정한 뒤, 그 값을 마지막 요소와 교환,
// 힙의 크기를 줄여 마지막 요소로 들어간 최대값을
// 힙 구성에 제외시킨다(정렬된 것으로 간주)
// 이를 반복하여 힙의 크기가 1이 될 때까지 반복하면
// 마지막 요소가 가장 큰 값을 가지는 배열 정렬이 완료 된다.

// 최대 힙 구성을 하는 함수
void heapify(int arr[], int size, int rootIndex) {
	// 루트 노드의 인덱스값을 가장 큰 값을 가진 인덱스로 초기화
	int largest = rootIndex;

	// 왼쪽 자식 인덱스
	int left = 2 * rootIndex + 1;

	// 오른쪽 자식 인덱스
	int right = 2 * rootIndex + 2;

	// 왼쪽 자식이 루트보다 큰 경우
	// 왼쪽 자식의 인덱스를 largest에 대입한다.
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}

	// 오른쪽 자식 검사
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	// 위에서 만약 하나라도 교환이 일어났다면 
	// largest의 값을 원래 루트 인덱스의 값과 교환하여
	// 최대 힙을 구성해야 한다.
	if (largest != rootIndex) {
		swap(&arr[rootIndex], &arr[largest]);
		heapify(arr, size, largest);
	}
}

// 힙 정렬 함수
void heapSort(int arr[], int size) {
	// 초기 힙 구성
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	// 힙에서 원소를 하나씩 추출
	for (int i = size - 1; i >= 0; i--) {
		// 0번째 요소의 값과 i번째 요소의 값을 교환
		swap(&arr[0], &arr[i]);
		// 0번째부터 i번째 요소까지 최대 힙 구성 실행
		heapify(arr, i, 0);
	}
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(*arr);

	printf("정렬 전 배열\n");
	printArr(arr, size);

	heapSort(arr, size);

	printf("\n정렬 후 배열\n");
	printArr(arr, size);

	return 0;
}