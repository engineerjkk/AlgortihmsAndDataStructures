#include <stdio.h>
#include <stdlib.h>

#define	FORTEST

#pragma warning (disable: 4996)

typedef struct node {
	int nData;
	struct node *link;
}	Node, *NodePtr;

void main()
{
	NodePtr Create2(void); //Node *Create2()  라고해도 된다.
	NodePtr Create5(void);
	NodePtr CreateN(int nCtr);
	void PrintList(NodePtr pList);
	void FreeList(NodePtr pList);

	NodePtr pHead;
#ifdef FORTEST
	pHead = Create5();	// Create5();
	PrintList(pHead);
	FreeList(pHead);

	while (1) {
		printf("? ");
		int nCtr;
		scanf("%d", &nCtr);
		if (nCtr <= 0)
			break;
		pHead = CreateN(nCtr);
		PrintList(pHead);
		FreeList(pHead);
		putchar('\n');
	}
	printf("Bye, ...\n\n");
#endif
}
#ifdef FORTEST
NodePtr Create2()
{
	NodePtr pFirst, pSecond; //각각 노드의 주소 //Node *pFirst, *pSecond  // struct node *pFirst, struct node *pSecond
	// first node
	pFirst = (NodePtr)malloc(sizeof(Node));//노드의 크기만큼 메모리를 할당받는다.
	pFirst->nData = 10;
	// second node
	pSecond = (NodePtr)malloc(sizeof(Node));
	pSecond->nData = 20;
	pFirst->link = pSecond;
	// end
	pSecond->link = NULL;
	return pFirst;
}

NodePtr Create5()
{
	NodePtr pFirst, pNode, pLast;
	// first node
	pFirst,pNode = (NodePtr)malloc(sizeof(Node));
	pNode->nData = 10;
	pFirst = pNode;
	pLast = pNode; //동시에 pLast가 pNode이다.
	//pNode=(struct node *)malloc(sizeof(struct node));
	// second node
	pNode = (NodePtr)malloc(sizeof(Node));
	pNode->nData = 20;
	pLast->link = pNode;
	pLast = pNode;
	// third node
	pNode = (NodePtr)malloc(sizeof(Node));
	pNode->nData = 30;
	pLast->link = pNode;
	pLast = pNode;
	// fourth node
	pNode = (NodePtr)malloc(sizeof(Node)); //pNode가 새로 할당받은 곳을 가리킨다.
	pNode->nData = 40;//그 곳의 데이터에 40을 넣는다.
	pLast->link = pNode;//이제 pLast 링크가 이제 pLast를 가리킨다.
	pLast = pNode;//역시 마지막 pLast는 pNode를 가리키게된다.
	// fifth node
	pNode = (NodePtr)malloc(sizeof(Node));
	pNode->nData = 50;
	pLast->link = pNode;
	pLast = pNode;
	// end
	pLast->link = NULL; //마지막 링크는 NULL를 가리킨다.
	return pFirst;
	//즉, 1.메모리 할당, 2.데이터 넣기, 3.링크조작
}

NodePtr CreateN(int nCtr)
{
	NodePtr pFirst, pNode, pLast;
	// first
	pFirst = (NodePtr)malloc(sizeof(Node));
	pFirst->nData = 1;
	pLast = pFirst;
	// from 2 to nCtr
	for (int i = 2; i <= nCtr; i++) {
		pNode = (NodePtr)malloc(sizeof(Node));
		pNode->nData = i;
		pLast = pLast->link = pNode;
	}
	pLast->link = NULL;
	return pFirst;
}
#endif
void PrintList(NodePtr pList)
{
	NodePtr ptr = pList;
	while (ptr) {
		printf("%d ", ptr->nData);
		ptr = ptr->link;//NULL이되면 while문 종료
	}
	putchar('\n');
}

void FreeList(NodePtr pList)
{
	if (pList) {
		FreeList(pList->link);
		delete pList;
	}
}
