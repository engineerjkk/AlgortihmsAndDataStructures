/* 
	���ϴ� ������ŭ �����͸� �Է��ϰ�, 
	����� ������ n�� �迭�� �ֱٿ� �Է��� n���� ���� 
*/

#include <stdio.h>
#define N 10			/* �����ϴ� �������� ���� */

int main()
{
	int i;
	int a[N];		/* �Է��� �����͸� ���� */
	int cnt = 0;	/* �Է��� �������� ���� */
	int retry;		/* �ٽ� �� ��? */

	puts("������ �Է��ϼ���.");

	do {
		printf("%d��° ���� : ", cnt + 1);
		scanf("%d", &a[cnt++ % N]);
		printf("����ұ��? (Yes �� 1/No �� 0) : ");
		scanf("%d", &retry);
	} while (retry == 1);
		i = cnt - N;
		if (i < 0) i = 0;
		
	for (; i < cnt; i++)
		printf("%2d��° ���� = %d\n", i + 1, a[i % N]);
		
	return 0;
}