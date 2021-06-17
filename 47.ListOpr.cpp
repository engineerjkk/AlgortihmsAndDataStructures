#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

typedef struct node {
	int nData;
	struct node *link;
}	Node, *NodePtr;

void main()
{
	NodePtr Add(NodePtr pFirst, int nData);
	NodePtr Insert(NodePtr pFirst, int nData, NodePtr pPrev);
	NodePtr Delete(NodePtr pFirst, int nData);
	NodePtr Find(NodePtr pFirst, int nData);
	void PrintList(NodePtr pFirst);
	NodePtr pFirst = NULL;
	NodePtr pPrev = NULL;
	while (1) {
		printf("[aidfe] ? ");
		char sCmnd[10];
		gets_s(sCmnd);
		if (*sCmnd == 'e')
			return;
		printf("Data ? ");
		char sData[10];
		gets_s(sData);
		int nData = atoi(sData);
		switch (*sCmnd) {
		case 'a':
			pFirst = Add(pFirst, nData);
			break;
		case 'f':
			pPrev = Find(pFirst, nData);  
			printf("%s\n", (pPrev) ? "Good" : "Bad");
			break;
		case 'i':
			pFirst = Insert(pFirst, nData, pPrev);
			break;
		case 'd':
			pFirst = Delete(pFirst, nData);
		}
		PrintList(pFirst);
	}
}

NodePtr Add(NodePtr pFirst, int nData)
{
	// pFirst가 가르키는 Linked List의 제일 앞에 nData를 가지는 노드를 삽입한다.
	//  pFirst가 가르키는 Linked List는 노드가 하나도 없을 수도 있다.
	//NodePtr pNew = (NodePtr)malloc(sizeof(Node));
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nData;
		pNew->link = pFirst;
		pFirst = pNew;
	}
	else
		printf("malloc fails");
	return pFirst;
}

NodePtr Find(NodePtr pFirst, int nData)
{
	// 노드의 데이타 값이 nData 값을 가지는 첫번째 노드를 찾아서 그 노드를 return한다.
	// 만약에 그러한 노드가 없으면 NULL을 return한다.
	NodePtr pNode = pFirst;
	while (pNode) {
		if (pNode->nData == nData)
			break;
		pNode = pNode->link;
	}
	return pNode;
}

NodePtr Insert(NodePtr pFirst, int nData, NodePtr pPrev)
{
	// pFirst가 가르키는 Linked List에서 pPrev 노드 뒤에 nData를 가지는 노드를 삽입한다.
	// 만약 pPrev가 NULL이면 제일 앞에 삽입된다.
	// Insert 명령은 Find 명령을 수행하여 pPrev에 적당한 노드로 설정한 후에 실행된다고 가정한다.
	NodePtr pNew = new Node; //메모리할당
	if (pNew) {//NULL이아니면,
		pNew->nData = nData;
		pNew->link = pPrev->link; //이전 노드의 링크를 현재 노드 링크에 복사 3번, pPrev가 NULL이면 죽는다. 이점을 명심하자 중요
		pPrev->link = pNew; //pPrev의 link가 pNew를 가리킨다. pNew자체 노드를 가리키니 곧 데이터를 가리키는 것.
	}
	else { //중간에 넣는게 아닌 첫번째에서 넣을때
		pNew->link = pFirst; //pFirst가 가리키던걸 pNew의 링크가 가리킨다.
		pFirst = pNew;//pFirst가 pNew를 가리킨다.
		//반드시 이 두개 순서를 지켜야한다.  
		
	}
	return pFirst;
}

NodePtr Delete(NodePtr pFirst, int nData)
{
	// 노드의 데이타 값이 nData 값을 가지는 첫번째 노드를 찾아서 그 노드를 삭제한다.
	// 노드를 삭제하기 위하여 이전 노드를 알아야 하는데 Find 함수의 알고리즘에서
	// 별도의 변수 **pTrail**를 만들어 바로 뒤에 따라 오게하고 
	// 현재의 노드가 찾는 노드이면 pTrail은 이전 노드가 된다.
	NodePtr pPrev = NULL, pDel = pFirst;
	while (pDel) { //pNode가 Null일때까지
		if (pDel->nData == nData)
			break;
		pPrev = pDel; // 이렇게하면 pTrail이 졸졸졸 따라온다.
		pDel = pDel->link;//pNode는 다음칸으로
	}
	if (pDel) {//만약 삭제할게 있다면!!
		//첫번째 노드를 삭제하는거였으면 pDel이 NULL이다.(pDel->nDate==nData 시에 break로 빠져나오므로 pPrev는 NULL이기때문)
		if (pPrev)//중간에 있는 pdel을 삭제하는경우
			pPrev->link = pDel->link;//pPrev의 링크가 pDel의 링크를 카리킨다.
		else//첫번째있는 노드를 삭제하는 경우, 즉 pPrev가 없는경우이다.
			pFirst = pDel->link;
		delete pDel;
	}
	/// <summary>
	/// pPrev->link=pDel->link;
	/// delete pDel;
	/// </summary>
	/// <param name="pFirst"></param>
	/// <param name="nData"></param>
	/// <returns></returns>
	return pFirst;
}

void PrintList(NodePtr pNode)
{
	while (pNode) {//pNode가 NULL일때까지 실행한다.
		printf("%d ", pNode->nData);
		pNode = pNode->link;//pNode가 link를 가리킨다.
	}
	printf("\n\n");
}
