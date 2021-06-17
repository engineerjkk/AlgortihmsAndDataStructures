#include <stdio.h>

#define STACK_SIZE 40
#define EXPR_SIZE  100
#define OPERANDS   5
#pragma warning (disable: 4996)

typedef int Item;

typedef struct {
	int nTop;
	Item items[STACK_SIZE];
}	Stack, *StackPtr;

void main()
{
	int nOprnd[] = {1, 2, 3, 4, 5};
	while (1) {
		char sPostfix[EXPR_SIZE];
		printf("\nPostfix Expr[?x] ? ");
		gets_s(sPostfix);
		int nResult;
		if (*sPostfix == 'x' || *sPostfix == NULL)
			return;
		else if (*sPostfix == '?') {
			void GetOperands(int nOprnd[]);
			GetOperands(nOprnd);
		}
		else {
			int EvalPostfixExpr(char *sPostfixExpr, int *pnResult, int nOprnd[]);
			if (EvalPostfixExpr(sPostfix, &nResult, nOprnd))
				printf("Result : %d\n", nResult);
			else
				printf("Error...\n");
		}
	}
}

void GetOperands(int nOprnd[])						// 수식에 사용할 피연산자 값을 입력한다.
{
	for (int i = 0; i < OPERANDS; i++) {			// 피연산자 A부터 E까지
		int nVal;
		char values[20];
		printf("%c ? ", i + 'A');					// A부터 E사이의 피연산자
		gets_s(values);
		if (sscanf(values, "%d", &nVal) != 1)		// error가 나면 멈춘다.
			return;
		nOprnd[i] = nVal;							// 입력된 피연산자를 저장한다.
	}
}

int EvalPostfixExpr(char *sPostfixExpr, int *pnResult, int nOprnd[])
{
	int push(StackPtr pStack, Item nValue);
	int pop(StackPtr pStack, Item *pnValue);

	Stack aStack;
	aStack.nTop = -1;
	char *pToken = sPostfixExpr - 1;
	while (*++pToken) {
		if (*pToken >= 'A' && *pToken <= 'E') {
			if (push(&aStack, nOprnd[*pToken - 'A']) == false)
				return false;
		}
		else {
			int nValueA, nValueB;
			if (pop(&aStack, &nValueB) == false)
				return false;
			if (*pToken != '!' && pop(&aStack, &nValueA) == false)
				return false;
			switch (*pToken) {
			case '+':
				nValueA += nValueB;
				break;
			case '-':
				nValueA -= nValueB;
				break;
			case '*':
				nValueA *= nValueB;
				break;
			case '/':
				if (nValueB == 0)
					return printf("Divide By Zero, ") == 0;
				nValueA /= nValueB;
				break;
			case '<':
				nValueA = nValueA < nValueB;
				break;
			case '>':
				nValueA = nValueA > nValueB;
				break;
			case '=':
				nValueA = nValueA == nValueB;
				break;
			case '&':
				nValueA = nValueA && nValueB;
				break;
			case '|':
				nValueA = nValueA || nValueB;
				break;
			case '!':
				nValueA = !nValueB;
			}
			if (push(&aStack, nValueA) == false)
				return false;
		}
	}
	*pnResult = aStack.items[0];
	return aStack.nTop == 0;
}

int IsStackEmpty(StackPtr pStack)
{	// 스택이 비었는지를 return 한다
	return pStack->nTop < 0;
}

int IsStackFull(StackPtr pStack)
{	// 스택이 가득 찼는지를 return 한다
	return pStack->nTop >= STACK_SIZE-1;
}

int push(StackPtr pStack, Item nValue)
{	// 스택에 nValue를 push하는데, true/false를 return 한다.
	if (IsStackFull(pStack))
		return false;
	pStack->items[++pStack->nTop] = nValue;
	return true;
}

int pop(StackPtr pStack, Item *pnValue)
{	// 스택에서 pop하여 pnValue에 저장하는데, true/false를 return 한다.
	if (IsStackEmpty(pStack))
		return false;
	*pnValue = pStack->items[pStack->nTop--];
	return true;
}
