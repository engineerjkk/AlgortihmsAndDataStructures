#include <stdio.h>

#define M	11
#define N	15
#define StackSize M * N
#pragma warning (disable: 4996)

typedef char Maze[M + 2][N + 2];		// Maze Ÿ���� �����Ѵ�.

typedef struct  {
	int nRow;
	int nCol;
}	Offsets;

typedef struct {
	int nRow;
	int nCol;
	int nDir;
}	Step, *StepPtr;

typedef struct {
	int nTop;
	Step items[StackSize];
}	Stack, *StackPtr;

void DoMark(Maze mark, StepPtr pStep);
int IsMoreDirection(StepPtr pStep);
Step GetNextPosition(StepPtr pStep);
int IsGoal(StepPtr pStep);
int CanGo(Maze maze, StepPtr pStep);
int IsNotMarked(Maze mark, StepPtr pStep);
int FindPath(Maze aMaze, Maze aMark, StackPtr pStack);
void PrintPath(Maze aMaze, Maze aMark, StackPtr pStack);
int IsEmptyStack(StackPtr pStack);
void Push(StackPtr pStack, StepPtr pStep);
void Pop(StackPtr pStack, StepPtr pStep);

void main()
{
	Stack aStack;						// ������ ã�� ���� ����ϱ� ���Ͽ� ���⿡�� �����Ѵ�
	Maze arrMark;
	Maze arrMaze = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	aStack.nTop = -1;							// ������ �ʱ�ȭ�Ѵ�.
	if (FindPath(arrMaze, arrMark, &aStack))	// ���� ã�Ҵ�.
		PrintPath(arrMaze, arrMark, &aStack);
	else										// ���� ����.
		printf("No path has been found.\n");
}

int FindPath(Maze maze, Maze mark, StackPtr pStack)	// �̷ο��� ���� ã�ƶ�.
{
	for (int i = 0; i < M + 2; i++)
		for (int j =0; j < N + 2; j++)
			mark[i][j] = 0;									// 0���� �ʱ�ȭ
	Step aStep;
	aStep.nRow = aStep.nCol = 1;							// ���� ��ġ
	aStep.nDir = 0;											// 0�� ������� ã�� ���Ͽ�
	DoMark(mark, &aStep);									// ���� ��ġ�� ǥ���϶�.
	Push(pStack, &aStep);
	while (!IsEmptyStack(pStack)) {
		Pop(pStack, &aStep);
		while (IsMoreDirection(&aStep)) {					// �� ã�ư� ���� �ִ°�?
			Step aNextStep = GetNextPosition(&aStep);		// ���� ��ġ
			if (IsGoal(&aNextStep))	{						// ��ǥ�ΰ�?
				Push(pStack, &aStep);						// ���� ��ġ�� �����Ѵ�.
				Push(pStack, &aNextStep);					// ��ǥ ��ġ�� �����Ѵ�.
				return true;								// ���� ã�Ҵ�.
			}
			if (CanGo(maze, &aNextStep) &&					// ���� �ְ�,
				IsNotMarked(mark, &aNextStep)) {			// �Դ� ���� �ƴѰ�?
				DoMark(mark, &aNextStep);					// ǥ���϶�.
				aStep.nDir++;								// �����ϸ� ������ ã�� ������ �����Ѵ�.
				Push(pStack, &aStep);						// �ǵ��� ���� ���Ͽ� ���� ��ġ�� �����϶�.
				aStep = aNextStep;							// �׸��� ���ο� ��ġ�� �����϶�.
				aStep.nDir = 0;								// 0�� ������� ã�� ���Ͽ�
			}
			else
				aStep.nDir++;								// ���� ������ �����϶�.
		}
	}
	return false;
}

void PrintPath(Maze maze, Maze mark, StackPtr pStack)		// ���ÿ� ����� ���� ����϶�.
{
	Maze arMaze;
	for (int i = 0; i < M + 2; i++)
		for (int j = 0; j < N + 2; j++)			// 0->'0', 1->'1', mark->'*'
			arMaze[i][j] = mark[i][j] ? '*' : maze[i][j] + 0x30;
	Step aStep;
	while (!IsEmptyStack(pStack)) {
		Pop(pStack, &aStep);
		arMaze[aStep.nRow][aStep.nCol] = 'x';	// path->'x'
	}
	for (int i = 0; i < M + 2; i++) {
		for (int j = 0; j < N + 2; j++)
			putchar(arMaze[i][j]);
		putchar('\n');
	}
}

int IsGoal(StepPtr pStep)									// ��ǥ�� �����Ͽ��°�?
{
	return pStep->nRow == M && pStep->nCol == N;
}

int IsNotMarked(Maze mark, StepPtr pStep)					// �̹� �Դ� ���� �ƴѰ�?
{
	return mark[pStep->nRow][pStep->nCol] != 1;
}

int CanGo(Maze maze, StepPtr pStep)							// ���� �ִ� ���ΰ�?
{
	return maze[pStep->nRow][pStep->nCol] == 0;
}

void DoMark(Maze mark, StepPtr pStep)						// �Դ� ������ ǥ���϶�.
{
	mark[pStep->nRow][pStep->nCol] = 1;
}

int IsMoreDirection(StepPtr pStep)							// �� �� ���� �ִ°�?
{
	return pStep->nDir < 8;
}

Step GetNextPosition(StepPtr pStep)							// ���� �� ��ġ�� ã�ƶ�.
{
	static Offsets move[8] = {
		{1, 1},					// ����
		{1, 0},					// ��
		{0, 1},					// ��
		{-1, 1},				// �ϵ�
		{1, -1},				// ����
		{-1, 0},				// ��
		{0, -1},				// ��
		{-1, -1}};				// �ϼ�
	Step aNextStep = *pStep;
	aNextStep.nRow += move[pStep->nDir].nRow;
	aNextStep.nCol += move[pStep->nDir].nCol;
	return aNextStep;
}

/*
 * Stack operations
 */

int IsEmptyStack(StackPtr pStack)
{
	return pStack->nTop < 0;
}

void Push(StackPtr pStack, StepPtr pStep)
{
	pStack->items[++pStack->nTop]= *pStep;
}

void Pop(StackPtr pStack, StepPtr pStep)
{
	*pStep = pStack->items[pStack->nTop--];
}
