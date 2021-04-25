/* ������ 2���� ~ 36������ ��� ��ȯ */
#include <stdio.h>

/*--- ���� �� x�� n������ ��ȯ�Ͽ� �迭 d�� �Ʒ��ڸ����� ���� ---*/
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0; 			/* ��ȯ �� �ڸ��� */

	if (x == 0) 				/* 0�̸� */
		d[digits++] = dchar[0]; 		/* ��ȯ �Ŀ��� 0 */
	else
		while (x) {
			d[digits++] = dchar[x % n]; 	/* n���� ���� �������� ���� */
			x /= n;
		}

	return digits;
}

int main(void)
{
	int i;
	unsigned no; 		/* ��ȯ�ϴ� ���� */
	int cd;				/* ��� */
	int dno;			/* ��ȯ �� �ڸ��� */
	char cno[512]; 		/* ��ȯ�� ���� �� �ڸ��� ���ڸ� �����ϴ� ���� �迭 */
	int retry;			/* �� �� ��? */

	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf("%u", &no);

		do {
			printf("� ������ ��ȯ�ұ��? (2-36) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd> 36);

		dno = card_convr(no, cd, cno); 		/* no�� cd������ ��ȯ */

		printf("%d�����δ�", cd);
		for (i = dno - 1; i >= 0; i--) 		/* ���ڸ����� ���ʷ� ��� */
			printf("%c", cno[i]);
		printf("�Դϴ�.\n");

		printf("�� �� �� �ұ��? (1 �� �� /0 �� �ƴϿ�) : ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}