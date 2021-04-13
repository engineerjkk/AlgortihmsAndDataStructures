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
	int nNecklace[N];											// 목걸이를 배열로 정의한다(0에서 n-1까지)
	for (int i = 0; i < n; i++)									//목걸이  n개의 구슬을 1에서 n까지 초기화 한다
		nNecklace[i] = i + 1;
	while (n > 1) {
		//
		// 한바퀴 회전하면서 삭제한다
		//
	}
	return nNecklace[0];
}

int SkipEraser2(int n)									// 순환 함수로 작성
{
	if (n == 1)
		return 1;
	//return 2 * SkipEraser2(n / 2) + (n % 2) ?  1 : -1;
	//홀수일때에는 1 짝수일에는 -1 
	return 2 * SkipEraser2(n / 2) + (n % 2) * 2 - 1;
}
