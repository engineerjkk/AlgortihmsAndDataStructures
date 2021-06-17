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
{	// queue가 비었으면 true 아니면 false를 반환한다.
	return pQueue->pFront==NULL;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// queue에 nItem을 추가하고 성공하면 true 아니면 false를 반환한다.
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nItem;
		pNew->link = NULL;
		if (pQueue->pFront != NULL)//pFront가 NULL일경우 rear가 쓰레기값을 가리키기 때문에 에러가난다. 
			pQueue->pRear->link = pNew;//마지막노드의 링크가 새로 들어온 노드를 가리키도록한다.
		else
			pQueue->pFront = pNew;//pFront가 NULL이라면 pNew를 가리키도록한다.
		pQueue->pRear = pNew;//어쨌거나 pRear은 마지막 노드를 가리킨다. 
	}
	return pNew != NULL;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)//마지막 노드 삭제
{	//queue에서 삭제하여 nItem에 저장하고 성공하면 true 아니면 false를 반환한다.
	//pQueue->pFront가 삭제될 노드이다.
	if (pQueue->pFront == NULL)//Front가 NULL이면 rear가 쓰레기값을 가리키므로 에러가난다.
		return false;
	NodePtr pDel = pQueue->pFront;//제일 첫번째 노드가 삭제될 노드이다. 
	nItem = pDel->nData;//삭제될 데이터를 nItem에 넣어준다. 
	pQueue->pFront = pDel->link;//삭제될 데이터의 링크를 첫번째pQueue의 pFront에 넣어준다.
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
