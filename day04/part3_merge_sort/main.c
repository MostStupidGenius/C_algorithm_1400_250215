#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

int gSize = 0;

// 전달된 배열을 출력하는 함수
void printArr(int arr[], int size) {
	printf("{");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("}\n");
}

// 병합 정렬(merge sort)
// 먼저 배열이 하나의 요소만 남을 때까지 반으로 나누고
// 이를 정렬된 상태로 병합하여 최종적으로
// 전체가 정렬된 배열을 만드는 방식
// 병합 과정에서 두 배열의 요소를 비교하여
// 작은 값부터 새 배열에 넣는다.
// 안정적인 정렬 방법: 동일한 값의 요소들의 상대적 위치가 보존됨.
// 항상 O(n log n)의 시간 복잡도를 보장
// 연결 리스트의 정렬에 적합

// 단점, 추가적인 메모리 공간이 필요하다.
// 작은 데이터셋에서 효율이 떨어져, 퀵 정렬보다 느릴 수 있다.

// 두 부분 배열을 병합하는 함수
void merge(int arr[], int left, int mid, int right) {
	// left: 병합할 부분의 시작 인덱스
	// mid: 병합할 부분의 중간 인덱스
	// right: 병합할 부분의 끝 인덱스
		
	int i, j, k; // 반복문에서 사용할 변수 선언

	// 왼쪽 부분 배열의 크기
	int leftSize = mid - left + 1;
	// 오른쪽 부분 배열의 크기
	int rightSize = right - mid;

	// 임시 배열을 동적으로 생성
	int* L = (int*)malloc(leftSize * sizeof(int));
	if (L == NULL) return;
	int* R = (int*)malloc(rightSize * sizeof(int));
	if (R == NULL) return;

	// 데이터를 임시 배열에 복사
	for (i = 0; i < leftSize; i++) {
		// 시작 인덱스에서 i값만큼 더하여 그 요소를
		// 임시 왼쪽 배열의 i번째 값으로 저장한다.
		L[i] = arr[left + i];
	}
	
	for (j = 0; j < rightSize; j++) {
		// 임시 오른쪽 배열의 j값을 
		// 원본 기준 중앙에서 1을 더하고 j만큼 이동한 위치의 값으로
		// 저장한다.
		R[j] = arr[(mid + 1) + j];
	}

	// 두 부분 배열을 병합
	i = 0; j = 0;
	k = left; // 병합된 배열의 인덱스

	// while문을 통해 두 배열의 요소를 정렬하여
	// 새로운 배열로 병합
	while (i < leftSize && j < rightSize) {
		// 두 배열은 이미 정렬된 상태라는 가정 하에,
		// 각 요소를 순차적으로 비교하여 적재해나가는 방식
		// 한쪽 부분 배열의 요소가 모두 소진되었다면
		// 다른 한쪽 부분 배열의 모든 요소의 값이
		// 병합된 값들보다 크다는 의미가 되어
		// 마지막에 추가만 해주면 된다.
		

		// 만약 임시 왼쪽 배열의 i번째 값이
		// 임시 오른쪽 배열의 j번째 값보다 작거나 같다면
		// 원본 배열의 k번째 값을 왼쪽i값으로 변경
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			// i값 증가
			i++;
		}
		// 반대라면
		else {
			// 오른쪽j값을 k번째 값으로 설정
			arr[k] = R[j];
			j++;
		}
		// 위 과정 중 하나가 끝나면 
		// k값도 1 증가
		k++;
	}
	// i와 j 중 하나가 끝 인덱스에 도달하면 반복문이 멈춘다.
	// 이후엔 남은 요소들을 오른쪽에 마저 붙여 주면 된다.
	
	// 남은 요소들을 복사
	// 왼쪽 부분 배열이 남을 경우
	while (i < leftSize) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// 오른쪽 부분 배열이 남을 경우
	while (j < rightSize) {
		arr[k] = R[j];
		j++;
		k++;
	}
	// 임시 배열 메모리 해제.
	free(L);
	free(R);
}

// 병합 정렬 함수
void mergeSort(int arr[], int left, int right) {
	// 정렬할 배열, 시작 인덱스, 끝 인덱스
	if (left < right) {
		// 시작 인덱스와 끝 인덱스 사이의 중앙 인덱스를 구하는 부분
		int mid = (left + right) / 2;
		//int mid = left + (right - left) / 2;

		// 분할
		// 재귀적으로 mergeSort 호출
		mergeSort(arr, left, mid); // 왼쪽 배열 부분
		mergeSort(arr, mid + 1, right); // 오른쪽 배열 부분

		// 병합
		merge(arr, left, mid, right);
	}
}

int main() {
	// 배열 선언
	int arr[] = { 65, 34, 25, 12, 22, 11, 80 };
	int size = sizeof(arr) / sizeof(*arr);
	gSize = size;
	printf("정렬 전 배열: \n");
	printArr(arr, size);

	mergeSort(arr, 0, size - 1);

	printf("\n정렬 후 배열: \n");
	printArr(arr, size);
	
	return 0;
}