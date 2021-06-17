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
	aStack.nTop = -1;								// �ʱ�ȭ
	push(&aStack, MinOpr);							// -���Ѵ�
	sInfix--;
	while (*++sInfix) {
		if (*sInfix >= 'A' && *sInfix <= 'Z')
			putchar(*sInfix);
		else if (*sInfix ==')')
			printStackOpr(&aStack, '('); // '('�� ���ö����� ���ÿ� �ִ� ���� ����϶�.
		else { //while(ISP>=ICP)
			int nICP = priority(*sInfix, ICP);
			int nISP = priority(top(&aStack), ISP);//����� �����ڿ� �ִ� ������ Priority�� �����Ͷ�
			while (nISP >= nICP) {
				//Item anItem;
				//pop(&aStack, anItem)
				putchar(pop(&aStack));
				int nISP = priority(top(&aStack), ISP);
			}
			push(&aStack, *sInfix);
		}
	}
	// ������ �������Ƿ� stack�� �����ڸ� ����Ѵ�.
	printStackOpr(&aStack, MinOpr);//����ǥ ���ö����� �������
	putchar('\n');
	return true;
}

int IsStackEmpty(StackPtr pStack)
{	

	return pStack->nTop==-1;
}

int IsStackFull(StackPtr pStack)
{	// ������ ���� á������ return �Ѵ�.
	return pStack->nTop==STACK_SIZE-1;
}

int push(StackPtr pStack, Item nValue)
{	// ���ÿ� nValue�� push�ϴµ�, true/false�� return �Ѵ�.
	if (IsStackFull(pStack))
		return false;
	pStack->items[++pStack->nTop] = nValue;
	return true;
}

Item pop(StackPtr pStack)
{	// ���ÿ��� pop�Ͽ� return�ϴµ�, ������ ������� EMPTY�� return �Ѵ�.
	return IsStackEmpty(pStack) ? EMPTY : pStack->items[pStack->nTop--];//pop �ϰ� top �ϳ� �����Ѵ�. 
}

Item top(StackPtr pStack)
{	// ������ ����� ���Ҹ� return�ϴµ�, ������ ������� EMPTY�� return �Ѵ�.
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
		{'^', 3, 4},		// {������, ISP, ICP}
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