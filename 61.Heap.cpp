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
		printf("노드 개수 ? ");
		scanf("%d", &nMax);
		if (nMax <= 0 || nMax > MAX_ELEMENTS)
			break;
		printf("  [Heap 랜덤 삽입]\n");
		for (int i = 1; i <= nMax; i++) {
			item.nData = rand() % 1000;
			printf("    [%02d] %d\n", i, item.nData);
			InsertHeap(heap, item, nCtr);
		}
		printf("\n  [Heap 삭제]\n");
		for (int i = 1; i <= nMax; i++) {
			item = DeleteHeap(heap, nCtr);
			printf("    [%02d] %d\n", i, item.nData);
		}
		putchar('\n');
	}
}

void InsertHeap(Element heap[], Element& anItem, int& nCtr)
{
	int nNdx = ++nCtr;//nNdx에 nCtr을 1 증가한 후 저장한다;
	while (nNdx>1&&anItem.nData>heap[nNdx/2].nData){//nNdx//가 1보다 크고  anItem의 데이커가 [nNdx / 2]의 데이터보다 크다)(오름차순 <)
		heap[nNdx] = heap[nNdx / 2];//부모의 데이터를 자식으로 내린다
		nNdx /= 2;//nNdx를 한 레벨 위로 올린다
	}
	heap[nNdx] = anItem;//[nNdx]에 anItem을 저장한다
}

Element DeleteHeap(Element heap[], int& nCtr)
{
	Element anItem = heap[1];// anItem에 루트 데이터를 저장한다
	Element lastItem = heap[nCtr--];// lastItem에 마지막 데이터를 저장하고 nCtr을 1 감소한다
	int parent = 1, child = 2;// parent에 1을, child에 2를 저장한다
	while (child <= nCtr){//child가 nCtr보다 작거나 같다) {
		if (child < nCtr && heap[child].nData < heap[child + 1].nData)//)child가 nCtr보다 작고 [child]의 데이터가 [child + 1]의 데이터보다 작다)
			child++;//child를 1 증가한다 (오름차순 >)
		if (lastItem.nData >= heap[child].nData)//)lastItem의 데이터가 [child]의 데이터보다 커거나 같다)(오름차순 <=)
			break;
		heap[parent] = heap[child];//[parent]의 데이터에 [child]의 데이터를 저장한다
		parent = child; //parent에 child를 저장한다
		child *= 2;//child에 2를 곱한다
	}
	heap[parent] = lastItem;// [parent] 에 lastItem을 저장한다
	return anItem;// anItem을 반환한다
}
