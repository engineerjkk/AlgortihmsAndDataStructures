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

int IsEmptyStack(int nTop) //스택이 비었으면 -1리턴
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return nTop == -1;
	if (nTop == -1)
		return true;
	return false;
}

int IsFullStack(int nTop)// 스택이 가득 찼으면 리턴.
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return nTop == N - 1; //?? 잘 이해가 안됨.
}

int Push(Item aStack[], int& nTop, Item nItem) //push 하나를 추가한다.
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	// top을 증가하여 삽입
	if (IsFullStack(nTop))//푸시하기전에 스택이 풀인지 확인한다.
		return false;//그럼 에러를 출력하는것!
	aStack[++nTop] = nItem;
	return true;
}

int Pop(Item aStack[], int& nTop, Item& nItem) //pop 하나를 제거하지,
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// 받아내고 top을 감소
	if (IsEmptyStack(nTop))//비어있으면 false를 리턴
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
