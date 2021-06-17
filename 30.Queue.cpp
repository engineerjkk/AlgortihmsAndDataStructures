#include <stdio.h>

#define N 10
#pragma warning (disable: 4996)

typedef int Item;

typedef struct {
	Item items[N];
	int nFront;
	int nRear;
}	Queue, *QueuePtr;//Q������ ����Ʈ Ÿ��

void main()
{
	//���ÿ����� �����͸� �Ѱ������� ť������ �״��! 
	int  IsEmptyQueue(Queue aQueue);//ť�� �״�� ����ش�.
	int  IsFullQueue(Queue aQueue);//ť�� �״��! �����Ͱ� �ƴϴ�.
	int  AddQueue(Queue& aQueue, Item nItem);//���� �ٲ����ϴϱ� callbyreference�� !
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
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return aQueue.nFront == aQueue.nRear;//������ empty.!
}

int IsFullQueue(Queue aQueue)
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return aQueue.nRear == N - 1;//aQueue�� ����� N-1�̴�. 
}

int AddQueue(Queue& aQueue, Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// rear�� �����Ͽ� ����
	if (IsFullQueue(aQueue))
		return false;
	aQueue.items[++aQueue.nRear] = nItem;
	return true;
}

int DeleteQueue(Queue& aQueue, Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// front�� �����Ͽ� �޾Ƴ�
	if (IsEmptyQueue(aQueue))
		return false;
	nItem = aQueue.items[++aQueue.nFront];//Queue.nFront�� ��°�� �����̹Ƿ� �Ǿտ� ++��������Ѵ�.aQueue�� ������ �������ְ� �� �߿��� nFront��� ������ �ǹ��Ѵ�. 
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
