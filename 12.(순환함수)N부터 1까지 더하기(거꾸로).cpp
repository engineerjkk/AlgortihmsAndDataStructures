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
		int PrintToNBwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNBwrd(n));
	}
}

// 1부터 n까지 거꾸로 출력하고 그들의 합을 반환한다
int PrintToNBwrd(int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할] ?
	[일반규칙] p(n) ::= print n,t p(n-1), return t+n
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	if (n == 1){
		printf("1");
	return 1;
}
	printf("%d ", n);
	int t = PrintToNBwrd(n - 1);
	return t + n;
}
