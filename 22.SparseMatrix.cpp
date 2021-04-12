#include <stdio.h>

#define MAX_COL	20
#define MAX_TERMS MAX_COL+1	/* max number of terms + 1 */
#pragma warning (disable: 4996)

typedef struct {
	int row;
	int col;
	int value;
}	Term;

void Transpose(Term a[], Term b[]);
void FastTranspose(Term a[], Term b[]);
void PrintSparseMatrix(Term a[]);

void main()
{
	Term a[MAX_TERMS] = {
			{7, 6, 8 },//row , col, value �̴�. 
			{0, 0, 15},
			{0, 3, 22},
			{0, 5,-15},
			{1, 1, 11},
			{1, 2, 3 },
			{2, 3,-6 },
			{4, 0, 91},
			{5, 2, 28},};
	Term b[MAX_TERMS];
	
	int bOK = 1;
	while (bOK) {//true�ε��ȿ�
		printf("1:Trans, 2:FastTrans, 3:Print a, 4:Print b, 5:Exit ? ");//O(mn^2),O(mn) ����Կ��� �����
		int nCmnd;
		scanf_s ("%d", &nCmnd);//����Ʈ �Է��� �ް�,
		switch (nCmnd) {
		case 1:
			for (int i = 0; i <= a[0].value; i++)
				b[i].row = b[i].col = b[i].value = -1;
			Transpose(a, b);
			PrintSparseMatrix(b);
			break;
		case 2:
			for (int i = 0; i <= a[0].value; i++)
				b[i].row = b[i].col = b[i].value = -1;
			FastTranspose(a, b);
			PrintSparseMatrix(b);
			break;
		case 3:
			PrintSparseMatrix(a);
			break;
		case 4:
			PrintSparseMatrix(b);
			break;
		case 5:
			bOK = 0;
			break;
		default:
			printf("Invalid Command ....\n");
		}
		putchar('\n');
	}
	printf("Bye, ....\n\n");
} 

void Transpose(Term a[], Term b[])  //��ġ��ķ� �ٲߴϴ�.
{	/* b is set to the transpose of a */
	int n = a[0].value;			/* total number of elements */
	b[0].row = a[0].col;	/* rows in b = columns in a */  
	b[0].col = a[0].row; 	/* columns in b = rows in a */  
   	b[0].value = n;          //    
	if (n > 0) { 			/* non zero matrix */    
		//???
		int nNdxB = 1;
		for (int i = 0; i < a[0].col; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[j].col == i) {
					b[nNdxB].row = a[j].col;
					b[nNdxB].col = a[j].row;
					b[nNdxB++].value = a[j].value;
				}
			}
		}
	} 
}

void FastTranspose(Term a[], Term b[])
{	/* the transepose of a is placed in b */ 
	int nRowCtr[MAX_COL], nStartPos[MAX_COL];
	int nNoCols = a[0].col, nNoTerms = a[0].value;
	b[0].row = nNoCols; b[0].col = a[0].row;
	b[0].value = nNoTerms;
	if (nNoTerms > 0) {	/* nonzero matrix */
		// nRowCtr�� �ʱ�ȭ
		for (int i=0;i<nNoCols;i++)
			nRowCtr[i]=0;
		// ���� ������ ����
		for (int i=1;i<=nNoTerms;i++)
			nRowCtr[a[i].col]++;
		nStartPos[0] = 1;		// 1���� ����
		// ���� ��ġ�� ����Ѵ�
		for (int i=1;i<nNoCols;i++)
			nStartPos[i]=nStartPos[i-1]+nRowCtr[i-1];
		// �ϳ��� ��ġ�Ͽ� �ùٸ� ��ġ�� �ִ´�
 		for (int i=1;i<=nNoTerms;i++) {
   			int j=nStartPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
			
		}                 
	}
}

void PrintSparseMatrix(Term a[])
{
	int M = a[0].row;
	printf("M : %d\n", M);
	int N = a[0].col;
	printf("N : %d\n", N);
	int t = a[0].value;
	printf("t : %d\n", t);
	int k = 1, nValue;
	for (int i = 0; i < M; i++) {//0~6���� �� 7
		for (int j = 0; j < N; j++) {//0~5���� �� 6
			nValue = (k <= t && i == a[k].row && j == a[k].col) ? a[k++].value : 0;
			//����� ���� 1���� ũ�鼭 ���� i�Ͱ��� ���� j�� ������ a�� ���� ���س��� �ƴϸ� 0���� 
			//7 6 8 �̴ϱ� 
			//ù�� ù�� ���� : k=1�� 8���� �����鼭,a[1]==0�� i�� 0�� �����鼭 a[1]=0�� j==0�� ������  a[1].value 
			printf("%4d", nValue);
		}
		printf("\n");// ��������� ���� ��� i�� 0�϶� N���� 1�� ����ϰ�~ i�� 1�϶� N���� 2�� ����ϰ�~
	}
	printf("M : %d\n", M);
	printf("N : %d\n", N);
	printf("t : %d\n", t);
}