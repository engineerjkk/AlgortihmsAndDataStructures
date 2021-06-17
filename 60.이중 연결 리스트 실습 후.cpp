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
	NodePtr pFirst = NULL; //���� �տ� ���
	NodePtr pNode = NULL;//find�Ҷ� Ȱ��ȭ
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
	// pLeft ��� �����ʿ� nData�� ������ ��带 �����Ѵ�.
	// pLeft�� NULL�̸� ù ���� �����Ѵ�.
	// pLeft�� ȣ���ϱ� ������ find�� ���Ͽ� ���� �����Ͽ��� �Ѵ�.
	/*NodePtr pRght, pNew = new Node;
	if (pNew) {
		pNew->nData = nData;
		pRght = pLeft ? pLeft->rlink : pFirst;//�갡 NULL�̸� �ȵǹǷ� pLeft�� ���� ������ rlink��, ������ pFirst�� �ȴ�.
		if (pLeft) {
			pRght = pLeft->rlink;
		}
		else {
			pRght = pFirst;
			pFirst = pNew;
		}
		pNew->llink = pLeft;
		pNew->rlink = pRght; //������� �Ķ���
		pLeft && (pLeft->rlink = pNew);//pL
		pRght&& pRght->llink = pNew;//������� ������
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
	// pDelNode�� �����Ѵ�.
	// pDelNode�� ȣ���ϱ� ������ find�� ���Ͽ� ���� �����Ͽ��� �Ѵ�.
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
	// nData�� ������ ��带 ã�µ� ������ NULL�� return �Ѵ�.
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
