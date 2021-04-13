#include <stdio.h>

#pragma warning(disable: 4996)

void main()
{
	while (1) {
		int k, n;
		printf("k ? ");
		scanf_s("%d", &k);
		if (k < 0)
			break;
		printf("n ? ");
		scanf_s("%d", &n);
		if (k > n)
			break;
		int PrintK2NBwrd1(int k, int n);
		int PrintK2NBwrd2(int k, int n);
		int PrintK2NBwrd3(int k, int n);
		int PrintK2NBwrd4(int k, int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd1(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd2(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd3(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd4(k, n));
	}
}

// k부터 n까지 거꾸로 출력하고 그들의 합을 반환한다
int PrintK2NBwrd1(int k, int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할] ?
	[일반규칙] p(k,n) :: = print n, t=p(k,n-1),return t+n
	[진행방향] ?
	[중단조건] ? p(k,k) ::= print k, t=p(k,k-1),return t+k
	[단순해] ?
	***/
	if (k > n)
		return 0;
	printf("%d ", n);
	return PrintK2NBwrd1(k, n - 1) + n;
}

int PrintK2NBwrd2(int k, int n)		// 1개와 나머지 n-1개의 순환
{
	/***
	[분할] ?
	[일반규칙] p(n) ::= ?
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	if (k > n)
		return 0;
	int t = PrintK2NBwrd2(k + 1, n);
	printf("%d ", k);
	return t + k;
}
//반토막 내기
int PrintK2NBwrd3(int k, int n)		// n/2개, 1개, n/2개의 순환
{
	/***
	[분할] ?
	[일반규칙] p(k,n) :: =t1=, p(k,m-1), print m, t2= p(m+1,n), return t1+m+t2
	[진행방향] ?
	[중단조건] ?m=(k+n)/2=k
	[단순해] ? p(k,k) ::=t1=p(m+1,k),print k, t2=p(k,k-1),return t1+k+t2
	***/
	if(k>n)
	return 0;
	int m = (k + n) / 2;
	int t1 = PrintK2NBwrd3(m + 1, n);
	printf("%d ", m);
	int t2 = PrintK2NBwrd3(k,m-1);
	return t1 + m + t2;
}
int PrintK2NBwrd4(int k, int n)		// n/3개, 1개, n/3개,1개 n/3개,의 순환
{
	/***
	[분할] ?
	[일반규칙] p(k,n) :: =t1=, p(k,m-1), print m, t2= p(m+1,n), return t1+m+t2
	[진행방향] ?
	[중단조건] ?m=(k+n)/2=k
	[단순해] ? p(k,k) ::=t1=p(m+1,k),print k, t2=p(k,k-1),return t1+k+t2
	***/
	if (n-k<=1) {
		int nSum = 0;

		switch (n - k) {
		case 1:
			printf("%d ", n);
			nSum += n;
		case 0:
			printf("%d ", k);
			nSum += k;
		}
		return nSum;
	}
		
	int t = n - k + 1, m1 = k + t / 4, m2 = k + 2 * t / 4, m3 = k + 3 * t / 4;
	int t1 = PrintK2NBwrd3(m3 + 1, n);
	printf("%d ", m3);
	int t2 = PrintK2NBwrd3(m2 + 1, m3-1);
	printf("%d ", m2);
	int t3 = PrintK2NBwrd3(m1+1,m2-1);
	printf("%d ", m1);
	int t4 = PrintK2NBwrd3(k, m1 - 1);
	return t1 + m1 + t2 + m2 + t3+m3+t4;
}
/*k ? 5
n ? 10
 Print: 10 9 8 7 6 5
Return: 45

 Print: 10 9 8 7 6 5
Return: 45

 Print: 10 9 8 7 6 5
Return: 45

k ?*/
