#include <stdio.h>
#include <string.h>
#include <math.h>

#define	N	30
#pragma warning( disable : 4996 )
void makeMagicSquare(int nMagicSqr[N][N], int nN);
void showMagicSquare(int nMagicSqr[N][N], int nN);
void checkMagicSquare(int nMagicSqr[N][N], int nN);
void main()
{
	int nMagicSqr[N][N];
	int nN; //입력받을 마방진값

	while (1) {
		printf("? ");
		scanf_s("%d", &nN);
		if (nN % 2 == 0 || nN > N)
			break;
		
		
		makeMagicSquare(nMagicSqr, nN);//마방진을 만들어라
		showMagicSquare(nMagicSqr, nN);//마방진을 출력하라
		checkMagicSquare(nMagicSqr, nN);//마방진을 체크하라
		printf("\n");
	}
	printf("Bye, ....\n");
}

void makeMagicSquare(int nMagicSqr[N][N], int nN)
{
	int nRow, nCol;
	for (nRow = 0; nRow < nN; nRow++)
		for (nCol = 0; nCol < nN; nCol++)
			nMagicSqr[nRow][nCol] = 0;//전부 초기화.

	nMagicSqr[nRow = 0][nCol = nN / 2] = 1;
	//0행 가운대에 1을 넣어준다.
	int nNmbr = 1, nCell = nN * nN;
	while (++nNmbr <= nCell) {
		int nPreRow = nRow, nPreCol = nCol;
		nRow = (nRow - 1 + nN) % nN;
		//nRow = nRow - 1; 이대로하면 음수가 나올 수 있으니, 음수가되면 결국 n-1이되게 만들었다.
		nCol = (nCol + 1) % nN; //오버플로우를 방지하기 위해 nN의 나머지연산을 취한다.
		//nCol = nCol + 1; 이대로하면 오버플러우가 될수있음
		//기본적으로 +1을 동북쪽으로 간다. 
		if (nMagicSqr[nRow][nCol]) //이미 숫자값이 있다면,남쪽으로간다.
		{
			nRow = (nPreRow + 1) % nN;//아래 행으로 이동.
			nCol = nPreCol; //열은 그래도 있으니 바뀌지않는다.


		}

		nMagicSqr[nRow][nCol] = nNmbr;
	}

}

void showMagicSquare(int nMagicSqr[N][N], int nN)
{
	printf("\n[마방진]\n");

	for(int nRow=0;nRow<nN;nRow++){
		for (int nCol=0; nCol < nN; nCol++) {
			printf("%3d", nMagicSqr[nRow][nCol]);
		}
		putchar('\n');
	}
		
		
	
}

void checkMagicSquare(int nMagicSqr[N][N], int nN)
{
	void checkMagicSquareRow(int nMagicSqr[N][N], int nN);
	void checkMagicSquareCol(int nMagicSqr[N][N], int nN);
	void checkMagicSquareDgl(int nMagicSqr[N][N], int nN, int nDir);
	checkMagicSquareRow(nMagicSqr, nN);
	checkMagicSquareCol(nMagicSqr, nN);
	printf("\n[대각선 검사]\n");
	checkMagicSquareDgl(nMagicSqr, nN, '\\');
	checkMagicSquareDgl(nMagicSqr, nN, '/');
}

void checkMagicSquareRow(int nMagicSqr[N][N], int nN)
{
	printf("\n[행 검사]\n");
	//
	for (int nRow=0; nRow < nN; nRow++) {
		printf("행%2d: ", nRow);
		int nSum = 0;
		for (int nCol = 0; nCol < nN; nCol++) {
			if (nCol)
				printf(" + ");
			printf("%2d", nMagicSqr[nRow][nCol]);
			nSum += nMagicSqr[nRow][nCol];
			}
		printf(" = %d\n", nSum);
		
		
	 }
	
}
//
void checkMagicSquareCol(int nMagicSqr[N][N], int nN)
{
	printf("\n[열 검사]\n");
	for (int nCol = 0; nCol < nN; nCol++) {
		printf("열%2d: ", nCol);
		int nSum = 0;
		for (int nRow = 0; nRow < nN; nRow++) {
			if (nRow)
				printf(" + ");
			printf("%2d", nMagicSqr[nRow][nCol]);
			nSum += nMagicSqr[nRow][nCol];
		}
		printf(" = %d\n", nSum);
	}
	
}

void checkMagicSquareDgl(int nMagicSqr[N][N], int nN, int nDir)
{
	printf("대 %c: ",nDir);
	int nSum = 0;
	if (nDir == '\\') {
		for (int i = 0; i < nN; i++) {
			if (i)
				printf(" + ");
			printf("%2d", nMagicSqr[i][i]);
			nSum += nMagicSqr[i][i];
		}
		printf(" = %d\n", nSum);
	}
	else {
		for (int i = 0; i < nN; i++) {
			if (i)
				printf(" + ");
			printf("%2d", nMagicSqr[i][nN-i-1]);
			nSum += nMagicSqr[i][nN-i-1];
		}
		printf(" = %d\n", nSum);
	}

}

/*****
? 5

[마방진]
17  24   1   8  15
23   5   7  14  16
 4   6  13  20  22
10  12  19  21   3
11  18  25   2   9

[행 검사]
행 0: 17 + 24 +  1 +  8 + 15 = 65
행 1: 23 +  5 +  7 + 14 + 16 = 65
행 2:  4 +  6 + 13 + 20 + 22 = 65
행 3: 10 + 12 + 19 + 21 +  3 = 65
행 4: 11 + 18 + 25 +  2 +  9 = 65

[열 검사]
열 0: 17 + 23 +  4 + 10 + 11 = 65
열 1: 24 +  5 +  6 + 12 + 18 = 65
열 2:  1 +  7 + 13 + 19 + 25 = 65
열 3:  8 + 14 + 20 + 21 +  2 = 65
열 4: 15 + 16 + 22 +  3 +  9 = 65

[대각선 검사]
대 \: 17 +  5 + 13 + 21 +  9 = 65
대 /: 15 + 14 + 13 + 12 + 11 = 65

? 0
Bye, ....
*****/