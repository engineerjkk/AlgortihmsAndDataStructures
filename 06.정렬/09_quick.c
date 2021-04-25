/* 퀵 정렬 */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 퀵 정렬 함수 ---*/
void quick(int a[], int left, int right)
{
	int pl = left;				/* 왼쪽 커서 */
	int pr = right;				/* 오른쪽 커서 */
	int x = a[(pl + pr) / 2];	/* 피벗은 가운데 요소를 선택합니다. */
	
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
	int *x;			/* 배열의 첫 번째 요소에 대한 포인터 */
	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	quick(x, 0, nx - 1);	/* 배열 x에 대해서 퀵 정렬합니다. */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	
	free(x);			/* 배열을 해제 */

	return 0;
}