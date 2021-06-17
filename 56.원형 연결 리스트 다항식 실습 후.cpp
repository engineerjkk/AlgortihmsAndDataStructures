#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

typedef struct node{		/* Term: 항을 정의한다 */
	int nCoef;
	int nExpon;
	struct node *link;
}	Node, *NodePtr, *Polynomial;

void main()
{
	Node A[] = {{0, -1, A + 1 },{6, 3, A + 2},{-1, 2, A + 3},{-2, 1, A} };
	Node B[] = {{0, -1, B + 1 },{5, 4, B + 2},{-1, 2, B + 3},{2, 1, B + 4}, {8, 0, B}};
	Polynomial polyA = A;
	Polynomial polyB = B;
	Polynomial polyC = NULL;
	int InputPolynomial(Polynomial& pPoly, const char *szMsg);
	void OutputPolynomial(Polynomial A, const char *szMsg);
	void FreePolynomial(Polynomial& pPolyA);
	int Attach(Polynomial aPoly, int nCoef, int nExpon);
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
			if (InputPolynomial(polyA, "A") == 0)	// 다항식 A를 입력한다.
				printf("Input Error\n");
			break;
		case 2:
			if (InputPolynomial(polyB, "B") == 0)	// 다항식 B를 입력한다.
				printf("Input Error\n");
			break;
		case 3:										// 더한다.
			if (AddPolynomial(polyA, polyB, polyC))
				OutputPolynomial(polyC, "C(X) = ");	// C를 출력한다.
			break;
		case 4:										// 뺀다.
			if (SubPolynomial(polyA, polyB, polyC))
				OutputPolynomial(polyC, "C(X) = ");	// C를 출력한다.
			break;
		case 5:										// 한항을 곱한다.
			SimpleMulPolynomial(polyA, polyB[1].nCoef, polyB[1].nExpon, polyC);
			OutputPolynomial(polyC, "C(X) = ");		// C를 출력한다.
			if (polyC)
				FreePolynomial(polyC);
			SimpleMulPolynomial(polyB, polyA[1].nCoef, polyA[1].nExpon, polyC);
			OutputPolynomial(polyC, "C(X) = ");		// C를 출력한다.
			break;
		case 6:										// 곱한다.
			if (MultiplyPolynomial(polyA, polyB, polyC))
				OutputPolynomial(polyC, "C(X) = ");	// C를 출력한다.
			break;
		case 7:
			OutputPolynomial(polyA, "A(X) = ");		// A를 출력한다.
			OutputPolynomial(polyB, "B(X) = ");		// B를 출력한다.
			break;
		default:
			bContinue = false;
		}
		putchar('\n');
	}
	printf("Bye, ...\n\n");
}

int Attach(NodePtr& pLast, int nCoef, int nExpon)
{
	// 저장할 공간이 있는지 조사하여 한 항을 끝에 저장한다.
	// 성공이면 true를, 실패하면 false를 return한다.
	NodePtr pNode = (NodePtr)malloc(sizeof(Node));
	if (pNode) {
		pLast = pLast->link = pNode;
		pNode->nCoef = nCoef;
		pNode->nExpon = nExpon;
	}
	return (int)pNode;
}

NodePtr GetHeadNode()
{
	NodePtr pHead = (Polynomial)malloc(sizeof(Node));//메모리 하나받아서  지수부분에 -1을 넣는다. 
	if (pHead) {
		pHead->nExpon = -1;
		pHead->link = pHead;//그리고 자기 자신을 가리키도록!
	}
	return pHead;
}

int AddPolynomial(Polynomial pPolyA, Polynomial pPolyB, Polynomial& pPolyC)
{
	NodePtr pLast;
	if ((pLast = pPolyC = GetHeadNode()) == NULL)
		return false;
	pPolyA = pPolyA->link;//헤드 노드 전진
	pPolyB = pPolyB->link;//헤드 노드 전진
	while (1) {
		if (pPolyA->nExpon > pPolyB->nExpon) {
			if (Attach(pLast, pPolyA->nCoef, pPolyA->nExpon) == false)
				return false;
			pPolyA = pPolyA->link;
		}
		else if (pPolyA->nExpon == pPolyB->nExpon) {
			if (pPolyA->nExpon == -1)//양쪽다 한바퀴 돌았으니 브레이크.
				break;
			int nCoef = pPolyA->nCoef + pPolyB->nCoef;
			if (nCoef)
				if (Attach(pLast, nCoef, pPolyA->nExpon) == false)
					return false;
			pPolyA = pPolyA->link;
			pPolyB = pPolyB->link;
		}
		else {
			if (Attach(pLast, pPolyB->nCoef, pPolyB->nExpon) == false)
				return false;
			pPolyB = pPolyB->link;
		}
	}
	pLast->link = pPolyC;
	return true;	// 성공이면 true를, 실패하면 false를 return한다.
}

int SubPolynomial(Polynomial pPolyA, Polynomial pPolyB, Polynomial& pPolyC)
{
	NodePtr pLast;
	if ((pLast = pPolyC = GetHeadNode()) == NULL)
		return false;
	pPolyA = pPolyA->link;
	pPolyB = pPolyB->link;
	while (1) {
		if (pPolyA->nExpon > pPolyB->nExpon) {
			if (Attach(pLast, pPolyA->nCoef, pPolyA->nExpon) == false)
				return false;
			pPolyA = pPolyA->link;
		}
		else if (pPolyA->nExpon == pPolyB->nExpon) {
			if (pPolyA->nExpon == -1)
				break;
			int nCoef = pPolyA->nCoef - pPolyB->nCoef;
			if (nCoef)
				if (Attach(pLast, nCoef, pPolyA->nExpon) == false)
					return false;
			pPolyA = pPolyA->link;
			pPolyB = pPolyB->link;
		}
		else {
			if (Attach(pLast, -pPolyB->nCoef, pPolyB->nExpon) == false)
				return false;
			pPolyB = pPolyB->link;
		}
	}
	pLast->link = pPolyC;
	return true;	// 성공이면 true를, 실패하면 false를 return한다.
}

int SimpleMulPolynomial(Polynomial pPolyA, int nCoef, int nExpon, Polynomial& pPolyB)
{	// 다항식 A와 한 항을 곱하여 다항식 B에 저장한다.
	NodePtr pLast;
	if ((pLast = pPolyB = GetHeadNode()) == NULL)
		return false;
	for (pPolyA=pPolyA->link;pPolyA->nExpon>=0;pPolyA=pPolyA->link)
		if (Attach(pLast, pPolyA->nCoef * nCoef, pPolyA->nExpon + nExpon) == false)
			return false;
	pLast->link = pPolyB;
	return true;
}

int MultiplyPolynomial(Polynomial pPolyA, Polynomial pPolyB, Polynomial& pPolyC)
{	// 두 다항식 A, B를 곱하여 다항식 C에 저장한다.
	// 성공이면 true를, 실패하면 false를 return한다.
	pPolyA = pPolyA->link;
	if (pPolyA->nExpon == -1)//-1이면 끝났다.
		return (int)(pPolyC = GetHeadNode());
	Polynomial C1, C2;
	return MultiplyPolynomial(pPolyA->link, pPolyB, C1) &&
		   SimpleMulPolynomial(pPolyB, pPolyA->nCoef, pPolyA->nExpon, C2) &&
		   AddPolynomial(C1, C2, pPolyC);
}

int CheckPolynomial(Polynomial pPoly)	/* 다항식이 올바르게 입력되었는지 조사 */
{
	Polynomial pNode = pPoly->link;
	int nExpon = pNode->nExpon + 1;
	int bRight = true;
	while (pNode != pPoly) {
		if (pNode->nExpon < 0 || pNode->nExpon >= nExpon)
			/* 지수가 양수이고 내림차순인지 조사 */
			return false;
		if (pNode->nCoef == 0)			/* 계수가 0인지 조사 */
			return false;
		nExpon = pNode->nExpon;
		pNode = pNode->link;
	}
	return pNode->nExpon == -1;
}

int InputPolynomial(Polynomial& pPoly, const char *szMsg)	/* 다항식을 입력 */
{
	NodePtr pLast = (NodePtr)malloc(sizeof(Node));
	if (pLast == NULL)
		return false;
	pLast->nExpon = -1;
	pPoly = pLast;
	fprintf(stderr, "%s 다항식을 입력합니다.\n", szMsg);
	int nCtr;
	do {
		fprintf(stderr, "항의 갯수는 ? ");
		scanf("%d", &nCtr);
		if (nCtr == 0)
			return false;
	} while (nCtr < 0);
	for (int i = 1; i <= nCtr; i++) {
		NodePtr pNode = (NodePtr)malloc(sizeof(Node));
		if (pNode == NULL)
			return false;
		pLast = pLast->link = pNode;
		fprintf(stderr, "%d 번째 항의 계수는 ? ", i);
		scanf("%d", &pNode->nCoef);
		fprintf(stderr, "%d 번째 항의 지수는 ? ", i);
		scanf("%d", &pNode->nExpon);
	}
	pLast->link = pPoly;				/* 끝을 표시한다 */
	return CheckPolynomial(pPoly);
}

void OutputPolynomial(Polynomial pPoly,const char *szMsg)	/* 다항식을 출력 */
{
	printf(szMsg);
	int isNotFirst = false;
	pPoly = pPoly->link;
	while (pPoly->nExpon != -1) {
		int nCoeff = pPoly->nCoef;		/* 계수 */
		int nExpon = pPoly->nExpon;		/* 지수 */
		char cSign = '+';
		if (nCoeff < 0) {				/* +/- 준비*/
			cSign = '-';
			nCoeff = - nCoeff;
		}
		if (isNotFirst || cSign == '-') /* 첫 항이 양수 */
			printf(" %c ", cSign);		/* 부호 출력 */
		if (nCoeff != 1 || nExpon == 0)
			printf("%d", nCoeff);		/* 계수 출력*/
		if (nExpon > 0) {
			putchar('X');
			if (nExpon > 1)
				printf("^%d", nExpon);	/* 지수 출력*/
		}
		pPoly = pPoly->link;
		isNotFirst = true;
	}
	putchar('\n');
}

void FreePolynomial(Polynomial& pPoly)
{
	NodePtr pNode = pPoly;
	pPoly = pPoly->link;
	pNode->link = NULL;
	while (pPoly) {
		pNode = pPoly;
		pPoly = pPoly->link;
		free(pNode);
	}
}