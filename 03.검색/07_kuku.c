/* ����ǥ�� ����ǥ */
#include <stdio.h>

/*--- x1�� x2�� ���� ���մϴ�. ---*/
int sum(int x1, int x2)
{
	return x1 + x2;
}

/*--- x1�� x2�� ���� ���մϴ�. ---*/
int mul(int x1, int x2)
{
	return x1 * x2;
}

/*--- ����, ����ǥ�� ��� ---*/
void kuku(int(*calc)(int, int))
{
	int i, j;
	
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++)
			printf("%3d", (*calc)(i, j));
		putchar('\n');
	}
}

int main(void)
{
	puts("����ǥ");
	kuku(sum);
	
	puts("\n ����ǥ");
	kuku(mul);

	return 0;
}