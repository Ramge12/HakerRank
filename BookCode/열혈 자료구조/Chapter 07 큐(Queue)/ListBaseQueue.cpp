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

struct LQueue
{
	Node* front;	//앞 부분
	Node* rear;		//뒤 부분
};

typedef LQueue Queue;

void QueueInit(Queue * pq)
{
	pq->front = NULL;	//이후에도 front를 F라 표현한다.
	pq->rear = NULL;	//이후에도 rear를 R이라 표현한다.
}
int QIsEmpty(Queue * pq)
{
	if (pq->front == NULL)		//F에 NULL이 저장되어 있으면,
		return true;			//큐가 텅 빈 것이니 true를 반환한다.
	else
		return false;
}

void Enqueue(Queue * pq, Data data)		//enqueue 연산 담당 함수
{
	Node * newNode = new Node;
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))			//첫 번째 노드의 추가라면,
	{
		pq->front = newNode;	//front가 새 노드를 가리키게 하고
		pq->rear = newNode;		//rear도 새 노드를 가리키게 한다
	}
	else						//두 번째 이후의 노드 추가라면
	{
		pq->rear->next = newNode;	//마지막 노드가 새 ㄴ드를 가리키게 하고
		pq->rear = newNode;		//rear가 새 노드를 가리키게 한다.
	}
}
Data Dequeue(Queue * pq)				//dequeue 연산 담당 함수
{
	Node * delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	delNode = pq->front;		//삭제할 노드의 주소 값 저장
	retData = delNode->data;	//삭제할 노드가 지닌 값 저장
	pq->front = pq->front->next;//삭제할 노드의 다음 노드를 front가 가리킴

	delete(delNode);
	return retData;
}
Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	return pq->front->data;
}

int main()
{

    return 0;
}

