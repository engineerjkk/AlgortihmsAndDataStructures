/* 유클리드 호제법에 의해 최대공약수를 구합니다. */
#include <stdio.h> 

/*--- 정수 x, y의 최대공약수를 반환 ---*/
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main(void)
{
	int x, y;
	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요 : ");
	scanf("%d", &x);
	printf("정수를 입력하세요 : ");
	scanf("%d", &y);

	printf("최대공약수는 %d입니다.\n", gcd(x, y));

	return 0;
}