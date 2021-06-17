#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ISP			1
#define ICP			2
#define STACK_SIZE	40
#define EXPR_SIZE	100
#define OPERANDS	5
#define	MinOpr		'?'
#pragma warning (disable: 4996)

typedef int Item;
typedef struct {
	int nTop;
	Item items[STACK_SIZE];
}	Stack, *StackPtr;

void main()
{
	char sInfix[EXPR_SIZE];							// infix ������ �Է¹ޱ� ���Ͽ�
	char sPostfix[EXPR_SIZE];						// postfix ������ �����ϱ� ���Ͽ�
	int  nValues[OPERANDS] = {1, 2, 3, 4, 5};		// �ǿ������� ���� �����ϱ� ���Ͽ�
	int *pOprnd = nValues - 'A';					// �ǿ����� �������� ������ �״�� ����ϱ� ���Ͽ�
	while (1) {										// �� �ǿ����� 'A'�� ���� pOprnd['A']�� �ǵ��� �Ѵ�.
		int Infix2Postfix(char *sInfix, char *sPostfix);
		int EvalPostfix(char *sPostfix, int *pOprnd, int& nValue);
		void GetOperands(int *nValues);
		int noGood = true;
		while (noGood) {							// ������ Infix ���� ���� ������
			printf("\n  Infix expression ? ");
			gets_s(sInfix);
			if (*sInfix == NULL)					// �Էµ� ���� ������ �����.
				break;
			if (*sInfix == '?')						// �ǿ����ڵ��� ���� �Է¹޴´�.
				GetOperands(nValues);
			else {
				noGood = false;
				for (char *pExpr = sInfix; *pExpr; pExpr++) {
					if (isalpha(*pExpr))									// operand
						*pExpr = toupper(*pExpr);							// �빮�ڷ� ��ȯ
					else if (strchr("!*/%+-<>=~&|()", *pExpr) == NULL)		// operator
						noGood = true;										// �Ŀ� ������ ���� ���ڰ� ����
				}
				if (noGood)
					printf("Error in infix expression, ....\n");			// �Ŀ� ������ ����
			}
		}
		if (*sInfix == NULL)
			break;
		int isOK = false;
		if (Infix2Postfix(sInfix, sPostfix)) {				// infix�� postfix�� ��ȯ�ϰ�
			printf("Postfix expression : %s\n", sPostfix);
			int nValue;
			isOK = EvalPostfix(sPostfix, pOprnd, nValue);
			if (isOK)		// �� ��ȯ�� postfix ����Ͽ� �����ϸ�
				printf("  Expression value : %d\n", nValue);
		}
		if (!isOK)
			printf("Error....\n");
	}
	printf("\nBye, ...\n\n");
}

void GetOperands(int *pValues)						// ���Ŀ� ����� �ǿ����� ���� �Է��Ѵ�.
{
	for (int i = 0; i < OPERANDS; i++) {			// �ǿ����� A���� Z����
		int nVal;
		char values[20];
		printf("%c ? ", i + 'A');					// A���� Z������ �ǿ�����
		gets_s(values);
		if (*values == NULL)						// �Է� ���� ������ �� �̻� ������� �ʴ´�.
			return;
		if (sscanf(values, "%d", &nVal) != 1)		// error�� ���� �����.
			return;
		pValues[i] = nVal;							// �Էµ� �ǿ����ڸ� �����Ѵ�.
	}
}

int Infix2Postfix(char *sInfix, char *sPostfix)
{
	int IsStackEmpty(StackPtr pStack);
	Item Push(StackPtr pStack, Item anItem);
	Item Pop(StackPtr pStack);
	Item TopItem(StackPtr pStack);
	int  Priority(char op, int mode);

	Stack aStack;
	aStack.nTop = -1;								// �ʱ�ȭ
	if (Push(&aStack, MinOpr) != MinOpr)			// ���� �ٴڿ� -���Ѵ븦 �ִ´�.
		return false;
	char *pToken = sInfix - 1;
	while (*++pToken) {
		if (isalpha(*pToken)) 						// �ǿ������̸� 
			*sPostfix++ = *pToken;					// ��¿� �ش�
		else if (*pToken == ')') {					// ')'�� ó��
			if (IsStackEmpty(&aStack))
				return false;
			while (TopItem(&aStack) != '(') {		// (�� �ƴ� ������
				*sPostfix++ = Pop(&aStack);			// ��¿� �ش�
				if (IsStackEmpty(&aStack))
					return false;
			}
			Pop(&aStack);							// '('�� ������
		}
		else {										// �������̸� 
			int nICP, nISP;
			if ((nICP = Priority(*pToken, ICP)) < 0)
				return false;
			if (IsStackEmpty(&aStack) ||
				(nISP = Priority(TopItem(&aStack), ISP)) < 0)
				return false;
			while (nISP >= nICP) {					// ISP�� ICP���� ���ų� ������
				*sPostfix++ = Pop(&aStack);			// ��¿� �ش�
				if (IsStackEmpty(&aStack) ||
					(nISP = Priority(TopItem(&aStack), ISP)) < 0)
					return false;
			}
			if (Push(&aStack, *pToken) != *pToken)	// �ڽ��� ���ÿ� ����.
				return false;
		}
	}
	while (aStack.nTop > 0)							// ���ÿ� �ִ� ������ �����ڵ鿡 ���Ͽ�
		*sPostfix++ = Pop(&aStack);					// ���
	*sPostfix = NULL;								// ������ ���� ǥ��
	return true;
}

int EvalPostfix(char *sPostfix, int *pValues, int& nValue)
{
	int IsStackEmpty(StackPtr pStack);
	Item Push(StackPtr pStack, Item anItem);
	Item Pop(StackPtr pStack);

	Stack aStack;
	aStack.nTop = -1;
	char *pToken = sPostfix - 1;
	while (*++pToken) {
		if (isalpha(*pToken)) {						// �ǿ������̸�
			Item anItem = pValues[*pToken];
			if (Push(&aStack, anItem) != anItem)	// �ǿ������� ���� ���� Push�Ѵ�.
				return false;
		}
		else {
			int nValueA, nValueB;
			if (IsStackEmpty(&aStack))
				return false;
			nValueB = Pop(&aStack);
			if (*pToken != '!') {				// Unary �ƴѵ�
				if (IsStackEmpty(&aStack))		// empty�̸�
					return false;
				nValueA = Pop(&aStack);
			}
			int nResult;
			if (*pToken == '!')					// NOT
				nResult = !nValueB;
			else if (*pToken == '*')			// ���ϱ�
				nResult =  nValueA * nValueB;
			else if (*pToken == '/') {			// ������
				if (nValueB == 0) {
					printf("Divide by zero, ...\n");
					return false;
				}
				nResult = nValueA / nValueB;
			}
			else if (*pToken == '%') {			// ������
				if (nValueB == 0) {
					printf("Divide by zero, ...\n");
					return false;
				}
				nResult = nValueA % nValueB;
			}
			else if (*pToken == '+')			// ���ϱ�
				nResult =  nValueA + nValueB;
			else if (*pToken == '-')			// ����
				nResult =  nValueA - nValueB;
			else if (*pToken == '>')			// ũ��
				nResult =  nValueA > nValueB;
			else if (*pToken == '<')			// �۴�
				nResult =  nValueA < nValueB;
			else if (*pToken == '=')			// ����
				nResult =  nValueA == nValueB;
			else if (*pToken == '~')			// �ٸ���
				nResult =  nValueA != nValueB;
			else if (*pToken == '&')			// AND
				nResult =  nValueA && nValueB;
			else if (*pToken == '|')			// OR
				nResult =  nValueA || nValueB;
			else
				return false;					// �߸��� ������
			if (Push(&aStack, nResult) != nResult)
				return false;
		}
	}
	if (IsStackEmpty(&aStack))
		return false;
	nValue = Pop(&aStack);						// Pop�Ͽ� ���� ���
	return IsStackEmpty(&aStack);				// �� �����̸� ����
}

int IsStackEmpty(StackPtr pStack)
{	// ������ ��� ������ true�� return�Ѵ�.
	return pStack->nTop <= -1;
}

int IsStackFull(StackPtr pStack)
{	// ������ ������ ������ true�� return�Ѵ�.
	return pStack->nTop >= STACK_SIZE - 1;
}

Item Push(StackPtr pStack, Item anItem)
{	// anItem�� Push�ϴµ� ����(����)�ϸ� anItem(anItem�� �ƴ� ��)�� ��ȯ�Ѵ�.
	if (IsStackFull(pStack))
		return !anItem;
	return pStack->items[++pStack->nTop] = anItem;
}

Item Pop(StackPtr pStack)
{	// ���� üũ ���� ������ pop�Ͽ� Item�� return�Ѵ�.
	return pStack->items[pStack->nTop--];
}

Item TopItem(StackPtr pStack)
{	// ���� üũ ���� ������ ���Ҹ� return�Ѵ�.
	return pStack->items[pStack->nTop];
}

int Priority(char op, int mode)
{	// ������ op�� ISP �Ǵ� ICP �켱����(������ ��� -1)�� return�Ѵ�.
	static char precedence[][3] = {
	//  {Op,  ISP,ICP}
		{'!',  8,  9},		// !		<--		;; !(NOT)
		{'*',  7,  7},		// *		-->
		{'/',  7,  7},		// /		-->
		{'%',  7,  7},		// %		-->
		{'+',  6,  6},		// +		-->
		{'-',  6,  6},		// -		-->
		{'>',  5,  6},		// >		<--		;; ũ��
		{'<',  5,  6},		// <		<--		;; �۴�
		{'=',  4,  5},		// =		<--		;; ����(==)
		{'~',  4,  5},		// ~		<--		;; �ٸ���(!=)
		{'&',  3,  3},		// &		-->		;; AND(&&)
		{'|',  2,  2},		// |		-->		;; OR(||)
		{'(',  1,  9},
		{ MinOpr,  0,  0}};	// �˰��� ���ǻ�

	int i;
	int nSize = sizeof(precedence) / sizeof(precedence[0]);	// �����ڵ��� ������ ���
	for (i = 0; i < nSize; i++) {			// ��� �����ڵ鿡 ���Ͽ�
		if (op == precedence[i][0])			// ���ϴ� �����ڸ� ã��
			return precedence[i][mode];		// �� �������� ISP �Ǵ� ICP �켱������ ����
	}
	return -1;								// �׷��� ������ ����
}