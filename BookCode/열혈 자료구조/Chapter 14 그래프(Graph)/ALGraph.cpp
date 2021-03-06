#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//정점의 이름을 상수화
enum { A, B, C, D, E, G, H, I, J };

struct ALGraph
{
	int numV;	//정점의 수
	int numE;	//간선의 수
	List * adjList;	//간선의 정보
};

//그래프의 초기화
void GraphInit(ALGraph * pg, int nv)
{
	//정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = new List;	//간선정보를 저장할 리스트 생성

	pg->numV = nv;		//정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;		//초기의 간선 수는 0개

	//정점의 수만큼 생성딘 리스트드을 초기화한다.
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	//리스트의 정렬기준을 설정
	}
}

//그래프의 리소스 해제
void GraphDestroy(ALGraph * pg)	//그래프 리소스의 이해
{
	if (pg->adjList != NULL)
		delete(pg->adjList);	//동적으로 할당된 연결 리스트의 소멸
}

//간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV)	//fromV, toV 연결하는 간선 추가
{
	//정점 fromV의 연결 리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);

	//정점 toV의 연결 리스트에 정점 fromV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int vx;
	for (int i = 0; i < pg->numV; i++)
	{
		cout << i + 65 << "와 연결된 정점:";
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			cout << vx + 64;

			while (LNext(&(pg->adjList[i]), &vx))
				cout << vx + 65;
		}
		cout << endl;
	}
}
int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}
