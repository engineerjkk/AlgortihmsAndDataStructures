/* 각 열에 1개의 퀸을 배치하는 조합을 재귀적으로 나열합니다. */
#include <stdio.h> 

int pos[8]; 		/* 각 열에서 퀸의 위치 */

/*--- 각 열의 퀸의 위치를 출력 ---*/
void print(void)
{
	int i;
	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

/*--- i열에 퀸을 배치 ---*/
void set(int i)
{
	int j;
	for (j = 0; j < 8; j++) {
		pos[i] = j;
		if (i == 7) 		/* 모든 열에 배치되었다면 */
			print();
		else
			set(i + 1);
	}
}
int main(void)
{
	set(0);

	return 0;
}