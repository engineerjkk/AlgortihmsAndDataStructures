#include <stdio.h>
#include <stdlib.h>

#define N 10
#pragma warning(disable: 4996)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr, *StackPtr;

void main()
{
	int  IsEmptyStack(StackPtr pStack);
	// int  IsFullStack(StackPtr pStack);
	int  Push(StackPtr& pStack, Item nItem);
	int  Pop(StackPtr& pStack, Item& nItem);
	void PrintStack(StackPtr pStack);
	int  Error(const char *sMsg);

	/** Create Stack **/
	StackPtr pStack = NULL;
	while (1) {
		Item value;
		printf("-1:Exit 0:Pop, *:Push ? ");
		scanf("%d", &value);
		if (value < 0)
			break;
		else if (value == 0) {
			if (Pop(pStack, value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (Push(pStack, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintStack(pStack);
	}
}

int IsEmptyStack(StackPtr pStack)
{
	return pStack == NULL;
}

int Push(StackPtr& pStack, Item nItem)
{
	NodePtr pNode = (NodePtr)malloc(sizeof(Node));
	if (pNode == NULL)
		return false;
	pNode->nData = nItem;
	pNode->link = pStack;
	pStack = pNode;
	return true;
}

int Pop(StackPtr& pStack, Item& nItem)
{
	if (IsEmptyStack(pStack))
		return false;
	NodePtr pNode = pStack;
	pStack = pStack->link;
	nItem = pNode->nData;
	free(pNode);
	return true;
}

void PrintStack(StackPtr pNode)
{
	printf("|    |\n");
	while (pNode) {
		printf("|%3d |\n", pNode->nData);
		pNode = pNode->link;
	}
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
