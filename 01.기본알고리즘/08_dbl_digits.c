/* 2�ڸ��� ��� (10~99)�� �Է��մϴ�. */
#include <stdio.h>

int main(void)
{
	int no;
	printf("2�ڸ� ������ �Է��ϼ���.\n");

	do {
		printf("���� : ");
		scanf("%d", &no);
	} while (no < 10 || no > 99);

	printf("���� no ���� %d�� �Ǿ����ϴ�.\n", no);

	return 0;
}