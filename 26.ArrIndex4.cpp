#include <stdio.h>

#define	N1	9
#define	N2	8
#define	N3	7
#define	N4	8
#define DIM	4 //4차원
#pragma warning( disable: 4996 )
//거꾸로 가는 프로그램입니다.
void main()
{
	int B[N1][N2][N3][N4]; //배열 크기 정의
	int nArrDesc[2 * DIM + 1] = {DIM, 0, 0, 0, 0, N1, N2, N3, N4};//배열 디스ㅡ크리트만들기 4차원입니다.
	/// <summary>
	/// 0000은 색인이고 N은 크기입니다. 그래서 차원의 두배+1입니다. 크기는 ㅈ어져있고 색인은 읽ㅇ어드린다. 
	/// </summary>
	int nDim = DIM;
	int *nNdx = nArrDesc + 1;
	int *nBound = nArrDesc + 1 + DIM;
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
			scanf_s("%d", nNdx + i);
			if (i == 0 && nNdx[i] < 0)
				IsOK = false;
		}
		if (IsOK) {
			int Aij(int A[], int nArrDesc[], int &nValue);
			if (Aij((int *)B, nArrDesc, nValue))
				printf("A[%d][%d][%d][%d] = %d(%d)\n",
					nNdx[0], nNdx[1], nNdx[2], nNdx[3], B[nNdx[0]][nNdx[1]][nNdx[2]][nNdx[3]], nValue);
			else
				printf("색인 오류, ....\n");
			putchar('\n');
		}
	}
	printf("Bye, ....\n\n");
}

int Aij(int A[], int nArrDesc[], int &nValue)
{	// 적절한 색인이면 nValue에 색인에 대한 배열의 값을 저장하고 T/F를 반환한다.
	// 알다시피 차원에 따라 식이 달라지기 때문에, 대신 for loop를 사용하여 식을 계산하라.
	// 아래와 같이 색인의 순서를 거꾸로 계산을 한다.
	// nNdx[3] * nSize +		;; nSize = 1; 사이즈가 1부터 시작하면서 바운드를 곱해줍니다. 
	// nNdx[2] * nSize +		;; nSize = nBound[3]
	// nNdx[1] * nSize +		;; nSize = nBound[2] * nBound[3]
	// nNdx[0] * nSize			;; nSize = nBound[1] * nBound[2] * nBound[3]
	int n = 0, nSize = 1;//n은 0으로 초기화시켜놓고 계속 더해준다. 
	int nDim = nArrDesc[0], *arNdx = nArrDesc + 1, *arBound = nArrDesc + 1 + nDim;
	for (int i = nDim - 1; i >= 0; i--) {//전체 식 더하기
		if (arNdx[i] < 0 || arNdx[i] >= arBound[i])
			return false;
		n += arNdx[i] * nSize;
		nSize *= arBound[i];//전체 사이즈 계산
	}
	nValue = A[n];
	return true;
}
