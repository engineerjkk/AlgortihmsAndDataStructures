/* �� ���� (���� 2 : h = ��, 13, 4, 1) */
#include <stdio.h>
#include <stdlib.h>

/*--- �� ���� �Լ� (���� 2 : h = ��, 13, 4, 1) ---*/
void shell(int a[], int n)
{
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;
	
	for (; h > 0; h /= 3)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];
			a[j + h] = tmp;
		}
}

int main(void)
{
	int i, nx;
	int *x;				/* �迭�� ù ��° ��ҿ� ���� ������ */

	puts("�� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);			/* �迭 x�� �� ���� */

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);				/* �迭�� ���� */
	
	return 0;
}