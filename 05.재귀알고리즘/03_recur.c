/* ��Ϳ� ���� ���� �����ϱ� ���� ��� �Լ� */
#include <stdio.h > 

/*--- ��� �Լ� recur( ) ---*/
void recur(int n)
{
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

int main(void)
{
	int x;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	
	recur(x);

	return 0;
}