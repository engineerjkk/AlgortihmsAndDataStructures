/* int�� ���� IntStack�� ��� */
#include <stdio.h>
#include "IntStack.h"

int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x;

		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) Ǫ�� (2) �� (3) ��ũ (4) ��� (0) ���� : ");
		scanf("%d", &menu);
		if (menu == 0) break;
		
		switch (menu) {
		case 1: /*--- Ǫ��---*/
			printf("������ : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;
		
		case 2: /*--- �� ---*/
			if (Pop(&s, &x) == -1)
				puts("\a���� : �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		
		case 3: /*--- ��ũ ---*/
			if (Peek(&s, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		
		case 4: /*--- ��� ---*/
			Print(&s);
			break;
		}
	}

	Terminate(&s);

	return 0;
}