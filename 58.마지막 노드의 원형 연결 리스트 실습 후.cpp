#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

typedef struct node {
	int nData;
	struct node *link;
}	Node, *NodePtr;

void main()
{
	char cmnd[10], data[10];
	NodePtr add(NodePtr pLast, int nData);
	NodePtr del(NodePtr pLast, int *pnData);
	NodePtr invert(NodePtr pNode);
	void print(NodePtr pNode);

	int nData;
	Node *pLast = NULL;
	cmnd[0] = 'a';
	while (cmnd[0]) {
		printf("\n[azdie] ? ");
		gets_s(cmnd);
		switch (*cmnd) {
		case 'a':
		case 'z':
			printf(" ? ");
			gets_s(data);
			pLast = add(pLast, atoi(data));	// �ϴ��� �տ��� �����ϰ�
			if (*cmnd == 'z')//z�̸� last ��� ���� 
				pLast = pLast->link;		// �ϳ� �����ϸ� ���� �ִ� ȿ��
			break;
		case 'd':
			if (pLast) {
				pLast = del(pLast, &nData);
				printf("%d is deleted\n", nData);
			}
			else
				printf("empty list\n");
			break;
		case 'i':
			pLast = invert(pLast);
			break;
		case 'e':
			return;
		}
		print(pLast);
	}
}

NodePtr add(NodePtr pLast, int nData)
{	
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nData; 
		if (pLast) {
			pNew->link = pLast->link;//pLast�� ��ũ�� pNew�� ��������.
			pLast->link = pNew; //pNew�� ��ũ�� pLast�� ��ũ�� ����Ų��.
		}
		else {//pLast�� NULL�� ���
			pNew->link = pNew;
			pLast = pNew;
		}
	}
	return pLast; 
	/*// nData�� ������ ��带 ù ���� �����Ѵ�.
	NodePtr pNode = (NodePtr)malloc(sizeof(Node));
	if (pNode == NULL)
		return pLast;
	pNode->nData = nData;
	if (pLast == NULL)
		pLast = pNode->link = pNode;
	else {
		pNode->link = pLast->link;
		pLast->link = pNode;
	}
	return pLast;*/
}

NodePtr del(NodePtr pLast, int *pnData)
{
	if (pLast) {
		NodePtr pDel = pLast->link;
		*pnData = pDel->nData;//������ �޾Ƴ���
		if (pLast == pDel)//pLast�� �Ѱ��϶������� pLast�� NULL�� ����Ű���Ѵ� �׷��� ������ �� �����ǰ� pLast�� ����� ����Ű�� �״´�.
			pLast = NULL;
		else
			pLast->link = pDel->link;//��ũ �����ϰ�
		delete pDel; //�����ش�.
		
	}
	return pLast;
	// ù��° ��带 �����ϰ� �� ���� pnData�� �����Ѵ�.
	/*if (pLast) {
		NodePtr pNode = pLast->link;	// ù ���
		*pnData = pNode->nData;			// ù ����� ����Ÿ
		if (pLast->link == pLast)		// �� ��常 �ִ� ���
			pLast = NULL;
		else
			pLast->link = pNode->link;
		free(pNode);
	}
	return pLast;*/
}

NodePtr invert(NodePtr pLast)
{
	// ��ȯ ����Ʈ�� �Ųٷ� �����´�.
	if (pLast) {
		NodePtr pNode = pLast = pLast->link;	// ù��带 ������ ����
		NodePtr pTrail = NULL;					// ��ȯ�� ���� ���Ͽ�
		while (pNode) {
			NodePtr pTemp = pTrail;
			pTrail = pNode;
			pNode = pNode->link;
			pTrail->link = pTemp;
		}
	}
	return pLast;
}

void print(NodePtr pLast)
{
	if (pLast == NULL)
		return;
	NodePtr pNode = pLast;
	do {
		pNode = pNode->link;
		printf("%d ", pNode->nData);
	} while (pNode != pLast);
	printf("\n");
}
