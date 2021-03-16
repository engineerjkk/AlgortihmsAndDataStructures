// hanoi.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#pragma warning(disable: 4996)

void main()
{
	while (true) {
		int nCtr;
		printf("Disks ? ");
		scanf("%d", &nCtr);			// �ű�� ž�� ���� �Է� �޴´�.
		if (nCtr <= 0)
			break;
		void hanoi(int nDisk, int nFrom, int nTo);
		hanoi(nCtr, 1, 2);			// ž�� 1���� 2�� �ű�ÿ�.
		putchar(10);
	}
}

void hanoi(int nDisk, int nFrom, int nTo)
{
	if (nDisk == 1) {
		printf("%d-->%d\n", nFrom, nTo);
}
	else {
		int nTemp = 6 - nFrom - nTo;
		hanoi(nDisk - 1, nFrom, nTemp);// ���� n-1�� ���� �켱 ������ ��ġ�� �ǽ��صΰ�
		hanoi(1, nFrom, nTo);// �� �Ʒ� ���� �������� ����
		hanoi(nDisk - 1, nTemp, nTo);// �ǽ��� �� ���� n-1���� ���� �������� �ű��.
	}
	   /*2
		(1,1,3) 1->3
		(1,1,2) 1->2
		1,3,2 3->2*/


	
	
	
}
