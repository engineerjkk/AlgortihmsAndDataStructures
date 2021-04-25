/* bsearch 함수를 사용하여 내림차순으로 정렬한 배열에서 검색 */
#include <stdio.h>
#include <stdlib.h>

/*--- 정수를 비교하는 함수(내림차순) ---*/
int int_cmpr(const int *a, const int *b)
{
	if (*a < *b)
		return 1;
	else if (*a > *b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int i, nx, ky;
	int *x; 							/* 배열의 첫 번째 요소에 대한 포인터 */
	int *p; 	                        /* 검색한 요소에 대한 포인터 */
	
	puts("bsearch 함수를 사용하여 검색");
	printf("요소의 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); 		/* 요소의 개수 nx인 int형 배열을 생성 */
	
	printf("내림차순으로 입력하세요.\n", nx);
	printf("x[0] : ");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] > x[i - 1]); 	/* 바로 앞의 값보다 크면 다시 입력 */
	}
	
	printf("검색 값 : ");
	scanf("%d", &ky);
	p = bsearch(&ky, 			                        /* 검색 값에 대한 포인터 */
		x, 							                    /* 배열 */
		nx, 								            /* 요소의 개수 */
		sizeof(int), 							        /* 요소의 크기 */
		(int(*)(const void *, const void *)) int_cmpr 	/* 비교 함수 */
	);
	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p - x));
	
	free(x); /* 배열을 해제 */
	
	return 0;
}