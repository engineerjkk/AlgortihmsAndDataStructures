#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

typedef struct node {
	int nData;
	struct node *llink;
	struct node *rlink;
}	Node, *NodePtr;

void main()
{
	NodePtr Insert(NodePtr pFirst, int nData, NodePtr pLeft);
	NodePtr Delete(NodePtr pFirst, NodePtr pDel);
	NodePtr Find(NodePtr pFirst, int nData);
	void PrintList(NodePtr pFirst);
	NodePtr pFirst = NULL;
	NodePtr pNode = NULL;
	while (1) {
		printf("[idfe] ? ");
		char sCmnd[10];
		gets_s(sCmnd);
		if (*sCmnd == 'e')
			return;
		int nData;
		if (*sCmnd == 'f' || *sCmnd == 'i') {
			printf("Data ? ");
			char sData[10];
			gets_s(sData);
			nData = atoi(sData);
		}
		switch (*sCmnd) {
		case 'i':
			pFirst = Insert(pFirst, nData, pNode);
			break;
		case 'd':
			if (pNode) {
				pFirst = Delete(pFirst, pNode);
				pNode = NULL;
			}
			else
				printf("First, assign a node to be deleted, ...\n"); 
			break;
		case 'f':
			pNode = Find(pFirst, nData);
			printf("%s\n", (pNode) ? "Good" : "Bad");
		}
		PrintList(pFirst);
	}
}

NodePtr Insert(NodePtr pFirst, int nData, NodePtr pLeft)
{
	// pLeft 노드 오른쪽에 nData를 가지는 노드를 삽입한다.
	// pLeft가 NULL이면 첫 노드로 삽입한다.
	// pLeft는 호출하기 직전에 find에 의하여 먼저 설정하여야 한다.
	// pRight = ?
	// pLeft가  있(없)을 경우
	// pRight가 있(없)을 경우
	//
	return pFirst;
}

NodePtr Delete(NodePtr pFirst, NodePtr pDel)
{
	// pNode를 삭제한다.
	// pNode는 호출하기 직전에 find에 의하여 먼저 설정하여야 한다.
	// pLeft = ?, pRight = ?
	// pLeft가  있(없)을 경우
	// pRight가 있(없)을 경우
	//
	return pFirst;
}

NodePtr Find(NodePtr pNode, int nData)
{
	// nData를 가지는 노드를 찾는데 없으면 NULL을 return 한다.
	return NULL;
}

void PrintList(NodePtr pNode)
{
	NodePtr pPrev = NULL;
	while (pNode) {
		printf("%d ", pNode->nData);
		pPrev = pNode;
		pNode = pNode->rlink;
	}
	printf("<---> ");
	pNode = pPrev;
	while (pNode) {
		printf("%d ", pNode->nData);
		pNode = pNode->llink;
	}
	printf("\n\n");
}
