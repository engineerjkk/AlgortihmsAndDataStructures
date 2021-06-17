#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr;

typedef struct {
	NodePtr pFront;
	NodePtr pRear;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	//int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item& nItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.pFront = NULL;
	while (1) {
		int value;
		printf("-2:Exit -1:Delete, *:Add ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		else if (value == -1) {
			if (DeleteQueue(&aQueue, value) == false)
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
{	// queue�� ������� true �ƴϸ� false�� ��ȯ�Ѵ�.
	return pQueue->pFront==NULL;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// queue�� nItem�� �߰��ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nItem;
		pNew->link = NULL;
		if (pQueue->pFront != NULL)//pFront�� NULL�ϰ�� rear�� �����Ⱚ�� ����Ű�� ������ ����������. 
			pQueue->pRear->link = pNew;//����������� ��ũ�� ���� ���� ��带 ����Ű�����Ѵ�.
		else
			pQueue->pFront = pNew;//pFront�� NULL�̶�� pNew�� ����Ű�����Ѵ�.
		pQueue->pRear = pNew;//��·�ų� pRear�� ������ ��带 ����Ų��. 
	}
	return pNew != NULL;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)//������ ��� ����
{	//queue���� �����Ͽ� nItem�� �����ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	//pQueue->pFront�� ������ ����̴�.
	if (pQueue->pFront == NULL)//Front�� NULL�̸� rear�� �����Ⱚ�� ����Ű�Ƿ� ����������.
		return false;
	NodePtr pDel = pQueue->pFront;//���� ù��° ��尡 ������ ����̴�. 
	nItem = pDel->nData;//������ �����͸� nItem�� �־��ش�. 
	pQueue->pFront = pDel->link;//������ �������� ��ũ�� ù��°pQueue�� pFront�� �־��ش�.
	delete pDel;
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	NodePtr pNode = pQueue->pFront;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n");
	pNode = pQueue->pFront;
	while (pNode) {
		printf("%4d", pNode->nData);
		pNode = pNode->link;
	}
	printf("\n");
	pNode = pQueue->pFront;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
