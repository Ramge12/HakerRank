#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//#include "DLinkedList.h"		//연결 리스트를 가져다 쓴다!

//정점의 이름들을 상수화
enum {A,B,C,D,E,F,G,H,I,J};

struct ALGraph
{
	int numV;			//정점의 수
	int numE;			//간선의 수
	List * adjList;		//간선의 정보
	int * visitInfo;	//탐색이 진행된 정점의 정보
};

//그래프의 초기화
void GraphInit(ALGraph * pg, int nv);	//그래프의 초기화

//그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

//간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

int WhoIsPrecede(int data1, int data2);

int VisitVertex(ALGraph * pg, int visitV);

void BFShowGraphVertex(ALGraph * pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue);

	VisitVertex(pg, visitV);		//시작 정점을 탐색한다.

	while (LFirst(&(pg->adjList[visitV]), &nextV) == true)	//아래의 while문에서는 visitV와 연결된 모든 정점에 방문한다.
	{
		if (VisitVertex(pg, nextV) == true)
			Enqueue(&queue, nextV);		//nextV에 방문해으니 큐에 저장

		while (LNext(&(pg->adjList[visitV]), &nextV) == true)
		{
			if (VisitVertex(pg, nextV) == true)
				Enqueue(&queue, nextV);	//nextV에 방문했으니 큐에 저장
		}
		if (QIsEmpty(&queue) == true)	//큐가 비면 BFS 종료
			break;
		else
			visitV = Dequeue(&queue);	//큐에서 하나 꺼내어 while문 다시 시작
	}
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);	//탐색 정보 초기화
}