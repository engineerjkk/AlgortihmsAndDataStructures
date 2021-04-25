/* 퀵 정렬 (비재귀 버전) */
#include <stdio.h> 
#include <stdlib.h> 
#include "IntStack.h"

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

/*--- 퀵 정렬 (비재귀 버전) ---*/
void quick(int a[], int left, int right)
{
	IntStack lstack; /* 분할할 맨앞 요소의 인덱스 스택 */
	IntStack rstack; /* 분할할 맨뒤 요소의 인덱스 스택 */

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left);		/* 왼쪽 커서 */
		int pr = (Pop(&rstack, &right), right);		/* 오른쪽 커서 */
		int x = a[(left + right) / 2];				/* 축 가운데 요소 */

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);	/* 왼쪽 그룹의 범위 */
			Push(&rstack, pr);		/* 인덱스를 푸시 */
		}

		if (pl < right) {
			Push(&lstack, pl);		/* 오른쪽 그룹의 범위 */
			Push(&rstack, right);	/* 인덱스를 푸시 */
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

int main(void)
{
	int i, nx;
	int * x; /* 배열의 첫 번째 요소에 대한 포인터 */

	puts("퀵 정렬");
	printf("요솟수 :");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] :", i);
		scanf("%d", &x[i]);
	}

	quick(x, 0, nx - 1);			/* 배열 x를 퀵 정렬 */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);						/* 배열을 삭제 */

	return 0;
}