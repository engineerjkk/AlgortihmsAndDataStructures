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

// 1���� n���� �Ųٷ� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintToNBwrd(int n)		// n-1���� ��ȯ�� ������ 1
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(n) ::= print n,t p(n-1), return t+n
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	if (n == 1){
		printf("1");
	return 1;
}
	printf("%d ", n);
	int t = PrintToNBwrd(n - 1);
	return t + n;
}