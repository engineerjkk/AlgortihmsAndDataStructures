#include <stdio.h>

//#pragma warning(disable: 4996)

void main()
{
	while (1) {
		int n;
		printf("n ? ");
		scanf_s("%d", &n);
		if (n < 0)
			break;
		int Fact(int);
		printf("%d! = %d\n\n", n, Fact(n));
	}
}

int Fact(int n)
{
	if (n <= 1) return 1;
	else return n*Fact(n-1);
}

/*n ? 5
5!= 120

n ? 4
4!= 24

n ? 3
3!= 6

n ? 6
6!= 720

n ? 7
7!= 5040

n ? 8
8!= 40320

n ? 9
9!= 362880

n ? 10
10!= 3628800

n ?*/
