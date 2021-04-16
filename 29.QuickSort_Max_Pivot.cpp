#include <stdio.h>
#include <stdlib.h>
#define max 10

void QuickSort(int A[], int start, int end);             //그 그룹안에서 소팅해줍니다.
int Partition(int A[], int start, int end);              //두 그룹으로 나누어 줍니다.


int main() {
	int A[max] = { 40,30,100,60,70,90,10,20,50 };
	int i;
	printf("\n Before Sorting\n");
	for (i = 0; i < max; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	QuickSort(A, 0, max - 1);
	printf("\n After Sorting\n");
	for (i = 0; i < max; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
void QuickSort(int A[], int start, int end) {
	int index;
	int i;

	if (start < end) {
		index = Partition(A, start, end);
		for (i = 0; i < max; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		QuickSort(A, start, index - 1);
		QuickSort(A, index + 1, end);
	}
	else {
		return;
	}
}
int Partition(int A[], int start, int end) {
	int pivot = A[end];
	int i;
	int index = start;

	int temp;

	for (i = start; i < end; i++) {
		if (A[i] <= pivot) {
			printf("Swap!! %d %d\n", A[i], A[index]);
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;
	printf("Swap!! %d %d\n", A[i], A[index]);
	return index;
}
//이해완료.