#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef int PriorityComp(HData d1, HData h2);	//두 개의 데이터를 대상으로 우선순위의 높고 낮음을 판단

struct Heap
{
	PriorityComp * comp;	//두 개의 데이터를 대상으로 우선순위의 높고 낮음을 판단
	int numOfData;
	HData heapArr[HEAP_LEN];
};

void HeapInit(Heap * ph , PriorityComp pc)	
{
	ph->numOfData = 0;
	ph->comp = pc;		//우선순위 비교에 사용되는 함수의 등록
}
int HIsEmpty(Heap * ph)		
{
	if (ph->numOfData == 0)
		return true;
	else
		return false;
}
int GetParentIDX(int idx)	
{
	return idx / 2;			
}
int GetLChildIDX(int idx)	
{
	return idx * 2;			
}
int GetRChildIDX(int idx)	
{
	return GetLChildIDX(idx) + 1;	
}

int GetHipriChildIDX(Heap * ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)		
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else		
	{
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)],ph->heapArr[GetRChildIDX(idx)])<0)	//
			return GetRChildIDX(idx);	
		else
			return GetLChildIDX(idx);	
	}
}

void HInsert(Heap * ph, HData data)	
{
	int idx = ph->numOfData + 1;		

	while (idx != 1)
	{
		if(ph->comp(data,ph->heapArr[GetParentIDX(idx)])>0)		//
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];

			idx = GetParentIDX(idx);
		}
		else		
			break;
	}
	ph->heapArr[idx] = data;	//	
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)	
{
	HData retData = ph->heapArr[1];			//
	HData lastElem = ph->heapArr[ph->numOfData];//

	int parentIdx = 1;	
	int childIdx;

	while (childIdx = GetHipriChildIDX(ph, parentIdx))
	{
		if (ph->comp(lastElem , ph->heapArr[childIdx])>=0)	//
			break;											
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;								
	}

	ph->heapArr[parentIdx] = lastElem;			
	ph->numOfData -= 1;
	return retData;
}

int DataPriorityComp(char ch1, char ch2)	//우선순위 비교함수
{
	return ch2 - ch1;
}



int main()
{

    return 0;
}

