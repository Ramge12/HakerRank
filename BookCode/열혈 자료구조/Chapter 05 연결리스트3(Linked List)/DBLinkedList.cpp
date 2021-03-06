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
	Node* prev;
};

struct DBLinkedList
{
	Node* head;
	Node* cur;
	int numOfData;
};

typedef DBLinkedList List;

void ListInit(List * plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data)
{
	Node * newNode = new Node;
	newNode->data = data;

	//아래 문장에서 plist->head는 NULL이다
	newNode->next = plist->head;		//새 노드의 next를 NULL로 초기화
	if (plist->head != NULL)
		plist->head->prev = newNode;	//두 번쨰 이후의 노드를 추가할 때만 실행

	newNode->prev = NULL;				//새 노드의 prev를 NULL로 초기화
	plist->head = newNode;				//포인터 변수 head가 새 노드 가리키게 함

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head == NULL)
		return false;
	
	plist->cur = plist->head;	//cur이 첫 번째 노드를 가리키게 함
	*pdata = plist->cur->data;	//cur이 가리키는 노드의 데이터 반환
	return true;
}
int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == NULL)
		return false;

	plist->cur = plist->cur->next;	//cur을 오른쪽으로 이동
	*pdata = plist->cur->data;		//cur이 가리키는 노드의 데이터 반환
	return true;
}
int LPrevious(List * plist, Data * pdata)
{
	if (plist->cur->prev == NULL)
		return false;

	plist->cur = plist->cur->prev;	//cur을 왼쪽으로 이동
	*pdata = plist->cur->data;		//cur이 가리키는 노드의 데이터 변환
	return true;
}
int LCount(List * plist)
{
	return plist->numOfData;
}

int main()
{

    return 0;
}

