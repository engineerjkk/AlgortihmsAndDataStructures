#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y)	x = (TreePtr)((unsigned)x ^ (unsigned)y);	\
					y = (TreePtr)((unsigned)x ^ (unsigned)y);	\
					x = (TreePtr)((unsigned)x ^ (unsigned)y);

#pragma warning (disable: 4996)

typedef struct node1 {			// 트리에서 노드
	char sData[5];
	struct node1 *lChild;
	struct node1 *rChild;
}	Node1, *Node1Ptr, Tree, *TreePtr;

typedef struct node2 {			// 스택, 큐에서 노드
	TreePtr pData;
	struct node2 *link;
}	Node2, *Node2Ptr, Stack, *StackPtr, Queue, *QueuePtr;

int InsertNode(TreePtr& pTree, char *sData);
void Inorder(TreePtr pTree);
void Preorder(TreePtr pTree);
void Postorder(TreePtr pTree);
void IterativeInorder(TreePtr pTree);
void IterativePreorder(TreePtr pTree);
void LevelOrder(TreePtr pTree);
TreePtr CopyTree(TreePtr pTree);
int EqualTree(TreePtr pTree, TreePtr pTree1);
void SwapTree(TreePtr pTree);
void FreeTree(TreePtr pTree);

void main()
{
	char *sMonth[] =  {"July", "Feb", "Aug", "May", "Oct", "Nov", "Dec", "Mar", "Sept", "Jan", "June", "Apr"};
	TreePtr pTree0 = NULL;
	for (int i = 0; i < sizeof(sMonth) / sizeof(sMonth[0]); i++)
		InsertNode(pTree0, sMonth[i]);
	char sCmnd[10];
	TreePtr pTree1 = NULL;
	while (1) {
		printf("\n[i nrotulcqsx e] ? ");
		gets_s(sCmnd);
		switch (*sCmnd | 0x20) {
		case 'i':
			printf("Data ? ");
			gets_s(sCmnd);
			if (InsertNode(pTree0, sCmnd))
				printf("Inserted ...\n");
			break;
		case 'n':
			printf("     Inorder Trav:");
			Inorder(pTree0);
			printf("\n");
			break;
		case 'r':
			printf("    Preorder Trav:");
			Preorder(pTree0);
			printf("\n");
			break;
		case 'o':
			printf("   Postorder Trav:");
			Postorder(pTree0);
			printf("\n");
			break;
		case 't':
			printf("Iter inorder Trav:");
			IterativeInorder(pTree0);
			printf("\n");
			break;
		case 'u':
			printf("Ite Preorder Trav:");
			IterativePreorder(pTree0);
			printf("\n");
			break;
		case 'l':
			printf(" Level order Trav:");
			LevelOrder(pTree0);
			printf("\n");
			break;
		case 'c':
			if (pTree1)
				FreeTree(pTree1);
			pTree1 = CopyTree(pTree0);
			printf("Copyed ...\n");
			break;
		case 'q':
			if (EqualTree(pTree0, pTree1))
				printf("Yes\n");
			else
				printf("No\n");
			break;
		case 's':
			SwapTree(pTree0);
			printf("Swapped ...\n");
			break;
		case 'x':
			printf("Exchanged ...\n");
			pTree0 = (TreePtr)((unsigned)pTree0 ^ (unsigned)pTree1);
			pTree1 = (TreePtr)((unsigned)pTree0 ^ (unsigned)pTree1);
			pTree0 = (TreePtr)((unsigned)pTree0 ^ (unsigned)pTree1);
			break;
		case 'e':
			if (pTree0)
				FreeTree(pTree0);
			if (pTree1)
				FreeTree(pTree1);
			printf("Freed ...\n");
			return;
		default:
			printf("Invalid command ....\n");
		}
	}
}

int InsertNode(TreePtr& pTree, char *sData)
{	// return true for success
	if (pTree == NULL) {
		pTree = (TreePtr)malloc(sizeof(Node1));
		if (pTree) {
			pTree->lChild = pTree->rChild = NULL;
			strcpy(pTree->sData, sData);
		}
		return pTree != NULL;
	}
	int nCond = strcmp(sData, pTree->sData);
	if (nCond < 0)
		return InsertNode(pTree->lChild, sData);
	if (nCond > 0)
		return InsertNode(pTree->rChild, sData);
	return false;
}

void Inorder(TreePtr pTree)
{
} 

void Preorder(TreePtr pTree)
{
}

void Postorder(TreePtr pTree)
{
}

void Push(StackPtr& pStack, TreePtr pTree)
{	// 첫 노드로 삽입
}

TreePtr Pop(StackPtr& pStack)
{	// 첫 노드를 삭제
	return NULL;
}

// 큐를 마지막 노드를 가리키는 원형 연결 리스트로 표현
void AddQ(QueuePtr& pQueue, TreePtr pTree)
{	// 마지막 노드로 삽입
}

TreePtr DeleteQ(QueuePtr& pQueue)
{	// 첫 노드를 삭제
	return NULL;
}

void IterativeInorder(TreePtr pTree)
{
	/***
	pStack을 초기화 한다
	while (1) {
		while (pTree) {
			pStack에 pTree를 push한다
			pTree의 lChild를 따라간다
		}
		pTree에 pStack을 pop한다
		if (pTree == NULL)
			return;
		pTree->sData를 출력한다
		pTree의 rChild를 따라간다
	}
	***/
}

void IterativePreorder(TreePtr pTree)
{
	/***
	pStack을 초기화 한다
	while (1) {
		while (pTree) {
			pStack에 pTree를 push한다
			pTree->sData를 출력한다
			pTree의 lChild를 따라간다
		}
		pTree에 pStack을 pop한다
		if (pTree == NULL)
			return;
		pTree의 rChild를 따라간다
	}
	***/
}

void LevelOrder(TreePtr pTree)
{
}

TreePtr CopyTree(TreePtr pTree)
{
	TreePtr pRoot = NULL;
	if (pTree) {//pTree가 NULL이면 그대로 NULL인 pRoot를 리턴
		//할당을 받는게 노드1
	    pRoot = new Node1;
		if (pRoot) {
			strcpy(pRoot->sData, pTree->sData);
			pRoot->lChild = CopyTree(pTree->lChild);
			pRoot->rChild = CopyTree(pTree->rChild);
		}
	}
	return pRoot;
}

int EqualTree(TreePtr pTree1, TreePtr pTree2)
{	
	if (pTree1 == NULL && pTree2 == NULL)//동시에 끝나면 true
		return true;
	if (pTree1 == NULL || pTree2 == NULL)//둘중하나만 끝나면 False
		return false;
	return strcmp(pTree1->sData,pTree2->sData)==0&&
		EqualTree(pTree1->lChild,pTree2->lChild)&&
		EqualTree(pTree1->rChild,pTree2->rChild);
}

void SwapTree(TreePtr pTree)//거울 처럼 자식 노드를 바꿔라
{	
	if (pTree) {
		TreePtr pTemp = pTree->lChild;
		pTree->lChild = pTree->rChild;
		pTree->rChild = pTemp;
		SwapTree(pTree->rChild);
	}
}

void FreeTree(TreePtr pTree)
{
	if (pTree) {
		FreeTree(pTree->lChild); //각각의 트리를 Free시킨다.
		FreeTree(pTree->rChild);
		delete pTree;

		}
	}


