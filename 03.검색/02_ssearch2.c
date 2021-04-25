/*--- 요소의 개수 n인 배열 a에서 key와 일치하는 요소를 선형 검색(버전 1 : for문) ---*/
int search(const int a[], int n, int key)
{
	int i;
	
	for (i = 0; i < n; i++)
		if (a[i] == key)
			return i; 	/* 검색 성공 */

	return -1; 			/* 검색 실패 */
}