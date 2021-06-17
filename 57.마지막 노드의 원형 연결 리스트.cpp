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
			if (*cmnd == 'z')
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
	// nData�� ������ ��带 ù ���� �����Ѵ�.
	return pLast;
}

NodePtr del(NodePtr pLast, int *pnData)
{
	// ù��° ��带 �����ϰ� �� ���� pnData�� �����Ѵ�.
	return pLast;
}

NodePtr invert(NodePtr pLast)
{
	// ��ȯ ����Ʈ�� �Ųٷ� �����´�.
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
