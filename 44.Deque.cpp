#include <stdio.h>

#define N 10
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
	int  JumpInQueue(QueuePtr pQueue, Item nItem);//제일 앞에다가 삽입
	int  DeleteQueue(QueuePtr pQueue, Item& nItem);
	int  MagnanimousQueue(QueuePtr pQueue, Item& nItem);//제일 끝에 것 삭제
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = 0;
	while (1) {
		int value;
		printf("-3:끝, -2:양보, -1:삭제, 0~999:삽입, *:새치기 ? ");//-2 : 제일 끝인 rear부분을 삭제,1000대이면 제일 앞에다 삭제한다. 
		scanf("%d", &value);
		if (value < -2)
			break;
		else if (value == -2) { //양보해라
			if (MagnanimousQueue(&aQueue, value) == false)
				Error("empty");
			else
				printf("%d is deleted(양보)\n", value);
		}
		else if (value == -1) { //정상적으로 삭제
			if (DeleteQueue(&aQueue, value) == false)
				Error("empty");
			else
				printf("%d is deleted(삭제)\n", value);
		}
		else if (value < 1000) { //정상적으로 삽입
			if (AddQueue(&aQueue, value) == false)
				Error("full");
			else
				printf("%d is inserted(삽입)\n", value);
		}
		else {//1000보다 크면 새치기
			if (JumpInQueue(&aQueue, value %= 1000) == false)
				Error("full");
			else
				printf("%d is inserted(새치기)\n", value);
		}
		PrintQueue(&aQueue);
	}
}

int IsEmptyQueue(QueuePtr pQueue)//한개를 안쓰므로
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return pQueue->nRear == pQueue->nFront;
}

int IsFullQueue(QueuePtr pQueue)
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return (pQueue->nRear + 1) % N == pQueue->nFront;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	// rear를 증가하여 넣음
	if (IsFullQueue(pQueue))
		return false;
	pQueue->items[pQueue->nRear=(pQueue->nRear + 1) % N] = nItem;
	return true;
}

int JumpInQueue(QueuePtr pQueue, Item nItem)//front에다가 집어넣고 감소를 시켜야 한다. 
{	// 큐에 nItem을 앞끝에 새치기하는데 승패에 따라 T/F를 반환한다.
	// front에 item을 넣고 감소
	if (IsFullQueue(pQueue))
		return false;
	pQueue->items[pQueue->nFront] = nItem;
	pQueue->nFront = (pQueue->nFront - 1 + N) % N;
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)
{	// 큐에서 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// front를 증가하여 받아냄
	if (IsEmptyQueue(pQueue))
		return false;
	nItem = pQueue->items[pQueue->nRear=(pQueue->nRear+1)%N];
	return true;
}

int MagnanimousQueue(QueuePtr pQueue, Item& nItem)
{	// 큐에서 뒤끝을 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// rear의 item을 받아내고 감소
	if (IsEmptyQueue(pQueue))
		return false;
	nItem = pQueue->items[pQueue->nRear];
	pQueue->nRear = (pQueue->nFront - 1 + N) % N;
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
