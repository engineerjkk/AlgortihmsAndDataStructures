/* 단순 삽입 정렬 */
#include <stdio.h>
#include <stdlib.h>

/*--- 단순 삽입 정렬 함수 ---*/
void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x; 						/* 배열의 첫 번째 요소에 대한 포인터 */
	puts("단순 삽입 정렬");
	printf("요소수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); 	/* 요소의 개수가 nx인 int형 배열을 생성 */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);		/* 배열 x를 단순 삽입 정렬 */
	
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	
	free(x);				/* 배열을 해제 */
	
	return 0;
}