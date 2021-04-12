#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4996)

void main()
{
	int B[SIZE][SIZE][SIZE][SIZE];//4차원 배열을 반들어놨다.

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			for (int k = 0; k < SIZE; k++)
				for (int l = 0; l < SIZE; l++)
					B[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l;
	while (1) { 
		int i, j, k, l, nValue;
		printf("index> ");
		scanf_s("%d", &i);
		if (i < 0)
			break;
		scanf_s("%d", &j);
		scanf_s("%d", &k);
		scanf_s("%d", &l);
		int Aij(int A[], int i, int j, int k, int l, int n, int &nValue); //ijk에 들은 값을 nValue에 넣을거임
		if (Aij((int *)B, i, j, k, l, SIZE, nValue))
			printf("A[%d][%d][%d][%d] = %d(%d)\n", i, j, k, l, B[i][j][k][l], nValue);
		else
			printf("색인 오류, ....\n");
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int A[], int i, int j, int k, int l, int n, int &nValue)
{	// 적절한 색인이면 nValue에 값을 저장하고 T/F를 반환한다.
	if (i < 0 || i >= n || j < 0 || j >= n || k < 0 || k >= n || l < 0 || l >= n)
		return false;//실패한경우이니 false를 리턴한다. 
	nValue = 
		A[i * n * n * n 
		+ j * n * n 
		+ k * n 
		+ l];
	//
	return true;
}
