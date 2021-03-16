#include <stdio.h>

#pragma warning(disable: 4996)

void main()
{
	while (1) {
		int n, r;
		printf("n ? ");
		scanf("%d", &n);
		if (n <= 0)
			break;
		printf("r ? ");
		scanf("%d", &r);
		if (n < r || r < 0)
			break;
		int Combi(int, int);
		printf("Combi(%d, %d) = %d\n\n", n, r, Combi(n, r));
	}
}

int Combi(int n, int r)
{
	if (n == r||r==0)
		return 1;
	
	return Combi(n - 1, r) + Combi(n - 1, r - 1);
}

/*조합은 서로다른 n개 중에서 r개를 선택하는 경우의 수 입니다.
순서는 중요하지 않습니다.

편의점에 가서 a b c d e f g 과자 중 3개를 선택하는 경우의 수라고 볼 수 있습니다. 
7개중 3개를 선택하는 경우의 수입니다.
7!/((7-3)!*3!)입니다.  =35
*/

