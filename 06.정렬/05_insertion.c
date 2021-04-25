/* �ܼ� ���� ���� */
#include <stdio.h>
#include <stdlib.h>

/*--- �ܼ� ���� ���� �Լ� ---*/
void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x; 						/* �迭�� ù ��° ��ҿ� ���� ������ */
	puts("�ܼ� ���� ����");
	printf("��Ҽ� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); 	/* ����� ������ nx�� int�� �迭�� ���� */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);		/* �迭 x�� �ܼ� ���� ���� */
	
	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	
	free(x);				/* �迭�� ���� */
	
	return 0;
}