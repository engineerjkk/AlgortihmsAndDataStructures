/* 1,000 ������ �Ҽ��� �����մϴ�(���� 2). */
#include <stdio.h>

int main(void)
{
	int i, n;
	int prime[500];					/* �Ҽ��� �����ϴ� �迭 */
	int ptr = 0; 			        /* �̹� ���� �Ҽ��� ���� */
	unsigned long counter = 0;		/* ������ Ƚ�� */
	
	prime[ptr++] = 2; 		        /* 2�� �Ҽ��Դϴ�. */
	for (n = 3; n <= 1000; n += 2) {		/* Ȧ������ ������� �մϴ�. */
		for (i = 1; i < ptr; i++) {			/* �̹� ���� �Ҽ��� �����ϴ�. */
			counter++;
			if (n % prime[i] == 0) 	/* ����������Ƿ� �Ҽ��� �ƴմϴ�. */
				break;				/* �� �̻��� �ݺ��� �ʿ� �����ϴ�. */
		}
	
		if (ptr == i) 			/* ���������� ����������� �ʾҴٸ� */
			prime[ptr++] = n; 	/* �迭�� �����մϴ�. */
	}
	
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	
	printf("�������� ������ Ƚ�� : %lu\n", counter);
	
	return 0;
}