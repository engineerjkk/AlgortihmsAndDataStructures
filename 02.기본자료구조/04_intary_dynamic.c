/* int형 배열을 동적으로 생성하고 해제합니다. */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int *a; 	/* 배열의 첫 번째 요소의 포인터 */
	int na; 	/* 배열 a의 요솟수 */
	
	printf("요솟수 : ");
	scanf("%d", &na);
	a = calloc(na, sizeof(int)); 	/* 요소 개수가 na인 int형 배열을 생성 */

	if (a == NULL)
		puts("메모리 확보에 실패했습니다.");
	else {
		printf("%d개의 정수를 입력하세요.\n", na);
	
		for (i = 0; i < na; i++) {
			printf("a[%d] : ", i);
			scanf("%d", &a[i]);
		}

		printf("각 요솟값은 아래와 같습니다.\n");

		for (i = 0; i < na; i++)
			printf("a[%d] = %d\n", i, a[i]);

		free(a); /* 요소 개수가 na인 int형 배열을 해제 */
	}

	return 0;
}