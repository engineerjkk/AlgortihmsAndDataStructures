/* �� ��, �� ���� 1���� ���� ��ġ�ϴ� ������ ��������� �����մϴ�. */
#include <stdio.h> 

int flag[8];	/* �� �࿡ ���� ��ġ�ߴ��� üũ�ϴ� �迭 */
int pos[8];		/* �� ������ ���� ��ġ */

/*--- �� ������ ���� ��ġ�� ��� ---*/
void print(void)
{
	int i;
	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

/*--- i������ �˸��� ��ġ�� ���� ��ġ�մϴ�. ---*/
void set(int i)
{
	int j;
	for (j = 0; j < 8; j++) {
		if (!flag[j]) {		/* j�࿡ ���� ��ġ���� �ʾҴٸ� */
			pos[i] = j;
			if (i == 7)		/* ��� ���� ���� ��ġ */
				print();
			else {
				flag[j] = 1;
				set(i + 1);
				flag[j] = 0;
			}
		}
	}
}

int main(void)
{
	int i;
	for (i = 0; i < 8; i++)
		flag[i] = 0;

	set(0);

	return 0;
}