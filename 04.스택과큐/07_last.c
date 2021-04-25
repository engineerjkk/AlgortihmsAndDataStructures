/* 
	원하는 개수만큼 데이터를 입력하고, 
	요소의 개수가 n인 배열에 최근에 입력한 n개만 저장 
*/

#include <stdio.h>
#define N 10			/* 저장하는 데이터의 개수 */

int main()
{
	int i;
	int a[N];		/* 입력한 데이터를 저장 */
	int cnt = 0;	/* 입력한 데이터의 개수 */
	int retry;		/* 다시 한 번? */

	puts("정수를 입력하세요.");

	do {
		printf("%d번째 정수 : ", cnt + 1);
		scanf("%d", &a[cnt++ % N]);
		printf("계속할까요? (Yes … 1/No … 0) : ");
		scanf("%d", &retry);
	} while (retry == 1);
		i = cnt - N;
		if (i < 0) i = 0;
		
	for (; i < cnt; i++)
		printf("%2d번째 정수 = %d\n", i + 1, a[i % N]);
		
	return 0;
}