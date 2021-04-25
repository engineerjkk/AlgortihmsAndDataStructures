/* µ¡¼ÀÇ¥¿Í °ö¼ÀÇ¥ */
#include <stdio.h>

/*--- x1°ú x2ÀÇ ÇÕÀ» ±¸ÇÕ´Ï´Ù. ---*/
int sum(int x1, int x2)
{
	return x1 + x2;
}

/*--- x1°ú x2ÀÇ °öÀ» ±¸ÇÕ´Ï´Ù. ---*/
int mul(int x1, int x2)
{
	return x1 * x2;
}

/*--- µ¡¼À, °ö¼ÀÇ¥¸¦ Ãâ·Â ---*/
void kuku(int(*calc)(int, int))
{
	int i, j;
	
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++)
			printf("%3d", (*calc)(i, j));
		putchar('\n');
	}
}

int main(void)
{
	puts("µ¡¼ÀÇ¥");
	kuku(sum);
	
	puts("\n °ö¼ÀÇ¥");
	kuku(mul);

	return 0;
}