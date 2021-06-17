#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

typedef struct node {
	int nData;
	struct node *link;
}	Node, *NodePtr;

void main()
{
	NodePtr Add(NodePtr pFirst, int nData);
	NodePtr Insert(NodePtr pFirst, int nData, NodePtr pPrev);
	NodePtr Delete(NodePtr pFirst, int nData);
	NodePtr Find(NodePtr pFirst, int nData);
	void PrintList(NodePtr pFirst);
	NodePtr pFirst = NULL;
	NodePtr pPrev = NULL;
	while (1) {
		printf("[aidfe] ? ");
		char sCmnd[10];
		gets_s(sCmnd);
		if (*sCmnd == 'e')
			return;
		printf("Data ? ");
		char sData[10];
		gets_s(sData);
		int nData = atoi(sData);
		switch (*sCmnd) {
		case 'a':
			pFirst = Add(pFirst, nData);
			break;
		case 'f':
			pPrev = Find(pFirst, nData);  
			printf("%s\n", (pPrev) ? "Good" : "Bad");
			break;
		case 'i':
			pFirst = Insert(pFirst, nData, pPrev);
			break;
		case 'd':
			pFirst = Delete(pFirst, nData);
		}
		PrintList(pFirst);
	}
}

NodePtr Add(NodePtr pFirst, int nData)
{
	// pFirst�� ����Ű�� Linked List�� ���� �տ� nData�� ������ ��带 �����Ѵ�.
	//  pFirst�� ����Ű�� Linked List�� ��尡 �ϳ��� ���� ���� �ִ�.
	//NodePtr pNew = (NodePtr)malloc(sizeof(Node));
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nData;
		pNew->link = pFirst;
		pFirst = pNew;
	}
	else
		printf("malloc fails");
	return pFirst;
}

NodePtr Find(NodePtr pFirst, int nData)
{
	// ����� ����Ÿ ���� nData ���� ������ ù��° ��带 ã�Ƽ� �� ��带 return�Ѵ�.
	// ���࿡ �׷��� ��尡 ������ NULL�� return�Ѵ�.
	NodePtr pNode = pFirst;
	while (pNode) {
		if (pNode->nData == nData)
			break;
		pNode = pNode->link;
	}
	return pNode;
}

NodePtr Insert(NodePtr pFirst, int nData, NodePtr pPrev)
{
	// pFirst�� ����Ű�� Linked List���� pPrev ��� �ڿ� nData�� ������ ��带 �����Ѵ�.
	// ���� pPrev�� NULL�̸� ���� �տ� ���Եȴ�.
	// Insert ����� Find ����� �����Ͽ� pPrev�� ������ ���� ������ �Ŀ� ����ȴٰ� �����Ѵ�.
	NodePtr pNew = new Node; //�޸��Ҵ�
	if (pNew) {//NULL�̾ƴϸ�,
		pNew->nData = nData;
		pNew->link = pPrev->link; //���� ����� ��ũ�� ���� ��� ��ũ�� ���� 3��, pPrev�� NULL�̸� �״´�. ������ ������� �߿�
		pPrev->link = pNew; //pPrev�� link�� pNew�� ����Ų��. pNew��ü ��带 ����Ű�� �� �����͸� ����Ű�� ��.
	}
	else { //�߰��� �ִ°� �ƴ� ù��°���� ������
		pNew->link = pFirst; //pFirst�� ����Ű���� pNew�� ��ũ�� ����Ų��.
		pFirst = pNew;//pFirst�� pNew�� ����Ų��.
		//�ݵ�� �� �ΰ� ������ ���Ѿ��Ѵ�.  
		
	}
	return pFirst;
}

NodePtr Delete(NodePtr pFirst, int nData)
{
	// ����� ����Ÿ ���� nData ���� ������ ù��° ��带 ã�Ƽ� �� ��带 �����Ѵ�.
	// ��带 �����ϱ� ���Ͽ� ���� ��带 �˾ƾ� �ϴµ� Find �Լ��� �˰��򿡼�
	// ������ ���� **pTrail**�� ����� �ٷ� �ڿ� ���� �����ϰ� 
	// ������ ��尡 ã�� ����̸� pTrail�� ���� ��尡 �ȴ�.
	NodePtr pPrev = NULL, pDel = pFirst;
	while (pDel) { //pNode�� Null�϶�����
		if (pDel->nData == nData)
			break;
		pPrev = pDel; // �̷����ϸ� pTrail�� ������ ����´�.
		pDel = pDel->link;//pNode�� ����ĭ����
	}
	if (pDel) {//���� �����Ұ� �ִٸ�!!
		//ù��° ��带 �����ϴ°ſ����� pDel�� NULL�̴�.(pDel->nDate==nData �ÿ� break�� ���������Ƿ� pPrev�� NULL�̱⶧��)
		if (pPrev)//�߰��� �ִ� pdel�� �����ϴ°��
			pPrev->link = pDel->link;//pPrev�� ��ũ�� pDel�� ��ũ�� ī��Ų��.
		else//ù��°�ִ� ��带 �����ϴ� ���, �� pPrev�� ���°���̴�.
			pFirst = pDel->link;
		delete pDel;
	}
	/// <summary>
	/// pPrev->link=pDel->link;
	/// delete pDel;
	/// </summary>
	/// <param name="pFirst"></param>
	/// <param name="nData"></param>
	/// <returns></returns>
	return pFirst;
}

void PrintList(NodePtr pNode)
{
	while (pNode) {//pNode�� NULL�϶����� �����Ѵ�.
		printf("%d ", pNode->nData);
		pNode = pNode->link;//pNode�� link�� ����Ų��.
	}
	printf("\n\n");
}
