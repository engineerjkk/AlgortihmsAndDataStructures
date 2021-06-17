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
	NodePtr Create2(void); //Node *Create2()  ����ص� �ȴ�.
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
	NodePtr pFirst, pSecond; //���� ����� �ּ� //Node *pFirst, *pSecond  // struct node *pFirst, struct node *pSecond
	// first node
	pFirst = (NodePtr)malloc(sizeof(Node));//����� ũ�⸸ŭ �޸𸮸� �Ҵ�޴´�.
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
	pLast = pNode; //���ÿ� pLast�� pNode�̴�.
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
	pNode = (NodePtr)malloc(sizeof(Node)); //pNode�� ���� �Ҵ���� ���� ����Ų��.
	pNode->nData = 40;//�� ���� �����Ϳ� 40�� �ִ´�.
	pLast->link = pNode;//���� pLast ��ũ�� ���� pLast�� ����Ų��.
	pLast = pNode;//���� ������ pLast�� pNode�� ����Ű�Եȴ�.
	// fifth node
	pNode = (NodePtr)malloc(sizeof(Node));
	pNode->nData = 50;
	pLast->link = pNode;
	pLast = pNode;
	// end
	pLast->link = NULL; //������ ��ũ�� NULL�� ����Ų��.
	return pFirst;
	//��, 1.�޸� �Ҵ�, 2.������ �ֱ�, 3.��ũ����
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
		ptr = ptr->link;//NULL�̵Ǹ� while�� ����
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
