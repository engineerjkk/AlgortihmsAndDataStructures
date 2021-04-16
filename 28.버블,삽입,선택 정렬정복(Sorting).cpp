#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Num_Selection = 0;
int Num_Bubble = 0;
int Num_Insert = 0;

inline void swap(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
}
/// <summary>
/// 맨뒤의 숫자를 고정한 다음에 맨 앞에서부터 숫자를 보두 비교한다. 그러다가 앞의 숫자가 더 크면 swap.
/// </summary>
/// <param name="A"></param>
/// <param name="n"></param>
void BubbleSort(int A[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				
			}Num_Bubble++;
		}

	}
}
/// <summary>
/// 가장 작은 수부터 정렬하는 알고리즘이므로, 가장 작은수를 일단 찾습니다.
/// </summary>
/// <param name="A"></param>
/// <param name="n"></param>
void SelectionSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[least]) {
				least = j;
				
			}Num_Selection++;
		}
		swap(A[i], A[least]);
	}
}
/// <summary>
/// 정렬된 열의 왼쪽 끝에 도달하거나 key보다 작거나 같은 값을 갖는 항목 A[j]를 발견한다.
/// </summary>
/// 문제있는코드
/*void InsertionSort(int a[], int n)
{
	int i, j, key;
	for (i = 2; i <= n; i++) {
		key = a[i]; j = i;
		while (a[j - 1] > key)//앞에 숫자가 뒤에꺼보다 크면 만약 첫번째 값이 두전째 값보다 크면
		{
			a[j] = a[j - 1]; j--;//swap한다.
		}
		a[j] = key;
	}
}*/
//while문 연산이 j--이므로 음수까지 도달하게 된다. 


void InsertionSort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0 && A[j] > key; j--) {//가장 작은값까지 돌았으면서  값이 현재 key보다 큰경우에만 swap
			A[j + 1] = A[j];
			Num_Insert++;
		}
		A[j + 1] = key;
		
	}
}

static void initRandom(int list[], int n, int max = 100) {
	for (int i = 0; i < n; i++) {
		list[i] = rand() % max;
	}
}
static void printArray(int arr[], int n, const char* str) {
	printf("%s=", str);	
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}
void main() {
	int list[16];
	int n = 16;
	srand(time(0));
	
	printf("선택정렬\n");
	initRandom(list, n);
	printArray(list, n, "Original");
	SelectionSort(list, n);
	printArray(list, n, "Selection");
	printf("비교횟수: %d\n\n", Num_Selection);

	printf("버블정렬\n");
	initRandom(list, n);
	printArray(list, n, "Original");
	BubbleSort(list, n);
	printArray(list, n, "Bubble");
	printf("비교횟수:%d\n\n", Num_Bubble);

	printf("삽입정렬\n");
	initRandom(list, n);
	printArray(list, n, "Original");
	InsertionSort(list, n);
	printArray(list, n, "insertion");
	printf("비교횟수:%d\n", Num_Insert	);
}
