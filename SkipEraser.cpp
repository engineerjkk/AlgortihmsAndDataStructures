#include <stdio.h>

#pragma warning(disable: 4996)
#define N	1000


void main()
{
	while (1) {
		printf("? ");
		int n;
		scanf_s("%d", &n);
		if (n <= 0 || n > N)
			break;
		int SkipEraser1(int n);
		int SkipEraser2(int n);
		//printf("Simulation: %d\n",   SkipEraser1(n));
		printf(" Recursion: %d\n\n", SkipEraser2(n));
	}
	printf("Bye, ...\n");
}

int SkipEraser1(int n)
{
	int nNecklace[N];											// ����̸� �迭�� �����Ѵ�(0���� n-1����)
	for (int i = 0; i < n; i++)									//�����  n���� ������ 1���� n���� �ʱ�ȭ �Ѵ�
		nNecklace[i] = i + 1;
	while (n > 1) {
		//
		// �ѹ��� ȸ���ϸ鼭 �����Ѵ�
		//
	}
	return nNecklace[0];
}

int SkipEraser2(int n)									// ��ȯ �Լ��� �ۼ�
{
	if (n == 1)
		return 1;
	//return 2 * SkipEraser2(n / 2) + (n % 2) ?  1 : -1;
	//Ȧ���϶����� 1 ¦���ϋ����� -1 
	return 2 * SkipEraser2(n / 2) + (n % 2) * 2 - 1;
}
