#include <stdio.h>

#define M	11
#define N	15
#define StackSize M * N
#pragma warning (disable: 4996)

typedef char Maze[M + 2][N + 2];		// Maze 타입을 정의한다.

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
	Stack aStack;						// 스택은 찾은 길을 출력하기 위하여 여기에서 정의한다
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

	aStack.nTop = -1;							// 스택을 초기화한다.
	if (FindPath(arrMaze, arrMark, &aStack))	// 길을 찾았다.
		PrintPath(arrMaze, arrMark, &aStack);
	else										// 길이 없다.
		printf("No path has been found.\n");
}

int FindPath(Maze maze, Maze mark, StackPtr pStack)	// 미로에서 길을 찾아라.
{
	for (int i = 0; i < M + 2; i++)
		for (int j =0; j < N + 2; j++)
			mark[i][j] = 0;									// 0으로 초기화
	Step aStep;
	aStep.nRow = aStep.nCol = 1;							// 시작 위치
	aStep.nDir = 0;											// 0번 방향부터 찾기 위하여
	DoMark(mark, &aStep);									// 시작 위치를 표시하라.
	Push(pStack, &aStep);
	while (!IsEmptyStack(pStack)) {
		Pop(pStack, &aStep);
		while (IsMoreDirection(&aStep)) {					// 더 찾아갈 길이 있는가?
			Step aNextStep = GetNextPosition(&aStep);		// 다음 위치
			if (IsGoal(&aNextStep))	{						// 목표인가?
				Push(pStack, &aStep);						// 현재 위치를 저장한다.
				Push(pStack, &aNextStep);					// 목표 위치를 저장한다.
				return true;								// 길을 찾았다.
			}
			if (CanGo(maze, &aNextStep) &&					// 길이 있고,
				IsNotMarked(mark, &aNextStep)) {			// 왔던 곳이 아닌가?
				DoMark(mark, &aNextStep);					// 표시하라.
				aStep.nDir++;								// 실패하면 다음에 찾을 방향을 설정한다.
				Push(pStack, &aStep);						// 되돌아 오기 위하여 현재 위치를 저장하라.
				aStep = aNextStep;							// 그리고 새로운 위치로 전진하라.
				aStep.nDir = 0;								// 0번 방향부터 찾기 위하여
			}
			else
				aStep.nDir++;								// 다음 방향을 설정하라.
		}
	}
	return false;
}

void PrintPath(Maze maze, Maze mark, StackPtr pStack)		// 스택에 저장된 길을 출력하라.
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

int IsGoal(StepPtr pStep)									// 목표에 도달하였는가?
{
	return pStep->nRow == M && pStep->nCol == N;
}

int IsNotMarked(Maze mark, StepPtr pStep)					// 이미 왔던 곳이 아닌가?
{
	return mark[pStep->nRow][pStep->nCol] != 1;
}

int CanGo(Maze maze, StepPtr pStep)							// 갈수 있는 길인가?
{
	return maze[pStep->nRow][pStep->nCol] == 0;
}

void DoMark(Maze mark, StepPtr pStep)						// 왔던 곳으로 표시하라.
{
	mark[pStep->nRow][pStep->nCol] = 1;
}

int IsMoreDirection(StepPtr pStep)							// 더 갈 길이 있는가?
{
	return pStep->nDir < 8;
}

Step GetNextPosition(StepPtr pStep)							// 다음 갈 위치를 찾아라.
{
	static Offsets move[8] = {
		{1, 1},					// 남동
		{1, 0},					// 남
		{0, 1},					// 동
		{-1, 1},				// 북동
		{1, -1},				// 남서
		{-1, 0},				// 서
		{0, -1},				// 북
		{-1, -1}};				// 북서
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
