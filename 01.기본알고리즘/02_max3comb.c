/* 세 정수의 최댓값을 구합니다(모든 대소 관계에 대하여 확인). */
#include <stdio.h>

/*--- a, b, c의 최댓값을 구합니다. ---*/
int max3(int a, int b, int c)
{
	int max = a;	/* 최댓값 */
	if (b > max) max = b;
	if (c > max) max = c;

	return max;
}

int main(void)
{
	printf("max3(%d, %d, %d) = %d\n", 3, 2, 1, max3(3, 2, 1)); /* [A] a > b > c */
	printf("max3(%d, %d, %d) = %d\n", 3, 2, 2, max3(3, 2, 2)); /* [B] a > b = c */
	printf("max3(%d, %d, %d) = %d\n", 3, 1, 2, max3(3, 1, 2)); /* [C] a > c > b */
	printf("max3(%d, %d, %d) = %d\n", 3, 2, 3, max3(3, 2, 3)); /* [D] a = c > b */
	printf("max3(%d, %d, %d) = %d\n", 2, 1, 3, max3(2, 1, 3)); /* [E] c > a > b */
	printf("max3(%d, %d, %d) = %d\n", 3, 3, 2, max3(3, 3, 2)); /* [F] a = b > c */
	printf("max3(%d, %d, %d) = %d\n", 3, 3, 3, max3(3, 3, 3)); /* [G] a = b = c */
	printf("max3(%d, %d, %d) = %d\n", 2, 2, 3, max3(2, 2, 3)); /* [H] c > a = b */
	printf("max3(%d, %d, %d) = %d\n", 2, 3, 1, max3(2, 3, 1)); /* [I] b > a > c */
	printf("max3(%d, %d, %d) = %d\n", 2, 3, 2, max3(2, 3, 2)); /* [J] b > a = c */
	printf("max3(%d, %d, %d) = %d\n", 1, 3, 2, max3(1, 3, 2)); /* [K] b > c > a */
	printf("max3(%d, %d, %d) = %d\n", 2, 3, 3, max3(2, 3, 3)); /* [L] b = c > a */
	printf("max3(%d, %d, %d) = %d\n", 1, 2, 3, max3(1, 2, 3)); /* [M] c > b > a */

	return 0;
}