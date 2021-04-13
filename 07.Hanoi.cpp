// hanoi.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#pragma warning(disable: 4996)

void main()
{
	while (true) {
		int nCtr;
		printf("Disks ? ");
		scanf("%d", &nCtr);			// 옮기는 탑의 층을 입력 받는다.
		if (nCtr <= 0)
			break;
		void hanoi(int nDisk, int nFrom, int nTo);
		hanoi(nCtr, 1, 2);			// 탑을 1에서 2로 옮기시요.
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
		hanoi(nDisk - 1, nFrom, nTemp);// 위의 n-1개 층을 우선 나머지 위치로 피신해두고
		hanoi(1, nFrom, nTo);// 맨 아래 층을 목적지로 욺기고
		hanoi(nDisk - 1, nTemp, nTo);// 피신해 둔 위의 n-1개의 층을 목적지로 옮긴다.
	}
	   /*2
		(1,1,3) 1->3
		(1,1,2) 1->2
		1,3,2 3->2*/


	
	
	
}
