#include <stdio.h>//기본 include
#include <stdlib.h> //메모리 allocate
#include <string.h>//스트링 필요

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

int InsertNode(TreePtr& pTree, const char *sData);
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
	const char *sMonth[] =  {"July", "Feb", "Aug", "May", "Oct", "Nov", "Dec", "Mar", "Sept", "Jan", "June", "Apr"};
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

int InsertNode(TreePtr& pTree, const char *sData)
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
	if (pTree) {
		Inorder(pTree->lChild);			//L
		printf(" %s", pTree->sData);	//D
		Inorder(pTree->rChild);			//R
	}
} 
/// <summary>
/// ptree로 가다가 null이면 죽는다.
/// 즉 if pTree일 때에만 프로그램이 돈다 
/// </summary>
/// <param name="pTree"></param>
void Preorder(TreePtr pTree)
{
	if (pTree) {
		printf(" %s", pTree->sData);    //D
		Preorder(pTree->lChild);	        //L
		Preorder(pTree->rChild);			//R
	}
}
/// <summary>
/// Preorder이니까 D가 앞에 온다.
///
/// 
/// </summary>
/// <param name="pTree"></param>
void Postorder(TreePtr pTree)
{
	if (pTree) {
		Postorder(pTree->lChild);	        //L
		Postorder(pTree->rChild);			//R
		printf(" %s", pTree->sData);        //D
	}
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
	Node2Ptr pNew = new Node2;
	if (pNew) {
		pNew->pData = pTree;
		pNew->link = pQueue->link; //pQueue의 링크값을 넣어준다. 이 화살표는 문제가 있다. pQuque->null일때 문제가 있다.
		if (pQueue) {
			pQueue->link = pNew; //pQueue의 링크값은 pNew가 되어야한다.
			pQueue->link = pNew;//pQueue의 링크가 pNew가 되어야한다.  그럼 pQueue가 C를 가리키다가 D를 가리키게 된다.
		}
		else 
			pQueue->link = pNew; //pQueue의 링크값은 pNew가 되어야한다.
		pQueue = pNew;//pQueue는 pNew가 되어야한다.  그럼 pQueue가 C를 가리키다가 D를 가리키게 된다.
		
		}
}

TreePtr DeleteQ(QueuePtr& pQueue)
{	// 첫 노드를 삭제
	TreePtr pTree = NULL;
	if (pQueue) {
		Node2Ptr pDel = pQueue->link;
		pTree = pDel->pData;
		if (pQueue == pDel)
			pQueue = NULL;
		else
			pQueue->link = pDel->link;	
		delete pDel;
	}
	return pTree;
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
	if (pTree) {
		Node2Ptr pQueue = NULL;
		AddQ(pQueue, pTree);
		while (1) {
			if ((pTree = DeleteQ(pQueue)) == NULL)
				break;
			printf(" %s", pTree->sData);
			if(pTree->lChild)
				AddQ(pQueue, pTree->lChild);
			if(pTree->rChild)
				AddQ(pQueue,pTree->rChild);
		}
	}
}
/// <summary>
/// 역시 널이 아닐때까지만
/// </summary>
/// <param name="pTree"></param>
/// <returns></returns>

TreePtr CopyTree(TreePtr pTree)
{
	return NULL;
}

int EqualTree(TreePtr pTree1, TreePtr pTree2)
{
	return true;
}

void SwapTree(TreePtr pTree)
{
}

void FreeTree(TreePtr pTree)
{
}

