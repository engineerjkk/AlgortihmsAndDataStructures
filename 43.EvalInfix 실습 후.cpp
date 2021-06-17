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
		if (isalpha(*pToken)) 						// 피연산자이면 
			*sPostfix++ = *pToken;					// 출력에 해당
		else if (*pToken == ')') {					// ')'를 처리
			if (IsStackEmpty(&aStack))
				return false;
			while (TopItem(&aStack) != '(') {		// (가 아닐 때까지
				*sPostfix++ = Pop(&aStack);			// 출력에 해당
				if (IsStackEmpty(&aStack))
					return false;
			}
			Pop(&aStack);							// '('을 버리고
		}
		else {										// 연산자이면 
			int nICP, nISP;
			if ((nICP = Priority(*pToken, ICP)) < 0)
				return false;
			if (IsStackEmpty(&aStack) ||
				(nISP = Priority(TopItem(&aStack), ISP)) < 0)
				return false;
			while (nISP >= nICP) {					// ISP가 ICP보다 높거나 같으면
				*sPostfix++ = Pop(&aStack);			// 출력에 해당
				if (IsStackEmpty(&aStack) ||
					(nISP = Priority(TopItem(&aStack), ISP)) < 0)
					return false;
			}
			if (Push(&aStack, *pToken) != *pToken)	// 자신은 스택에 들어간다.
				return false;
		}
	}
	while (aStack.nTop > 0)							// 스택에 있는 나머지 연산자들에 대하여
		*sPostfix++ = Pop(&aStack);					// 출력
	*sPostfix = NULL;								// 수식의 끝을 표시
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
		if (isalpha(*pToken)) {						// 피연산자이면
			Item anItem = pValues[*pToken];
			if (Push(&aStack, anItem) != anItem)	// 피연산자의 실제 값을 Push한다.
				return false;
		}
		else {
			int nValueA, nValueB;
			if (IsStackEmpty(&aStack))
				return false;
			nValueB = Pop(&aStack);
			if (*pToken != '!') {				// Unary 아닌데
				if (IsStackEmpty(&aStack))		// empty이면
					return false;
				nValueA = Pop(&aStack);
			}
			int nResult;
			if (*pToken == '!')					// NOT
				nResult = !nValueB;
			else if (*pToken == '*')			// 곱하기
				nResult =  nValueA * nValueB;
			else if (*pToken == '/') {			// 나누기
				if (nValueB == 0) {
					printf("Divide by zero, ...\n");
					return false;
				}
				nResult = nValueA / nValueB;
			}
			else if (*pToken == '%') {			// 나머지
				if (nValueB == 0) {
					printf("Divide by zero, ...\n");
					return false;
				}
				nResult = nValueA % nValueB;
			}
			else if (*pToken == '+')			// 더하기
				nResult =  nValueA + nValueB;
			else if (*pToken == '-')			// 빼기
				nResult =  nValueA - nValueB;
			else if (*pToken == '>')			// 크다
				nResult =  nValueA > nValueB;
			else if (*pToken == '<')			// 작다
				nResult =  nValueA < nValueB;
			else if (*pToken == '=')			// 같다
				nResult =  nValueA == nValueB;
			else if (*pToken == '~')			// 다르다
				nResult =  nValueA != nValueB;
			else if (*pToken == '&')			// AND
				nResult =  nValueA && nValueB;
			else if (*pToken == '|')			// OR
				nResult =  nValueA || nValueB;
			else
				return false;					// 잘못된 연산자
			if (Push(&aStack, nResult) != nResult)
				return false;
		}
	}
	if (IsStackEmpty(&aStack))
		return false;
	nValue = Pop(&aStack);						// Pop하여 값을 얻고
	return IsStackEmpty(&aStack);				// 빈 스택이면 성공
}

int IsStackEmpty(StackPtr pStack)
{	// 스택이 비어 있으면 true를 return한다.
	return pStack->nTop <= -1;
}

int IsStackFull(StackPtr pStack)
{	// 스택이 가득차 있으면 true를 return한다.
	return pStack->nTop >= STACK_SIZE - 1;
}

Item Push(StackPtr pStack, Item anItem)
{	// anItem을 Push하는데 성공(실패)하면 anItem(anItem이 아닌 값)을 반환한다.
	if (IsStackFull(pStack))
		return !anItem;
	return pStack->items[++pStack->nTop] = anItem;
}

Item Pop(StackPtr pStack)
{	// 에러 체크 없이 무조건 pop하여 Item을 return한다.
	return pStack->items[pStack->nTop--];
}

Item TopItem(StackPtr pStack)
{	// 에러 체크 없이 꼭데기 원소를 return한다.
	return pStack->items[pStack->nTop];
}

int Priority(char op, int mode)
{	// 연산자 op의 ISP 또는 ICP 우선순위(오류일 경우 -1)를 return한다.
	static char precedence[][3] = {
	//  {Op,  ISP,ICP}
		{'!',  8,  9},		// !		<--		;; !(NOT)
		{'*',  7,  7},		// *		-->
		{'/',  7,  7},		// /		-->
		{'%',  7,  7},		// %		-->
		{'+',  6,  6},		// +		-->
		{'-',  6,  6},		// -		-->
		{'>',  5,  6},		// >		<--		;; 크다
		{'<',  5,  6},		// <		<--		;; 작다
		{'=',  4,  5},		// =		<--		;; 같다(==)
		{'~',  4,  5},		// ~		<--		;; 다르다(!=)
		{'&',  3,  3},		// &		-->		;; AND(&&)
		{'|',  2,  2},		// |		-->		;; OR(||)
		{'(',  1,  9},
		{ MinOpr,  0,  0}};	// 알고리즘 편의상

	int i;
	int nSize = sizeof(precedence) / sizeof(precedence[0]);	// 연산자들의 갯수를 계산
	for (i = 0; i < nSize; i++) {			// 모든 연산자들에 대하여
		if (op == precedence[i][0])			// 원하는 연산자를 찾고
			return precedence[i][mode];		// 그 연산자의 ISP 또는 ICP 우선순위를 전달
	}
	return -1;								// 그러한 연산자 없음
}