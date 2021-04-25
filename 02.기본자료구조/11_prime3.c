/* 1,000 ������ �Ҽ��� ���մϴ�(���� 3). */
#include <stdio.h>

int main(void)
{
	int i, n;
	int prime[500];				/* �Ҽ��� �����ϴ� �迭 */
	int ptr = 0; 				/* �̹� ���� �Ҽ��� ���� */
	unsigned long counter = 0;	/* ������ �������� Ƚ�� */
	
	prime[ptr++] = 2; 			/* 2�� �Ҽ��Դϴ� */
	prime[ptr++] = 3; 			/* 3�� �Ҽ��Դϴ� */
	for (n = 5; n <= 1000; n += 2) {		/* Ȧ������ ������� �մϴ�. */
		int flag = 0;
		for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
			counter++;
			if (n % prime[i] == 0) {	/* ����������� �Ҽ��� �ƴմϴ�. */
				flag = 1;
				break; 		/* �� �̻��� �ݺ��� �ʿ� �����ϴ�. */
			}
		}
	
		if (!flag) 		/* ���������� ����������� �ʾҽ��ϴ�. */
			prime[ptr++] = n; 	/* �迭�� ���� */
	}
	
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	
	printf("������ �������� ������ Ƚ�� : %lu\n", counter);
	
	return 0;
}