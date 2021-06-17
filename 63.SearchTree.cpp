#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable: 4996)

typedef struct tree {
	char sName[9];			// 이름
	int  nNo;
	char sPosition[3];		// 포지션
	char sBirthday[11];		// 생년월일 2002.06.04
	int  nHeight;			// 키
	int  nWeight;			// 몸무게
	char sClub[30];
	struct tree *lChild;
	struct tree *rChild;
}	Data, *DataPtr, Tree, *TreePtr, Node, *NodePtr;

void main()
{
	void MakeSearchTree(TreePtr& pTree1, TreePtr& pTree2);//바이너리 탐색트리를 만들고
	TreePtr SearchTree(TreePtr pTree, char *sName);//서치트리를한다.ㅈ
	TreePtr pTree1 = NULL, pTree2 = NULL;//pTree의 초기화
	MakeSearchTree(pTree1, pTree2);
	TreePtr pTree = pTree1;
	while (1) {
		void SwapTree(TreePtr pTree);
		int  EqualTree(TreePtr pTree1, TreePtr pTree2);
		void Inorder(TreePtr pTree);
		char sCmnd[20];
		printf("[sqnx*e] ? ");
		gets_s(sCmnd);							// 명령을 입력한다.
		TreePtr pNode;
		switch (*sCmnd | 0x20) {
		case 'e':								// 아무런 명령이 없으면
			return;
		case 's':								// 트리의 왼쪽과 오른쪽 자식을 바꾼다
			SwapTree(pTree);
			printf("Swap: Tree%d\n", (pTree == pTree1) ? 1 : 2);
			break;
		 case 'q':								// 두 트리가 같은지 비교한다.
			printf("%s\n", EqualTree(pTree1, pTree2) ? "good" : "bad");
			break;
		 case 'n':								// inorder traverse하면서 선수 이름을 출력한다.
			Inorder(pTree);
			putchar('\n');
			break;
		 case 'x':								// 탐색 대상을 pTree1과 pTree2를 바꾼다.
			if (pTree == pTree1) {
				pTree = pTree2;
				printf("pTree2 사용\n");
			}
			else {
				pTree = pTree1;
				printf("pTree1 사용\n");
			}
			break;
		 default:								// 검색할 선수의 이름으로 간주
			pNode = SearchTree(pTree, sCmnd);	// 검색을 한다.
			if (pNode) {
				printf("    이름: %s\n", pNode->sName);
				printf("      No: %d\n", pNode->nNo);
				printf("  포지션: %s\n", pNode->sPosition);
				printf("생년월일: %s\n", pNode->sBirthday);
				printf("      키: %d\n", pNode->nHeight);
				printf("  몸무게: %d\n", pNode->nWeight);
				printf("    소속: %s\n", pNode->sClub);
			}
			else
				printf("  No name......\n");
		}
		putchar('\n');
	}
}

void MakeSearchTree(TreePtr& pTree1, TreePtr& pTree2)
{
#include "nationalTeam.h"

	TreePtr InsertNode1(TreePtr pTree, DataPtr pNode);
	void InsertNode2(TreePtr& pTree, DataPtr pNode);
	for (int i = 0; i < sizeof(nationalTeam) / sizeof(nationalTeam[0]); i++) {
		pTree1 = InsertNode1(pTree1, nationalTeam + i);
		InsertNode2(pTree2, nationalTeam + i);
	}
}

TreePtr InsertNode1(TreePtr pTree, DataPtr pNode)
{
	// 트리에 하나의 노드를 삽입한다.
	// 이미 존재하면 아무런 일을 하지 않는다.
	if (pTree == NULL) {
		pTree = new Node;
		if (pTree) {
			*pTree = *pNode;
			pTree->lChild = pTree->rChild = NULL;
		}
		return pTree;
	}
	
		int nCmp = strcmp(pNode->sName,pTree->sName);//루트의 데이터와 현재의 데이터 비교
		if (nCmp < 0)
			pTree->lChild = InsertNode1(pTree->lChild, pNode);
		else if (nCmp > 0)
			pTree->lChild = InsertNode1(pTree->rChild, pNode);

		return pTree;
}

void InsertNode2(TreePtr& pTree, DataPtr pNode)
{
	// 트리에 하나의 노드를 삽입한다.
	// 이미 존재하면 아무런 일을 하지 않는다.
	if (pTree == NULL) {
		pTree = new Node;
		if (pTree) {
			*pTree = *pNode;
			pTree->lChild = pTree->rChild = NULL;
		}
		return;
	}
	int nCmp = strcmp(pNode->sName, pTree->sName);//루트의 데이터와 현재의 데이터 비교
	if (nCmp < 0)
		InsertNode1(pTree->lChild, pNode);
	else if (nCmp > 0)
		InsertNode1(pTree->rChild, pNode);

}

TreePtr SearchTree(TreePtr pTree, char *sName)
{
	// 탐색트리에서 sName을 가진 선수를 찾아 그 노드를 return한다.
	// 그 선수가 없으면 NULL을 return한다.
	if (pTree) {
		int nCmp = strcmp(sName,pTree->sName);
		if (nCmp < 0)
			pTree = SearchTree(pTree->lChild, sName);
		else if (nCmp>0)
			pTree = SearchTree(pTree->lChild, sName);
	}
	return pTree;//왼쪽에서 찾아서 리턴 or 오른쪽에서 찾아서 리턴
} 

void Inorder(TreePtr pTree)
{
	// 이름만 출력한다
	if (pTree) {
		Inorder(pTree->lChild);
		printf("%s ", pTree->sName);
		Inorder(pTree->rChild);
	}
}

void SwapTree(TreePtr pTree)
{
	// 이진트리의 모든 노드의 오른쪽과 왼쪽 자식을 서로 바꾼다.
	// 즉 거울 비친 모습의 이진트리로 변환한다.
	// 탐색트리를 사용하므로 오른쪽은 작게되고 왼쪽은 크게 된다.
}

int EqualTree(TreePtr pTree1, TreePtr pTree2)
{
	// 두 트리를 같은지 비교하여 true/false를 return한다.
	// 두 노드는 sName, nNo 두 필드만 비교하여 판단한다.
	return true;
}
