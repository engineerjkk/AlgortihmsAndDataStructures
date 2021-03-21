#include <stdio.h>

#pragma warning(disable: 4996)
#define N	25

void main()
{
	int arr[N];
	for (int i = 0; i < N; i++)
		arr[i] = i + 101;
	while (1) {
		int n;
		printf("n ? ");
		scanf_s("%d", &n);
		if (n < 0 || n > N)
			break;
		int PrintArrayFwrd1(int a[], int n);
		int PrintArrayFwrd2(int a[], int n);
		int PrintArrayFwrd3(int a[], int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintArrayFwrd1(arr, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintArrayFwrd2(arr, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintArrayFwrd3(arr, n));
	}
}

// 배열에서 n개의 값들을 출력하고 그들의 합을 반환한다
int PrintArrayFwrd1(int a[], int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할] ?
	[일반규칙] p(a,n) ::= t=p(a,n-1),print a|n-1|,return t+a[n-1]
	[진행방향] ? n--
	[중단조건] ?n==0
	[단순해] ?print X,return 0
	***/
	if (n == 0)
		return 0;
	int t = PrintArrayFwrd1(a, n - 1);
	printf("%d ", a[n - 1]);
	return t + a[n - 1];
}

int PrintArrayFwrd2(int a[], int n)		// 1개와 나머지 n-1개의 순환
{
	/***
	[분할] ?
	[일반규칙] p(n) ::= print a[0], t=p(a+1,n-1),return t+a[0]
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	if (n == 0)
		return 0;
	printf("%d ", a[0]);
	return PrintArrayFwrd2(a + 1, n - 1) + a[0];
}

int PrintArrayFwrd3(int a[], int n)		// n/2개, 1개, n/2개의 순환
{
	/***
	[분할] ?
	[일반규칙] p(n) ::= m=n/2,t1=p(a,m-1),print a[m],t2=p(a+m+1,n-m-1,return t1+a[m]+t2	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	if (n == 0)
		return 0;
	int m = n / 2;
	int t1=PrintArrayFwrd3(a, m);
	printf("%d ", a[m]);
	int t2 = PrintArrayFwrd3(a + m + 1, n - m - 1);
	return t1 + a[m] + t2;
}