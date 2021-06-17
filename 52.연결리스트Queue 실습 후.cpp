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
	int  Error(char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.pFront = NULL;
	while (1) {
		int value;
		printf("-1:Exit 0:Delete, *:Add ? ");
		scanf("%d", &value);
		if (value < 0)
			break;
		else if (value == 0) {
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
{	
	//queue가 비어있으면 true 아니면 false를 반환한다.
	return pQueue->pFront == NULL;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{
	//queue에 nItem을 추가하고 성공하면 true아니면 false를 반환한다.
	NodePtr pNode = (NodePtr)malloc(sizeof(Node));
	if (pNode == NULL)
		return false;
	pNode->nData = nItem;
	pNode->link = NULL;
	if (pQueue->pFront)
		pQueue->pRear->link = pNode;
	else
		pQueue->pFront = pNode;
	pQueue->pRear = pNode;
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)
{
	if (IsEmptyQueue(pQueue))
		return false;
	NodePtr pNode = pQueue->pFront;
	nItem = pNode->nData;
	pQueue->pFront = pNode->link;
	free(pNode);
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

int Error(char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
