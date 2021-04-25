/* �迭 ��Ҹ� �������� �����մϴ�. */
#include <stdio.h>
#include <stdlib.h>

/*--- type���� x�� y ���� ��ȯ ---*/
#define swap(type, x, y) do { type t = x; x = y; y = t;} while (0)

/*--- ��� ������ n�� �迭 a�� ��Ҹ� �������� ���� ---*/
void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
	swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
	int i;
	int *x; 		/* �迭 ù ��° ����� ������ */
	int nx; 		/* �迭 x�� ��� ���� */

	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); 	/* ��� ������ nx�� int�� �迭 x�� ���� */

	printf("%d���� ������ �Է��ϼ���.\n", nx);
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_reverse(x, nx); 		/* �迭 x�� ��Ҹ� �������� ���� */
	printf("�迭�� ��Ҹ� �������� �����߽��ϴ�.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	
	free(x); 			/* �迭 x�� ���� */

	return 0;
}