#include <stdio.h>

#define N 10
#pragma warning (disable: 4996)

typedef int Item;
typedef struct stack {
	Item items[N];
	int  nTop;
}	Stack, *StackPtr;

void main()
{
	int  IsEmptyStack(StackPtr pStack);
	int  IsFullStack(StackPtr pStack);
	int  Push(StackPtr pStack, Item nItem);
	int  Pop(StackPtr pStack, Item& nItem);
	void PrintStack(StackPtr pStack);
	int  Error(const char *sMsg);

	/** Create Stack **/
	Stack aStack;

	aStack.nTop = -1;
	while (1) {
		Item value;
		printf("-2:Exit -1:Pop, 0~:Push ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		if (value == -1) {
			if (Pop(&aStack, value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (Push(&aStack, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintStack(&aStack);
	}
}

int IsEmptyStack(StackPtr pStack)
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return pStack->nTop == -1;
	//(*pStack).nTop==-1; 이렇게 쓰면 꼴 사납다.
}

int IsFullStack(StackPtr pStack)
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return pStack->nTop == N - 1;
}

int Push(StackPtr pStack, Item nItem)
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	// top을 증가하여 삽입
	if (IsFullStack(pStack))
		return false;
	pStack->items[++pStack->nTop] = nItem;

	/// <summary>
	/// int nTop=pStack->nTop;
	/// pStack->items[++nTop]=nItem;
	/// </summary>
	/// <param name="pStack"></param>
	/// <param name="nItem"></param>
	/// <returns></returns>
	return true;
}

int Pop(StackPtr pStack, Item& nItem)
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다
	// 받아내고 top을 감소
	if (IsEmptyStack(pStack))
		return false;
	nItem = pStack->items[pStack->nTop--];
	return true;
}

void PrintStack(StackPtr pStack)
{
	printf("|    |\n");
	for (int i = pStack->nTop; i >= 0; i--)
		printf("|%3d |\n", pStack->items[i]);
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
