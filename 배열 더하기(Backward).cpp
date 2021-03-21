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
		scanf("%d", &n);
		if (n < 0 || n > N)
			break;
		int PrintArrayBwrd1(int a[], int n);
		int PrintArrayBwrd2(int a[], int n);
		int PrintArrayBwrd3(int a[], int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintArrayBwrd1(arr, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintArrayBwrd2(arr, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintArrayBwrd3(arr, n));
	}
}

// �迭���� n���� ������ �Ųٷ� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintArrayBwrd1(int a[], int n)		// n-1���� ��ȯ�� ������ 1
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	if (n == 0)
		return 0;
	printf("%d ", a[n - 1]);
	return PrintArrayBwrd1(a, n - 1) + a[n - 1];
}

int PrintArrayBwrd2(int a[], int n)		// 1���� ������ n-1���� ��ȯ
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	if(n==0)
		return 0;
	int t = PrintArrayBwrd2(a + 1, n - 1);
	printf("%d ", a[0]);
	return t + a[0];
}

int PrintArrayBwrd3(int a[], int n)		// n/2��, 1��, n/2���� ��ȯ
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	if (n == 0)
		return 0;
	int m = n / 2;
	int t = PrintArrayBwrd3(a + m + 1, n - m - 1);
	printf("%d ", a[m]);
	return PrintArrayBwrd3(a, m) + a[m] + t;
}