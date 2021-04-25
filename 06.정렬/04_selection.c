/*--- 단순 선택 정렬 ---*/
void selection(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(int, a[i], a[min]);
	}
}