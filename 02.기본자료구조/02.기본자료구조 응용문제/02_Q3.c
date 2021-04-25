///* Q3 배열 요소의 평균값 */
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- 요솟수 n인 배열 a의 요소의 평균을 ---*/
//double aveof(const int a[], int n)
//{
//	int i;
//	double sum = 0; /* 합계 */
//
//	for (i = 0; i <n; i++)
//		sum += a[i];
//
//	return sum / n;
//}
//
//int main(void)
//{
//	int i;
//	int *height;		/* 배열의 첫 번째 요소에 대한 포인터 */
//	int number;			/* 인원 = 배열 height의 요솟수 */
//
//	printf("인원 : ");
//	scanf("%d", &number);
//
//	height = calloc(number, sizeof(int)); /* 요솟수 number 배열을 생성 */
//
//	printf("%d명의 키를 입력하세요.\n", number);
//	for (i = 0; i < number; i++) {
//		printf("height [%d] : ", i);
//		scanf("%d", &height[i]);
//	}
//
//	printf("평균은 %f입니다.\n", aveof(height, number));
//
//	free(height); /* 배열 height를 해제 */
//
//	return 0;
//}