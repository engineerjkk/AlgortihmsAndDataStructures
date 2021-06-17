#include <stdio.h>

#define N 	10
#pragma warning (disable: 4996)

typedef int Item;

typedef struct {
	Item items[N];
	int nFront; 
	int nRear;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item *pItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = 0;
	while (1) {
		int value;
		printf("-2:Exit -1:Delete, 0~:Add ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		else if (value == -1) {
			if (DeleteQueue(&aQueue, &value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (AddQueue(&aQueue, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintQueue(&aQueue);
	}
}

int IsEmptyQueue(QueuePtr pQueue)
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return pQueue->nFront==pQueue->nRear;
}

int IsFullQueue(QueuePtr pQueue)
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return (pQueue->nRear+1)%N==pQueue->nFront;//사실 가득찬게 아니고 한개가 빈 상태이다.
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	// rear를 증가하여 삽입
	if (IsFullQueue(pQueue))
		return false;
	//pQueue->nFront = (pQueue->nFront + 1) % N;//증가를 시키고 거기에 아이템을 집어넣어라
	pQueue->items[pQueue->nRear = (pQueue->nRear + 1) % N] = nItem;
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item *pItem)
{	// 큐에서 삭제하여 pItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// front를 증가하여 받아냄
	if (IsEmptyQueue(pQueue))
		return false;
	*pItem = pQueue->items[pQueue->nFront=(pQueue->nFront)%N];
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	int nCtr = (pQueue->nRear - pQueue->nFront + N) % N;
	for (int i = 1; i <= nCtr; i++)
		printf("--%d-", (pQueue->nFront + i) % N);
	printf("--\n");
	for (int i = 1; i <= nCtr; i++)
		printf("%3d ", pQueue->items[(pQueue->nFront + i) % N]);
	printf("\n");
	for (int i = 1; i <= nCtr; i++)
		printf("----");
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
