#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ISP			1
#define ICP			2
#define STACK_SIZE	40
#define EXPR_SIZE	100
#define OPERANDS	5
#define	MinOpr		'@'
#pragma warning (disable: 4996)

typedef int Item;
typedef struct {
	int nTop;
	Item items[STACK_SIZE];
}	Stack, *StackPtr;

void main()
{
	char sInfix[EXPR_SIZE];							// infix 수식을 입력받기 위하여
	char sPostfix[EXPR_SIZE];						// postfix 수식을 저장하기 위하여
	int  nValues[OPERANDS] = {1, 2, 3, 4, 5};		// 피연산자의 값을 저장하기 위하여
	int *pOprnd = nValues - 'A';					// 피연산자 실제값의 색인을 그대로 사용하기 위하여
	while (1) {										// 즉 피연산자 'A'의 값은 pOprnd['A']가 되도록 한다.
		int Infix2Postfix(char *sInfix, char *sPostfix);
		int EvalPostfix(char *sPostfix, int *pOprnd, int& nValue);
		void GetOperands(int *nValues);
		int noGood = true;
		while (noGood) {							// 완전한 Infix 식을 얻을 때까지
			printf("\n  Infix expression ? ");
			gets_s(sInfix);
			if (*sInfix == NULL)					// 입력된 식이 없으면 멈춘다.
				break;
			if (*sInfix == '?')						// 피연산자들의 값을 입력받는다.
				GetOperands(nValues);
			else {
				noGood = false;
				for (char *pExpr = sInfix; *pExpr; pExpr++) {
					if (isalpha(*pExpr))									// operand
						*pExpr = toupper(*pExpr);							// 대문자로 변환
					else if (strchr("!*/%+-<>=~&|()", *pExpr) == NULL)		// operator
						noGood = true;										// 식에 허용되지 않은 문자가 있음
				}
				if (noGood)
					printf("Error in infix expression, ....\n");			// 식에 오류가 있음
			}
		}
		if (*sInfix == NULL)
			break;
		int isOK = false;
		if (Infix2Postfix(sInfix, sPostfix)) {				// infix를 postfix로 변환하고
			printf("Postfix expression : %s\n", sPostfix);
			int nValue;
			isOK = EvalPostfix(sPostfix, pOprnd, nValue);
			if (isOK)		// 그 변환된 postfix 계산하여 성공하면
				printf("  Expression value : %d\n", nValue);
		}
		if (!isOK)
			printf("Error....\n");
	}
	printf("\nBye, ...\n\n");
}

void GetOperands(int *pValues)						// 수식에 사용할 피연산자 값을 입력한다.
{
	for (int i = 0; i < OPERANDS; i++) {			// 피연산자 A부터 Z까지
		int nVal;
		char values[20];
		printf("%c ? ", i + 'A');					// A부터 Z사이의 피연산자
		gets_s(values);
		if (*values == NULL)						// 입력 값이 없으면 더 이상 계속하지 않는다.
			return;
		if (sscanf(values, "%d", &nVal) != 1)		// error가 나면 멈춘다.
			return;
		pValues[i] = nVal;							// 입력된 피연산자를 저장한다.
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
	aStack.nTop = -1;								// 초기화
	if (Push(&aStack, MinOpr) != MinOpr)			// 제일 바닥에 -무한대를 넣는다.
		return false;
	char *pToken = sInfix - 1;
	while (*++pToken) {
		// ???
	}
	// ???
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
		// ???
	}
	// ???
}

int IsStackEmpty(StackPtr pStack)
{	// 스택이 비어 있으면 true를 return한다.
	return true;
}

int IsStackFull(StackPtr pStack)
{	// 스택이 가득차 있으면 true를 return한다.
	return true;
}

Item Push(StackPtr pStack, Item anItem)
{	// anItem을 Push하는데 성공(실패)하면 anItem(anItem이 아닌 값)을 반환한다.
	return anItem;
}

Item Pop(StackPtr pStack)
{	// 에러 체크 없이 무조건 pop하여 Item을 return한다.
	return true;
}

Item TopItem(StackPtr pStack)
{	// 에러 체크 없이 꼭데기 원소를 return한다.
	return true;
}

int Priority(char op, int mode)
{	// 연산자 op의 ISP 또는 ICP 우선순위(오류일 경우 -1)를 return한다.
	static char precedence[][3] = {
	//  {Op,  ISP,ICP}
		// ???
		{ MinOpr,  0,  0}};	// 알고리즘 편의상

	int i;
	int nSize = sizeof(precedence) / sizeof(precedence[0]);	// 연산자들의 갯수를 계산
	for (i = 0; i < nSize; i++) {			// 모든 연산자들에 대하여
		if (op == precedence[i][0])			// 원하는 연산자를 찾고
			return precedence[i][mode];		// 그 연산자의 ISP 또는 ICP 우선순위를 전달
	}
	return -1;								// 그러한 연산자 없음
}
