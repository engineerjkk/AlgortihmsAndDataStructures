/* �� ����(�迭�� ���� ������ ǥ��) */
#include <stdio.h> 
#include <stdlib.h> 

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

/*--- �� ����(�迭�� ���� ������ ǥ��) ---*/
void quick(int a[], int left, int right)
{
	int pl = left;				/* ���� Ŀ�� */
	int pr = right;				/* ������ Ŀ�� */
	int x = a[(pl + pr) / 2];	/* ��(��� ���) */

	int i;
	printf("a[%d] ~ a[%d] : {", left, right);
	for (i = left; i < right; i++)
		printf("%d", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

int main(void)
{
	int i, nx;
	int * x; /* �迭�� ù ��° ��ҿ� ���� ������ */

	puts("�� ����");
	printf("��ڼ� :");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] :", i);
		scanf("%d", &x[i]);
	}

	quick(x, 0, nx - 1);		/* �迭 x�� �� ���� */

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);					/* �迭�� ���� */

	return 0;
}