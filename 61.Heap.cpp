#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS	100
#pragma warning (disable: 4996)

typedef struct {
	int nData;
	int nOtherData;
}	Element;

void main()
{
	void InsertHeap(Element heap[], Element& anItem, int& n);
	Element DeleteHeap(Element heap[], int& nCtr);

	Element heap[MAX_ELEMENTS + 1];
	int nCtr = 0;
	Element item;
	srand((unsigned)time(NULL));
	while (1) {
		int nMax;
		printf("��� ���� ? ");
		scanf("%d", &nMax);
		if (nMax <= 0 || nMax > MAX_ELEMENTS)
			break;
		printf("  [Heap ���� ����]\n");
		for (int i = 1; i <= nMax; i++) {
			item.nData = rand() % 1000;
			printf("    [%02d] %d\n", i, item.nData);
			InsertHeap(heap, item, nCtr);
		}
		printf("\n  [Heap ����]\n");
		for (int i = 1; i <= nMax; i++) {
			item = DeleteHeap(heap, nCtr);
			printf("    [%02d] %d\n", i, item.nData);
		}
		putchar('\n');
	}
}

void InsertHeap(Element heap[], Element& anItem, int& nCtr)
{
	int nNdx = ++nCtr;//nNdx�� nCtr�� 1 ������ �� �����Ѵ�;
	while (nNdx>1&&anItem.nData>heap[nNdx/2].nData){//nNdx//�� 1���� ũ��  anItem�� ����Ŀ�� [nNdx / 2]�� �����ͺ��� ũ��)(�������� <)
		heap[nNdx] = heap[nNdx / 2];//�θ��� �����͸� �ڽ����� ������
		nNdx /= 2;//nNdx�� �� ���� ���� �ø���
	}
	heap[nNdx] = anItem;//[nNdx]�� anItem�� �����Ѵ�
}

Element DeleteHeap(Element heap[], int& nCtr)
{
	Element anItem = heap[1];// anItem�� ��Ʈ �����͸� �����Ѵ�
	Element lastItem = heap[nCtr--];// lastItem�� ������ �����͸� �����ϰ� nCtr�� 1 �����Ѵ�
	int parent = 1, child = 2;// parent�� 1��, child�� 2�� �����Ѵ�
	while (child <= nCtr){//child�� nCtr���� �۰ų� ����) {
		if (child < nCtr && heap[child].nData < heap[child + 1].nData)//)child�� nCtr���� �۰� [child]�� �����Ͱ� [child + 1]�� �����ͺ��� �۴�)
			child++;//child�� 1 �����Ѵ� (�������� >)
		if (lastItem.nData >= heap[child].nData)//)lastItem�� �����Ͱ� [child]�� �����ͺ��� Ŀ�ų� ����)(�������� <=)
			break;
		heap[parent] = heap[child];//[parent]�� �����Ϳ� [child]�� �����͸� �����Ѵ�
		parent = child; //parent�� child�� �����Ѵ�
		child *= 2;//child�� 2�� ���Ѵ�
	}
	heap[parent] = lastItem;// [parent] �� lastItem�� �����Ѵ�
	return anItem;// anItem�� ��ȯ�Ѵ�
}
