#include <stdio.h>

#define N 10
#pragma warning (disable: 4996)

typedef int Item;

typedef struct {
	Item items[N];
	int nFront;
	int nRear;
}	Queue, *QueuePtr;//Q에대한 포인트 타입

void main()
{
	//스택에서는 포인터를 넘겨줬지만 큐에서는 그대로! 
	int  IsEmptyQueue(Queue aQueue);//큐를 그대로 놈겨준다.
	int  IsFullQueue(Queue aQueue);//큐를 그대로! 포인터가 아니다.
	int  AddQueue(Queue& aQueue, Item nItem);//뭔가 바뀌어야하니까 callbyreference로 !
	int  DeleteQueue(Queue& aQueue, Item& anItem);
	void PrintQueue(Queue aQueue);
	int Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = -1;
	while (1) {
		int value;
		printf("-2:Exit -1:Delete, *:Add ? ");
		scanf_s("%d", &value);
		if (value < -1)
			break;
		if (value == -1) {
			if (DeleteQueue(aQueue, value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (AddQueue(aQueue, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintQueue(aQueue);
	}
}

int IsEmptyQueue(Queue aQueue)
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return aQueue.nFront == aQueue.nRear;//같으면 empty.!
}

int IsFullQueue(Queue aQueue)
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return aQueue.nRear == N - 1;//aQueue의 리어는 N-1이다. 
}

int AddQueue(Queue& aQueue, Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	// rear를 증가하여 삽입
	if (IsFullQueue(aQueue))
		return false;
	aQueue.items[++aQueue.nRear] = nItem;
	return true;
}

int DeleteQueue(Queue& aQueue, Item& nItem)
{	// 큐에서 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// front를 증가하여 받아냄
	if (IsEmptyQueue(aQueue))
		return false;
	nItem = aQueue.items[++aQueue.nFront];//Queue.nFront가 통째로 변수이므로 맨앞에 ++를해줘야한다.aQueue는 변수가 여러개있고 그 중에서 nFront라는 변수를 의미한다. 
	return true;
}

void PrintQueue(Queue aQueue)
{
	for (int i = aQueue.nFront + 1; i <= aQueue.nRear; i++)
		printf("--%d-", i);
	printf("--\n");
	for (int i = aQueue.nFront + 1; i <= aQueue.nRear; i++)
		printf("%3d ", aQueue.items[i]);
	printf("\n");
	for (int i = aQueue.nFront + 1; i <= aQueue.nRear; i++)
		printf("----");
	printf("--\n\n");
}

int Error(const char* sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
