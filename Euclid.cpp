#include <stdio.h>

#pragma warning(disable: 4996)

void main()
{
	int nNmbr1, nNmbr2;
	while (1) {
		printf("Number 1 ? ");
		scanf("%d", &nNmbr1);		// �� �ϳ� �Է�
		if (nNmbr1 <= 0)			// �����̸� ������
			break;
		printf("Number 2 ? ");
		scanf("%d", &nNmbr2);		// �ٸ� �� �ϳ� �� �Է�
		int Euclid(int nBig, int nSmall);
		printf("GCD: %d\n\n", Euclid(nNmbr1, nNmbr2));	// �ִ����� ���
	}
}

int Euclid(int nBig, int nSmall)
{	// GCD(Greatest Common Divisor)�� ����Ѵ�
	int nRem = nBig % nSmall;
	if (nRem == 0)
		return nSmall;

	return Euclid(nSmall, nRem);
}
/*2468%1072
1072%324
324%100
100%24
24%4
return -> 4
*/

