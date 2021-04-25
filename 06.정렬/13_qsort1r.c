/* qsort �Լ��� ����Ͽ� ���� �迭�� ��Ҹ� ������������ ���� */
#include <stdio.h> 
#include <stdlib.h> 

/*--- int �� �� �Լ�(�������� ���Ŀ�) ---*/
int int_cmpr(const int * a, const int * b)
{
	if (*a < *b)
		return 1;
	else if (*a > * b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int i, nx;
	int * x; /* �迭�� ù ��° ��ҿ� ���� ������ */

	printf("qsort�� ���� ����\n");
	printf("��Ҽ� :");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); /* ��Ҽ� nx�� int �� �迭�� ���� */

	for (i = 0; i < nx; i++) {
		printf("x[%d] :", i);
		scanf("%d", &x[i]);
	}

	qsort(x,												/* �迭 */
	    nx,													/* ��Ҽ� */
		sizeof(int),										/* ����� ũ�� */
		(int (*)(const void *, const void *)) int_cmpr		/* �� �Լ� */
	);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x); /* �迭�� ���� */

	return 0;
}