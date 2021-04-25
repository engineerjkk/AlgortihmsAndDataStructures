/* int형 큐 IntQueue를 사용하는 프로그램 */
#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int m, x;

		printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1) 인큐 (2) 디큐 (3) 피크 (4) 출력 (0) 종료 : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1: /*--- 인큐 ---*/
			printf("데이터 : "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;

		case 2: /*--- 디큐 ---*/
			if (Deque(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 3: /*--- 피크 ---*/
			if (Peek(&que, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 4: /*--- 출력 ---*/
			Print(&que);
			break;
		}
	}

	Terminate(&que);

	return 0;
}