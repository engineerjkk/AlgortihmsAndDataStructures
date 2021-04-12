
#include <stdio.h>

#define	N1	9
#define	N2	8
#define	N3	7
#define	N4	6
#define DIM	4
#pragma warning (disable: 4996)

void main()
{
	int B[N1][N2][N3][N4];
	int nNdx[DIM], nBound[DIM] = {N1, N2, N3, N4};

	for (int i = 0; i < nBound[0]; i++)
		for (int j = 0; j < nBound[1]; j++)
			for (int k = 0; k < nBound[2]; k++)
				for (int l = 0; l < nBound[3]; l++)
					B[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l;
	int IsOK = true;
	while (IsOK) {
		int nValue;
		printf("index> ");
		for (int i = 0; i < DIM && IsOK; i++) {
			scanf("%d", nNdx + i);
			if (i == 0 && nNdx[i] < 0)
				IsOK = false;
		}
		if (IsOK) {
			int Aij(int A[], int nDim, int nNdx[], int nBound[], int &nValue);
			if (Aij((int *)B, DIM, nNdx, nBound, nValue))
				printf("A[%d][%d][%d][%d] = %d(%d)\n",
					nNdx[0], nNdx[1], nNdx[2], nNdx[3], B[nNdx[0]][nNdx[1]][nNdx[2]][nNdx[3]], nValue);
			else
				printf("색인 오류, ....\n");
			putchar('\n');
		}
	}
	printf("Bye, ....\n\n");
}

int Aij(int A[], int nDim, int nNdx[], int nBound[], int &nValue)
{	// 적절한 색인이면 nValue에 값을 저장하고 T/F를 반환한다.
	// 알다시피 차원에 따라 식이 달라지기 때문에, 대신 for loop를 사용하여 식을 계산하라.
	// 						;; nSize = nBound[3] * nBound[2] * nBound[1] * nBound[0]
	// nNdx[0] * nSize +	;; nSize = nBound[3] * nBound[2] * nBound[1]
	// nNdx[1] * nSize +	;; nSize = nBound[3] * nBound[2]
	// nNdx[2] * nSize +	;; nSize = nBound[3]
	// nNdx[3] * nSize		;; nSize = 1
	for (int i = 0; i < nDim; i++)
		if (nNdx[i] < 0 || nNdx[i] >= nBound[i])
			return false;
	int nSize = 1;
	for (int i = 0; i < nDim; i++)
		nSize *= nBound[i];
	int n = 0;
	for (int i = 0; i < nDim; i++) {
		nSize /= nBound[i];
		n += nNdx[i] * nSize;
	}
	nValue = A[n];
	return true;
}
