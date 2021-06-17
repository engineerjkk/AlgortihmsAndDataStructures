#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

typedef struct node{		/* Term: ���� �����Ѵ� */
	int nCoef;//���
	int nExpon;//����
	struct node *link;//��ũ
}	Node, *NodePtr, *Polynomial;

void main()
{
	Node A[] = {{6, 3, A + 1}, {-1, 2, A + 2}, {-2, 1, NULL }}; 
	Node B[] = {{5, 4, B + 1}, {-1, 2, B + 2}, { 2, 1, B + 3}, {8, 0, NULL}};
	Polynomial polyA = A;
	Polynomial polyB = B;
	Polynomial polyC = NULL;
	int InputPolynomial(Polynomial& pPoly, const char *szMsg);
	void OutputPolynomial(Polynomial A, const char *szMsg);
	void FreePolynomial(Polynomial& pPolyA);
	int Attach(NodePtr& pLastNode, int nCoef, int nExpon);
	int AddPolynomial(Polynomial A, Polynomial B, Polynomial& C);
	int SubPolynomial(Polynomial A, Polynomial B, Polynomial& C);
	int SimpleMulPolynomial(Polynomial A, int nCoef, int nExpon, Polynomial& B);
	int MultiplyPolynomial(Polynomial A, Polynomial B, Polynomial& C);
	int bContinue = true;
	while (bContinue) {
		int nFtn;
		printf("1: A, 2: B, 3: Add, 4: Sub, 5: Simple, 6: Mul, 7: pr ? ");
		scanf("%d", &nFtn);
		if (polyC)
			FreePolynomial(polyC);
		switch (nFtn) {
		case 1:
			if (InputPolynomial(polyA, "A") == 0)	// ���׽� A�� �Է��Ѵ�.
				printf("Input Error\n");
			break;
		case 2:
			if (InputPolynomial(polyB, "B") == 0)	// ���׽� B�� �Է��Ѵ�.
				printf("Input Error\n");
			break;
		case 3:										// ���Ѵ�.
			if (AddPolynomial(polyA, polyB, polyC))
				OutputPolynomial(polyC, "C(X) = ");	// C�� ����Ѵ�.
			break;
		case 4:										// ����.
			if (SubPolynomial(polyA, polyB, polyC))
				OutputPolynomial(polyC, "C(X) = ");	// C�� ����Ѵ�.
			break;
		case 5:										// ������ ���Ѵ�.
			SimpleMulPolynomial(polyA, polyB[0].nCoef, polyB[0].nExpon, polyC);
			OutputPolynomial(polyC, "C(X) = ");		// C�� ����Ѵ�.
			break;
		case 6:										// ���Ѵ�.
			if (MultiplyPolynomial(polyA, polyB, polyC))
				OutputPolynomial(polyC, "C(X) = ");	// C�� ����Ѵ�.
			break;
		case 7:
			OutputPolynomial(polyA, "A(X) = ");		// A�� ����Ѵ�.
			OutputPolynomial(polyB, "B(X) = ");		// B�� ����Ѵ�.
			break;
		default:
			bContinue = false;
		}
		putchar('\n');
	}
}

int Attach(NodePtr& pLast, int nCoef, int nExpon)
{
	// ������ ������ �ִ��� �����Ͽ� �� ���� ���� �����Ѵ�.
	// �����̸� true��, �����ϸ� false�� return�Ѵ�.
	NodePtr pNode = (NodePtr)malloc(sizeof(Node));
	if (pNode) {
		pLast = pLast->link = pNode;
		pNode->nCoef = nCoef;
		pNode->nExpon = nExpon;
	}
	return (int)pNode; //pNode != NULL; �� �Ȱ���.
}

int AddPolynomial(Polynomial pPolyA, Polynomial pPolyB, Polynomial& pPolyC)
{
	pPolyC = (Polynomial)malloc(sizeof(Node));
	if (pPolyC == NULL) //ù��°���
		return false;
	NodePtr pLast = pPolyC;
	while (pPolyA && pPolyB) {
		if (pPolyA->nExpon > pPolyB->nExpon) {
			if (Attach(pLast, pPolyA->nCoef, pPolyA->nExpon) == false)
				return false;
			pPolyA = pPolyA->link;
		}
		else if (pPolyA->nExpon == pPolyB->nExpon) {
			int nCoef = pPolyA->nCoef + pPolyB->nCoef;
			if (nCoef)
				if (Attach(pLast, nCoef, pPolyA->nExpon) == false)
					return false; 
			pPolyA = pPolyA->link;
			pPolyB = pPolyB->link;
		}
		else { //pPolyA->nExpon < pPolyB->nExpon
			if (Attach(pLast, pPolyB->nCoef, pPolyB->nExpon) == NULL)
				return false;
			pPolyB = pPolyB->link;
		}
	}
	for (; pPolyA;pPolyA=pPolyA->link) {//A�� ������� Attach
		if (Attach(pLast, pPolyA->nCoef, pPolyA->nExpon) == false)//A�� ����,��� pLast
			return false;
	for (; pPolyB; pPolyB = pPolyB->link) {//A�� ������� Attach
		if (Attach(pLast, pPolyB->nCoef, pPolyB->nExpon) == false)//A�� ����,��� pLast
			return false;
		pPolyA = pPolyA->link;//A����
	}
	pLast->link = NULL;
	NodePtr pDel = pPolyC;
	pPolyC = pPolyC->link;
	free(pDel);
	return true;	// �����̸� true��, �����ϸ� false�� return�Ѵ�.
}

int SubPolynomial(Polynomial pPolyA, Polynomial pPolyB, Polynomial& pPolyC)
{
	return true;	/* �����̸� true��, �����ϸ� false�� return�Ѵ� */
}

int SimpleMulPolynomial(Polynomial pPolyA, int nCoef, int nExpon, Polynomial& pPolyB)
{
	// ���׽� A�� �� ���� ���Ͽ� ���׽� B�� �����Ѵ�.
	return true;
}

int MultiplyPolynomial(Polynomial pPolyA, Polynomial pPolyB, Polynomial& pPolyC)
{
	// �� ���׽� A, B�� ���Ͽ� ���׽� C�� �����Ѵ�.
	// �����̸� true��, �����ϸ� false�� return�Ѵ�.
	return true;
}

int CheckPolynomial(Polynomial pNode)	/* ���׽��� �ùٸ��� �ԷµǾ����� ���� */
{
	int nExpon = pNode->nExpon + 1;
	int bRight = true;
	while (pNode) {
		if (pNode->nExpon < 0 || pNode->nExpon >= nExpon)
			/* ������ ����̰� ������������ ���� */
			return false;
		if (pNode->nCoef == 0)			/* ����� 0���� ���� */
			return false;
		nExpon = pNode->nExpon;
		pNode = pNode->link;
	}
	return true;
}

int InputPolynomial(Polynomial& pPoly,const char *szMsg)	/* ���׽��� �Է� */
{
	NodePtr pLast = (NodePtr)malloc(sizeof(Node));
	if (pLast == NULL)
		return false;
	pPoly = pLast;
	fprintf(stderr, "%s ���׽��� �Է��մϴ�.\n", szMsg);
	int nCtr;
	do {
		fprintf(stderr, "���� ������ ? ");
		scanf("%d", &nCtr);
		if (nCtr == 0)
			return false;
	} while (nCtr < 0);
	for (int i = 1; i <= nCtr; i++) {
		NodePtr pNode = (NodePtr)malloc(sizeof(Node));
		if (pNode == NULL)
			return false;
		pLast = pLast->link = pNode;
		fprintf(stderr, "%d ��° ���� ����� ? ", i);
		scanf("%d", &pNode->nCoef);
		fprintf(stderr, "%d ��° ���� ������ ? ", i);
		scanf("%d", &pNode->nExpon);
	}
	pLast->link = NULL;					/* ���� ǥ���Ѵ� */
	pLast = pPoly;
	pPoly = pPoly->link;
	free(pLast);
	return CheckPolynomial(pPoly);
}

void OutputPolynomial(Polynomial pPoly, const char *szMsg)	/* ���׽��� ��� */
{
	printf(szMsg);
	int isNotFirst = false;
	while (pPoly) {
		int nCoeff = pPoly->nCoef;		/* ��� */
		int nExpon = pPoly->nExpon;		/* ���� */
		char cSign = '+';
		if (nCoeff < 0) {				/* +/- �غ�*/
			cSign = '-';
			nCoeff = - nCoeff;
		}
		if (isNotFirst || cSign == '-') /* ù ���� ��� */
			printf(" %c ", cSign);		/* ��ȣ ��� */
		if (nCoeff != 1 || nExpon == 0)
			printf("%d", nCoeff);		/* ��� ���*/
		if (nExpon > 0) {
			putchar('X');
			if (nExpon > 1)
				printf("^%d", nExpon);	/* ���� ���*/
		}
		pPoly = pPoly->link;
		isNotFirst = true;
	}
	putchar('\n');
}

void FreePolynomial(Polynomial& pPoly)
{
	while (pPoly) {
		NodePtr pNode = pPoly;
		pPoly = pPoly->link;
		free(pNode);
	}
}