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

// 1���� n���� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintToNFwrd(int n)		// n-1���� ��ȯ�� ������ 1
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(n) ::= t=p(n-1),print n, return n+t
	[�������] 10->0
	[�ߴ�����] n�� 0�̵Ǹ� �ߴ�
	[�ܼ���] ?
	***/
	if (n == 0) {
		return 0;
	}
	int t = PrintToNFwrd(n - 1);
	printf("%d ", n);
	return n+t;
}
