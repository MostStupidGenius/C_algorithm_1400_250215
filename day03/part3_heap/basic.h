// basic.h
#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>

// 힙(heap)
// 최상위 노드가 가장 큰 값을 가지게끔 완전 이진 트리 구조로
// 데이터를 정렬하는 자료구조이다.
// 완전 이진 트리: 마지막 레벨을 제외한 모든 레벨이 완전히 채워져 있고,
// 마지막 레벨의 모든 노드는 가능한 한 왼쪽부터 채워져 있는 이진 트리
// 최대 힙(max heap)
// : 부모 노드의 값이 자식 노드의 값보다 항상 크거나 같은, 
// 완전 이진 트리를 말한다.
// -> 최상위 노드는 항상 해당 트리에서 가장 큰 값이 위치하게 된다.

// 최대 힙에서 노드의 위치를 바꾸는 함수
void swap(int* a, int* b) {
	// 정수 변수의 주소값을 전달받아
	int temp = *a;// a의 값을 임시 변수에 담고
	*a = *b; // a의 값을 b에 담긴 값으로 바꾸고
	*b = temp; // b의 값을 임시로 담았던 a의 값으로 바꾼다.
}

// 최대 힙을 유지하도록 재정렬하는 함수
// heapify
// : 내부적으로 값의 교환과 재귀호출로 이루어져 있다.
void heapify(int heap[], int heapSize, int rootIndex) {
	// data가 가장 큰 인덱스를 담는 변수를 초기화
	int largest = rootIndex;

	// 왼쪽 자식의 인덱스를 유추
	int leftChild = 2 * rootIndex + 1;
	int rightChild = leftChild + 1;

	// 왼쪽 자식의 인덱스가 전체 힙의 사이즈보다 작고
	// 왼쪽 자식의 값이 largest의 data보다 크다면
	// largest의 값을 왼쪽 자식의 인덱스로 대체
	if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
		largest = leftChild;
	}

	// 오른쪽 자식에도 동일한 로직을 수행
	if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
		largest = rightChild;
	}
	
	// 자식 인덱스의 값 중 root인덱스의 값보다 큰 값이 있다면
	// 값이 가장 큰 인덱스의 값이 변경되었다면
	if (largest != rootIndex) {
		// 자식 노드의 값을 부모 노드의 값과 교환해야 한다.
		swap(&heap[rootIndex], &heap[largest]);
		// 최대 힙 유지를 위해 heapify를 재귀적으로 호출
		heapify(heap, heapSize, largest);
	}
}

// 새로운 요소 삽입
void insert(int heap[], int* n, int key) {
	// 현재 힙 구조의 개수n의 값이 0이라면
	// 힙 구조에 있는 노드 개수가 0개라는 의미이므로
	if (*n == 0) {
		// 새로 전달받은 값인 key를 0번째 요소로 추가한다.
		heap[0] = key;
		// 힙 구조의 노드 개수를 1 증가시킨다.
		(*n)++;
		return; // 새 값이 추가되었으므로 함수 종료
	}

	// 힙 구조의 노드 개수번째 값을 전달된 key값으로 설정
	// 새로 삽입된 key값을 마지막 노드로 추가함을 의미한다.
	// 노드의 개수는 새로 입력될 값의 인덱스를 가리킨다.
	heap[*n] = key;
	(*n)++; // 노드의 개수를 1 증가시킨다.

	// 상향식으로 힙 속성 유지
	// 노드개수에서 2를 나누고 1을 뺀 값은
	// 힙 구조에서 마지막 노드의 부모 노드의 인덱스를 가리키는
	// 공식이다.
	for (int i = *n / 2 - 1; i >= 0; i--) {
		// *n은 마지막 요소를 제외한 나머지의 개수를 의미한다.
		heapify(heap, *n, i);
	}
}

// 최대값(루트) 삭제
int extractMax(int heap[], int* size) {
	if (*size == 0) {
		return -1; // 노드와 값이 없음을 의미한다.
	}

	// 첫번째 노드의 값이 최대값일 것이다.
	int max = heap[0];

	// 마지막 노드를 최상위 노드로 옮기고
	heap[0] = heap[*size - 1];
	(*size)--; // 전체 노드의 개수를 1 줄인다.

	// 가장 작은 값일 수 있는 마지막 노드를
	// 최상위로 끌어올린 다음, 이를 기준으로 최대 힙 구성을 한다.
	heapify(heap, *size, 0);
	// 가장 큰 값이었던 값을 반환
	return max;
}

// 힙의 최대값 확인
int getMax(int heap[]) {
	return heap[0];
}





#endif // !NODE_H