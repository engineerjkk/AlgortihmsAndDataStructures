/*--- ����� ���� n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���� 1 : for��) ---*/
int search(const int a[], int n, int key)
{
	int i;
	
	for (i = 0; i < n; i++)
		if (a[i] == key)
			return i; 	/* �˻� ���� */

	return -1; 			/* �˻� ���� */
}