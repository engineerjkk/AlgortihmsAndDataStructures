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
	NodePtr pFirst = NULL; //제일 앞에 노드
	NodePtr pNode = NULL;//find할때 활성화
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
	/*NodePtr pRght, pNew = new Node;
	if (pNew) {
		pNew->nData = nData;
		pRght = pLeft ? pLeft->rlink : pFirst;//얘가 NULL이면 안되므로 pLeft에 뭔가 있으면 rlink로, 없으면 pFirst가 된다.
		if (pLeft) {
			pRght = pLeft->rlink;
		}
		else {
			pRght = pFirst;
			pFirst = pNew;
		}
		pNew->llink = pLeft;
		pNew->rlink = pRght; //여기까지 파란색
		pLeft && (pLeft->rlink = pNew);//pL
		pRght&& pRght->llink = pNew;//여기까지 빨간색
	}*/

	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nData;
		NodePtr pRight = (pLeft) ? pLeft->rlink : pFirst;
		pNew->llink = pLeft;
		pNew->rlink = pRight;
		if (pLeft)
			pLeft->rlink = pNew;
		else
			pFirst = pNew;
		if (pRight)
			pRight->llink = pNew;
	}
	return pFirst;
}

NodePtr Delete(NodePtr pFirst, NodePtr pDel)
{
	// pDelNode를 삭제한다.
	// pDelNode는 호출하기 직전에 find에 의하여 먼저 설정하여야 한다.
	NodePtr pLeft  = pDel->llink;
	NodePtr pRight = pDel->rlink;
	if (pLeft)
		pLeft->rlink = pRight;
	else
		pFirst = pRight;
	if (pRight)
		pRight->llink = pLeft;
	delete pDel;
	return pFirst;
}

NodePtr Find(NodePtr pNode, int nData)
{
	// nData를 가지는 노드를 찾는데 없으면 NULL을 return 한다.
	for (; pNode; pNode = pNode->rlink)
		if (pNode->nData == nData)
			break;
	return pNode;
	/*if (pNode == NULL || pNode->nData == nData)
		return pNode;
	return Find(pNode->rlink, nData);*/
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
