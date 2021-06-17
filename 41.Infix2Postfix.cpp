#include <stdio.h>

#define STACK_SIZE	40
#define EXPR_SIZE	100
#define ISP			1
#define ICP			2
#define MinOpr		'?'
#define	EMPTY		0x20
#pragma warning (disable: 4996)

/** Create Stack **/
typedef char Item;

typedef struct {
	int  nTop;
	Item items[STACK_SIZE];
}	Stack, *StackPtr;


void main()
{
	while (1) {
		char sInfix[EXPR_SIZE];
		printf("\n  Infix Expr ? ");
		gets_s(sInfix);
		if (*sInfix == NULL)
			return;
		int Infix2Postfix(char *sInfix);
		printf("Postfix Expr : ");
		Infix2Postfix(sInfix);
	}
}

int Infix2Postfix(char *sInfix)
{
	int push(StackPtr pStack, Item op);
	Item pop(StackPtr pStack);
	Item top(StackPtr pStack);
	int priority(char op, int mode);
	int printStackOpr(StackPtr pStack, Item nLastOpr);

	Stack aStack;
	aStack.nTop = -1;								// 초기화
	push(&aStack, MinOpr);							// -무한대
	sInfix--;
	while (*++sInfix) {
		if (*sInfix >= 'A' && *sInfix <= 'Z')
			putchar(*sInfix);
		else if (*sInfix ==')')
			printStackOpr(&aStack, '('); // '('가 나올때까지 스택에 있는 것을 출력하라.
		else { //while(ISP>=ICP)
			int nICP = priority(*sInfix, ICP);
			int nISP = priority(top(&aStack), ISP);//꼭대기 연산자에 있는 스택의 Priority를 가져와라
			while (nISP >= nICP) {
				//Item anItem;
				//pop(&aStack, anItem)
				putchar(pop(&aStack));
				int nISP = priority(top(&aStack), ISP);
			}
			push(&aStack, *sInfix);
		}
	}
	// 수식이 끝났으므로 stack의 연산자를 출력한다.
	printStackOpr(&aStack, MinOpr);//물음표 나올때까지 스택출력
	putchar('\n');
	return true;
}

int IsStackEmpty(StackPtr pStack)
{	

	return pStack->nTop==-1;
}

int IsStackFull(StackPtr pStack)
{	// 스택이 가득 찼는지를 return 한다.
	return pStack->nTop==STACK_SIZE-1;
}

int push(StackPtr pStack, Item nValue)
{	// 스택에 nValue를 push하는데, true/false를 return 한다.
	if (IsStackFull(pStack))
		return false;
	pStack->items[++pStack->nTop] = nValue;
	return true;
}

Item pop(StackPtr pStack)
{	// 스택에서 pop하여 return하는데, 스택이 비었으면 EMPTY을 return 한다.
	return IsStackEmpty(pStack) ? EMPTY : pStack->items[pStack->nTop--];//pop 하고 top 하나 감소한다. 
}

Item top(StackPtr pStack)
{	// 스택의 꼭대기 원소를 return하는데, 스택이 비었으면 EMPTY을 return 한다.
	return IsStackEmpty(pStack)? EMPTY : pStack->items[pStack->nTop];
}

int printStackOpr(StackPtr pStack, Item nLastOpr)
{
	Item nOpr;
	while ((nOpr = pop(pStack)) != nLastOpr) {
		if (nOpr == EMPTY)
			return false;
		putchar(nOpr);
	}
	return true;
}

int priority(char op, int mode)
{
	char precedence[][3] = { 
		{'^', 3, 4},		// {연산자, ISP, ICP}
		{'*', 2, 3},
		{'/', 2, 3},
		{'+', 1, 2},
		{'-', 1, 2},
		{'(', 0, 4},
		{'?', -1, 0}};
	int i;
	int nSize = sizeof(precedence) / sizeof(precedence[0]);
	for (i = 0; i < nSize; i++)
		if (op == precedence[i][0])
			return precedence[i][mode];
	return -1;
}