/* 배열을 나누는 프로그램 */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while (0)

/*--- 배열을 나누는 함수 ---*/
void partition(int a[], int n)
{
	int i;
	int pl = 0;			/* 왼쪽 커서 */
	int pr = n - 1;		/* 오른쪽 커서 */
	int x = a[n / 2];	/* 피벗은 가운데 요소를 선택합니다. */

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
		
	printf("피벗의 값은 %d입니다.\n", x);
	printf("피벗 이하의 그룹\n");		/* 피벗 이하의 그룹 */
	
	for (i = 0; i <= pl - 1; i++)		/* a[0] ~ a[pl - 1] */
		printf("%d ", a[i]);
	putchar('\n');
	
	if (pl > pr + 1) {
		printf("피벗과 일치하는 그룹\n");	/* 피벗과 같은 그룹 */
		for (i = pr + 1; i <= pl - 1; i++)	/* a[pr + 1] ~ a[pl - 1] */
			printf("%d ", a[i]);
		putchar('\n');
	}

	printf("피벗 이상의 그룹\n");		/* 피벗 이상의 그룹 */
	for (i = pr + 1; i < n; i++)		/* a[pr + 1] ~ a[n - 1] */
		printf("%d ", a[i]);
	
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int *x;							/* 배열의 첫 번째 요소에 대한 포인터 */
	puts("배열을 나눕니다.");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* 요소의 개수가 nx인 int형 배열을 생성 */
	
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	
	partition(x, nx);		/* 배열 x를 분할 */
	
	free(x);				/* 배열을 해제 */
	
	return 0;
}