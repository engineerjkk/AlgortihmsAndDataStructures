#include <stdio.h>

#pragma warning(disable: 4996)

void main()
{
	while (1) {
		printf("n ? ");
		int n;
		scanf("%d", &n);
		if (n < 0)
			break;
		int PrintToNFwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNFwrd(n));
	}
}

// 1부터 n까지 출력하고 그들의 합을 반환한다
int PrintToNFwrd(int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할] ?
	[일반규칙] p(n) ::= t=p(n-1),print n, return n+t
	[진행방향] 10->0
	[중단조건] n이 0이되면 중단
	[단순해] ?
	***/
	if (n == 0) {
		return 0;
	}
	int t = PrintToNFwrd(n - 1);
	printf("%d ", n);
	return n+t;
}
