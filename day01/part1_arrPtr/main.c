#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arrInt[] = {0, 10, 2, 3};
	// 배열은 0번째 방의 주소를 가리키는 포인터변수이다.
	printf("%d\n", *(arrInt + 1));

	// 기존 배열 주소에서 1만큼 이동한 주소를 가리킨다.
	int* arrInt2 = arrInt + 1;
	// 즉, 배열은 0번째 방의 주소를 가리켰으므로
	// arrInt2는 1번째 방의 주소를 가리키는
	// 포인터변수가 된 것이다.

	// 해당 포인터변수의 값에 접근하면
	// 1번째 방 요소의 값에 접근할 수 있다.
	printf("%d\n", *arrInt2);

	*arrInt2 = 30;

	// arrInt[1] 요소를 확인해보면
	printf("%d\n", arrInt[1]);

	// 배열에서 그 값을 변경하면
	arrInt[1] = 13;
	// 같은 주소값을 가진 arrInt2에서 값에 접근했을 때
	// 바뀐 값을 받을 수 있다.
	printf("%d\n", *arrInt2);


	return 0;
}