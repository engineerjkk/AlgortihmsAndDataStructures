/* 세 정수의 값을 입력하고 중앙값을 구합니다. */
#include <stdio.h>

/*--- a, b, c의 중앙값을 구합니다. ---*/
int med3(int a, int b, int c)
{
	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}

int main(void)
{
	int a, b, c;

	printf("세 정수의 중앙값을 구합니다.\n");
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);
	printf("c의 값 : "); scanf("%d", &c);

	printf("중앙값은 %d입니다.\n", med3(a, b, c));

	return 0;
}