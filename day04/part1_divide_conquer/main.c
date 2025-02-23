#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "basic.h"

// 분할 정복 알고리즘
// 큰 문제를 더 작은 부분 문제로 나누어 해결하는 방식
// 내부적으로 재귀함수를 사용하여 구현된다.

// 분할 정복 구현
// 배열의 최대값 찾기

/**
 * 분할 정복을 사용하여 배열에서 최대값을 찾는 함수
 * @param arr: 정수 배열
 * @param start: 현재 부분 배열의 시작 인덱스
 * @param end: 현재 부분 배열의 끝 인덱스
 * return: 해당 범위에서의 최대값(int)
*/
int findMax(int arr[], int start, int end) {
	// 기저 사례: 원소가 하나일 때
	if (start == end) {
		// 시작 인덱스와 끝 인덱스가 같을 경우,
		// 원소가 하나라고 볼 수 있다.
		return arr[start]; // 그냥 그 원소를 반환한다.
	}

	// 1단계: 분할 - 배열을 두 부분으로 나눈다.
	// 시작 인덱스와 끝 인덱스의 중간 인덱스를 정한다.
	int midIndex = (start + end) / 2; // 정수를 2로 나누면 몫만 나온다.
	
	// 2단계: 정복 - 왼쪽과 오른쪽 부분에서 각각 최대값을 찾는다.
	// 왼쪽과 오른쪽을 구분하는 기준점을 midIndex로 한다.
	int leftMax = findMax(arr, start, midIndex);
	int rightMax = findMax(arr, midIndex+1, end);

	// 3단계: 결합(병합) - 두 부분의 최대값 중 더 큰 값을 반환
	// 토너먼트처럼 최종 우승자를 뽑기 위해 그 아래로
	// 반씩 나누며 진행되는 모양을 취한다.
	return (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
	int arr[] = {23, 35, 82, 51, 17, 63, 41, 88};
	int size = sizeof(arr) / sizeof(arr[0]);
	int max = findMax(arr, 0, size - 1);
	printf("최대값: %d\n", max);
	return 0;
}