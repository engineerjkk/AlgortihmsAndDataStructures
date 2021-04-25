/* qsort 함수를 사용하여 구조체 배열을 정렬 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];	/* 이름 */
	int height;		/* 키 */
	int weight;		/* 몸무게 */
} Person;

/*--- Person형 비교 함수(이름 오름차순 정렬) ---*/
int npcmp(const Person *x, const Person *y)
{
	return strcmp(x->name, y->name);
}

/*--- Person형 비교 함수(키 오름차순 정렬) ---*/
int hpcmp(const Person *x, const Person *y)
{
	return x->height < y->height ? -1 :
		x->height > y->height ? 1 : 0;
}

/*--- Person형 비교 함수(몸무게 내림차순 정렬) ---*/
int wpcmp(const Person *x, const Person *y)
{
	return x->weight < y->weight ? 1 :
		x->weight > y->weight ? -1 : 0;
}

/*--- 사람 no명의 데이터를 표시 ---*/
void print_person(const Person x[], int no)
{
	int i;
	for (i = 0; i < no; i++)
		printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
}

int main()
{
	Person x[] = {
		{ "sunmi", 170, 52 },
		{ "yoobin", 180, 70 },
		{ "sohee", 172, 63 },
		{ "jina", 165, 50 },
	};

	int nx = sizeof(x) / sizeof(x[0]); 		/* 배열 x의 요소 개수 */

	puts("정렬 전");
	print_person(x, nx);

	/* 이름 오름차순으로 정렬 */
	qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *)) npcmp);
	puts("\n이름 오름차순으로 정렬 후");
	print_person(x, nx);

	/* 키 오름차순으로 정렬 */
	qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *)) hpcmp);
	puts("\n키 오름차순으로 정렬 후");
	print_person(x, nx);

	/* 몸무게 내림차순으로 정렬 */
	qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *)) wpcmp);
	puts("\n몸무게 내림차순으로 정렬 후");
	
	print_person(x, nx);

	return 0;
}