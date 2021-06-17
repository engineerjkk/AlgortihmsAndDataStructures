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
	// pLeft ��� �����ʿ� nData�� ������ ��带 �����Ѵ�.
	// pLeft�� NULL�̸� ù ���� �����Ѵ�.
	// pLeft�� ȣ���ϱ� ������ find�� ���Ͽ� ���� �����Ͽ��� �Ѵ�.
	// pRight = ?
	// pLeft��  ��(��)�� ���
	// pRight�� ��(��)�� ���
	//
	return pFirst;
}

NodePtr Delete(NodePtr pFirst, NodePtr pDel)
{
	// pNode�� �����Ѵ�.
	// pNode�� ȣ���ϱ� ������ find�� ���Ͽ� ���� �����Ͽ��� �Ѵ�.
	// pLeft = ?, pRight = ?
	// pLeft��  ��(��)�� ���
	// pRight�� ��(��)�� ���
	//
	return pFirst;
}

NodePtr Find(NodePtr pNode, int nData)
{
	// nData�� ������ ��带 ã�µ� ������ NULL�� return �Ѵ�.
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
