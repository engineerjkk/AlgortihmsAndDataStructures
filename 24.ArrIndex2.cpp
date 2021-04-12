#include <stdio.h>

#define	N1	9
#define	N2	8
#define	N3	7
#define	N4	6
#pragma warning (disable: 4996)

void main()
{
	int B[N1][N2][N3][N4];//4차우너 배열을 반들어놨다.
	int nBound[4] = {N1, N2, N3, N4};

	for (int i = 0; i < nBound[0]; i++)
		for (int j = 0; j < nBound[1]; j++)
			for (int k = 0; k < nBound[2]; k++)
				for (int l = 0; l < nBound[3]; l++)
					B[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l;
	while (1) {
		int i, j, k, l, nValue;
		printf("index> ");
		scanf("%d", &i);
		if (i < 0)
			break;
		scanf("%d", &j);
		scanf("%d", &k);
		scanf("%d", &l);
		int Aij(int A[], int i, int j, int k, int l, int nBound[], int &nValue);
		if (Aij((int *)B, i, j, k, l, nBound, nValue))
			printf("A[%d][%d][%d][%d] = %d(%d)\n", i, j, k, l, B[i][j][k][l], nValue);
		else
			printf("색인 오류, ....\n");
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int A[], int i, int j, int k, int l, int nBound[], int &nValue)
{	// 적절한 색인이면 nValue에 값을 저장하고 T/F를 반환한다.
	if (i < 0 || i >= nBound[0] ||
		j < 0 || j >= nBound[1] ||
		k < 0 || k >= nBound[2] ||
		l < 0 || l >= nBound[3])
		return false;
	int ndx = i * nBound[1] * nBound[2] * nBound[3] +
		j * nBound[2] * nBound[3] +
		k * nBound[3] +
		l;
	nValue = A[ndx];
	return true;
}
