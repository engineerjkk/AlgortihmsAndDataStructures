#include <stdio.h>

#define N 10
#pragma warning (disable: 4996)

typedef int Item;

void main()
{
	int  IsEmptyStack(int nTop);
	int  IsFullStack(int nTop);
	int  Push(Item aStack[], int& nTop, Item nItem);
	int  Pop(Item aStack[], int& nTop, Item& nItem);
	void PrintStack(Item aStack[], int nTop);
	int  Error(const char *sMsg);

	/** Create Stack **/
	Item aStack[N];
	int nTop;

	nTop = -1;
	while (1) {
		Item value;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		if (value == -1) {
			if (Pop(aStack, nTop, value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (Push(aStack, nTop, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintStack(aStack, nTop);
	}
}

int IsEmptyStack(int nTop) //������ ������� -1����
{	// ������ ��������� ���� T/F�� ��ȯ�Ѵ�.
	return nTop == -1;
	if (nTop == -1)
		return true;
	return false;
}

int IsFullStack(int nTop)// ������ ���� á���� ����.
{	// ������ ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return nTop == N - 1; //?? �� ���ذ� �ȵ�.
}

int Push(Item aStack[], int& nTop, Item nItem) //push �ϳ��� �߰��Ѵ�.
{	// ���ÿ� nItem�� push�ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// top�� �����Ͽ� ����
	if (IsFullStack(nTop))//Ǫ���ϱ����� ������ Ǯ���� Ȯ���Ѵ�.
		return false;//�׷� ������ ����ϴ°�!
	aStack[++nTop] = nItem;
	return true;
}

int Pop(Item aStack[], int& nTop, Item& nItem) //pop �ϳ��� ��������,
{	// ���ÿ��� pop�Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// �޾Ƴ��� top�� ����
	if (IsEmptyStack(nTop))//��������� false�� ����
		return false;
	nItem = aStack[nTop--];
	return true;
}

void PrintStack(Item aStack[], int nTop)
{
	printf("|    |\n");
	for (int i = nTop; i >= 0; i--)
		printf("|%3d |\n", aStack[i]);
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
