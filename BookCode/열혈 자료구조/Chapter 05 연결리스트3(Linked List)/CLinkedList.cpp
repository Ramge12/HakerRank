#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

typedef int Data;

struct Node
{
	Data data;
	Node* next;
};

struct CList
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
};

typedef CList List;

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data)			//꼬리에 노드를 추가
{
	Node * newNode = new Node;			//새 노드를 생성
	newNode->data = data;				//새 노드에 데이터 저장

	if (plist->tail == NULL)			//첫 번째 노드라면,
	{
		plist->tail = newNode;			//tail 이 새 노드를 가리키게 한다.
		newNode->next = newNode;		//새 노드 자신을 가리키게 한다/
	}
	else								//두 번쨰 이후 노드라면
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;			//LInsertFront 함수와의 유일한 차이점
	}
	(plist->numOfData)++;
}
void LInsertFront(List * plist, Data data)		//머리에 노드를 추가
{
	Node * newNode = new Node;			//새 노드를 생성
	newNode->data = data;				//새 노드에 데이터 저장

	if (plist->tail == NULL)			//첫 번째 노드라면,
	{
		plist->tail = newNode;			//tail 이 새 노드를 가리키게 한다.
		newNode->next = newNode;		//새 노드 자신을 가리키게 한다/
	}
	else								//두 번째 이후 노드라면
	{
		newNode->next = plist->tail->next;		//새 노드와 4가 저장된 노드 연결
		plist->tail->next = newNode;	//2가 저장된 노드와 새 노드 연결
	}
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->tail == NULL)		//저장된 노드가 없다면
		return false;

	plist->before = plist->tail;	//before가 꼬리를 가리키게 한다.
	plist->cur = plist->tail->next;	//cur이 머리를 가리키게 한다

	*pdata = plist->cur->data;		//cur이 가리키는 노드의 데이터 반환
	return true;
}
int LNext(List* plist, Data * pdata)
{
	if (plist->tail == NULL)			//저장된 노드가 없다면
		return false;
	
	plist->before = plist->cur;			//before가 다음 노드를 가리키게 한다.
	plist->cur = plist->cur->next;		//cur이 다음 노드를 가리키게 한다.

	*pdata = plist->cur->data;			//cur이 가리키는 노드의 데이터 변환
	return true;
}
Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)		//삭제 대상을 tail이 가리킨다면
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List * plist)
{
	return plist->numOfData;
}

int main()
{

    return 0;
}

