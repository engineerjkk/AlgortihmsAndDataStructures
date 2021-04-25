/* 퀵 정렬(배열의 분할 과정을 표시) */
#include <stdio.h> 
#include <stdlib.h> 

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

/*--- 퀵 정렬(배열의 분할 과정을 표시) ---*/
void quick(int a[], int left, int right)
{
	int pl = left;				/* 왼쪽 커서 */
	int pr = right;				/* 오른쪽 커서 */
	int x = a[(pl + pr) / 2];	/* 축(가운데 요소) */

	int i;
	printf("a[%d] ~ a[%d] : {", left, right);
	for (i = left; i < right; i++)
		printf("%d", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
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

	quick(x, 0, nx - 1);		/* 배열 x를 퀵 정렬 */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);					/* 배열을 삭제 */

	return 0;
}