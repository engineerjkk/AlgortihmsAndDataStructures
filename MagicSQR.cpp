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
	int nN; //�Է¹��� ��������

	while (1) {
		printf("? ");
		scanf_s("%d", &nN);
		if (nN % 2 == 0 || nN > N)
			break;
		
		
		makeMagicSquare(nMagicSqr, nN);//�������� ������
		showMagicSquare(nMagicSqr, nN);//�������� ����϶�
		checkMagicSquare(nMagicSqr, nN);//�������� üũ�϶�
		printf("\n");
	}
	printf("Bye, ....\n");
}

void makeMagicSquare(int nMagicSqr[N][N], int nN)
{
	int nRow, nCol;
	for (nRow = 0; nRow < nN; nRow++)
		for (nCol = 0; nCol < nN; nCol++)
			nMagicSqr[nRow][nCol] = 0;//���� �ʱ�ȭ.

	nMagicSqr[nRow = 0][nCol = nN / 2] = 1;
	//0�� ����뿡 1�� �־��ش�.
	int nNmbr = 1, nCell = nN * nN;
	while (++nNmbr <= nCell) {
		int nPreRow = nRow, nPreCol = nCol;
		nRow = (nRow - 1 + nN) % nN;
		//nRow = nRow - 1; �̴���ϸ� ������ ���� �� ������, �������Ǹ� �ᱹ n-1�̵ǰ� �������.
		nCol = (nCol + 1) % nN; //�����÷ο츦 �����ϱ� ���� nN�� ������������ ���Ѵ�.
		//nCol = nCol + 1; �̴���ϸ� �����÷��찡 �ɼ�����
		//�⺻������ +1�� ���������� ����. 
		if (nMagicSqr[nRow][nCol]) //�̹� ���ڰ��� �ִٸ�,�������ΰ���.
		{
			nRow = (nPreRow + 1) % nN;//�Ʒ� ������ �̵�.
			nCol = nPreCol; //���� �׷��� ������ �ٲ����ʴ´�.


		}

		nMagicSqr[nRow][nCol] = nNmbr;
	}

}

void showMagicSquare(int nMagicSqr[N][N], int nN)
{
	printf("\n[������]\n");

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
	printf("\n[�밢�� �˻�]\n");
	checkMagicSquareDgl(nMagicSqr, nN, '\\');
	checkMagicSquareDgl(nMagicSqr, nN, '/');
}

void checkMagicSquareRow(int nMagicSqr[N][N], int nN)
{
	printf("\n[�� �˻�]\n");
	//
	for (int nRow=0; nRow < nN; nRow++) {
		printf("��%2d: ", nRow);
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
	printf("\n[�� �˻�]\n");
	for (int nCol = 0; nCol < nN; nCol++) {
		printf("��%2d: ", nCol);
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
	printf("�� %c: ",nDir);
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

[������]
17  24   1   8  15
23   5   7  14  16
 4   6  13  20  22
10  12  19  21   3
11  18  25   2   9

[�� �˻�]
�� 0: 17 + 24 +  1 +  8 + 15 = 65
�� 1: 23 +  5 +  7 + 14 + 16 = 65
�� 2:  4 +  6 + 13 + 20 + 22 = 65
�� 3: 10 + 12 + 19 + 21 +  3 = 65
�� 4: 11 + 18 + 25 +  2 +  9 = 65

[�� �˻�]
�� 0: 17 + 23 +  4 + 10 + 11 = 65
�� 1: 24 +  5 +  6 + 12 + 18 = 65
�� 2:  1 +  7 + 13 + 19 + 25 = 65
�� 3:  8 + 14 + 20 + 21 +  2 = 65
�� 4: 15 + 16 + 22 +  3 +  9 = 65

[�밢�� �˻�]
�� \: 17 +  5 + 13 + 21 +  9 = 65
�� /: 15 + 14 + 13 + 12 + 11 = 65

? 0
Bye, ....
*****/