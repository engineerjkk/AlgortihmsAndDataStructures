/* int�� ��ü�� �������� �����ϰ� �����մϴ�. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int * x;
	x = calloc(1, sizeof(int)); 	/* int�� �����Ϳ� �޸� �Ҵ� */

	if (x == NULL) {
		puts("�޸� �Ҵ翡 �����߽��ϴ�.");
	}
	else {
		*x = 57;
		printf("*x = %d\n", *x);

		free(x); 		/* int�� �����Ϳ� �Ҵ��� �޸� ���� */
	}

	return 0;
}