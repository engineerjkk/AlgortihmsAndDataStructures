/* bsearch �Լ��� ����� ����ü �迭������ �˻� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10]; 		/* �̸� */
	int height; 		/* Ű */
	int weight; 		/* ������ */
} Person;

/*--- Person���� �� �Լ�(������������ �̸� ����) ---*/
int npcmp(const Person *x, const Person *y)
{
	return strcmp(x->name, y->name);
}
int main(void)
{
	Person x[] = {					/* �迭 ��Ҵ� �̸��� ������������ */
		{ "�迵��", 179, 79 }, 		/* ���ĵǾ� ���� ������ �� �˴ϴ�. */
		{ "������", 172, 63 },
		{ "�̼���", 176, 52 },
		{ "������", 165, 51 },
		{ "������", 181, 73 },
		{ "ȫ����", 172, 84 },
	};
	int nx = sizeof(x) / sizeof(x[0]); 		/* �迭 x�� ����� ���� */
	int retry;

	puts("�̸����� �˻��մϴ�.");
	do {
		Person temp, *p;
		printf("�̸� : ");
		scanf("%s", temp.name);
		p = bsearch(&temp, x, nx, sizeof(Person),
			(int(*)(const void *, const void *)) npcmp);

		if (p == NULL)
			puts("�˻��� �����߽��ϴ�.");
		else {
			puts("�˻� ���� !! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.");
			printf("x[%d] : %s %dcm %dkg\n",
				(int)(p - x), p->name, p->height, p->weight);
		}

		printf("�ٽ� �˻��ұ��? (1) �� / (0) �ƴϿ� : ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}