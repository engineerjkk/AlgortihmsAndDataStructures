/* 병합 정렬 프로그램 */
#include <stdio.h>
#include <stdlib.h>

static int *buff;		/* 작업용 배열 */

/*--- 병합 정렬(main 부분) ---*/
static void __mergesort(int a[], int left, int right)
{
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;

		__mergesort(a, left, center);			/* 앞부분에 대한 병합 정렬 */
		__mergesort(a, center + 1, right);		/* 뒷부분에 대한 병합 정렬 */
		
		for (i = left; i <= center; i++)
			buff[p++] = a[i];

		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];

		while (j < p)
			a[k++] = buff[j++];
	}
}

/*--- 병합 정렬 함수 ---*/
int mergesort(int a[], int n)
{
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);		/* 배열 전체를 병합 정렬 */
	
	free(buff);
	
	return 0;
}

int main(void)
{
	int i, nx;
	int *x;				/* 배열의 첫 번째 요소에 대한 포인터 */
	
	puts("병합 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	mergesort(x, nx);			/* 배열 x를 병합 정렬 */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	
	free(x);		/* 배열을 해제 */
	
	return 0;
}