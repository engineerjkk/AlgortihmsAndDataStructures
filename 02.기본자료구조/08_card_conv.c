/* 정수를 2진수 ~ 36진수로 기수 변환 */
#include <stdio.h>

/*--- 정수 값 x를 n진수로 변환하여 배열 d에 아랫자리부터 저장 ---*/
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0; 			/* 변환 후 자릿수 */

	if (x == 0) 				/* 0이면 */
		d[digits++] = dchar[0]; 		/* 변환 후에도 0 */
	else
		while (x) {
			d[digits++] = dchar[x % n]; 	/* n으로 나눈 나머지를 저장 */
			x /= n;
		}

	return digits;
}

int main(void)
{
	int i;
	unsigned no; 		/* 변환하는 정수 */
	int cd;				/* 기수 */
	int dno;			/* 변환 후 자릿수 */
	char cno[512]; 		/* 변환한 값의 각 자리의 숫자를 저장하는 문자 배열 */
	int retry;			/* 한 번 더? */

	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수 : ");
		scanf("%u", &no);

		do {
			printf("어떤 진수로 변환할까요? (2-36) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd> 36);

		dno = card_convr(no, cd, cno); 		/* no를 cd진수로 변환 */

		printf("%d진수로는", cd);
		for (i = dno - 1; i >= 0; i--) 		/* 윗자리부터 차례로 출력 */
			printf("%c", cno[i]);
		printf("입니다.\n");

		printf("한 번 더 할까요? (1 … 예 /0 … 아니오) : ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}