/* 1, 2, …, n의 합을 구합니다(do문에서 양의 정수만을 ​​n 값으로 입력합니다). */
#include <stdio.h>

int main(void)
{
	int i, n;
	int sum; 				/* 합 */

	puts("1부터 n까지의 합을 구합니다.");

	do {
		printf("n 값 : ");
		scanf("%d", &n);
	} while (n <= 0);
	
	sum = 0;
	
	for (i = 1; i <= n; i++) {	/* i = 1, 2, …, n */
		sum += i;				/* sum에 i를 추가 */
	}
	
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

	return 0;
}