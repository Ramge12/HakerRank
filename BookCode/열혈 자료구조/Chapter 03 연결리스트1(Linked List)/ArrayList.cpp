#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define LIST_LEN 100
typedef int LData;		//LData에 대한 typedef 선언

struct ArrayList		//배열기반 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];		//리스트의 저장소인 배열
	int numOfData;				//저장된 데이터의 수
	int curPosition;			//데이터 참조위치를 기록
};

typedef ArrayList List;

void ListInit(List* plist)				//초기화
{
	(plist->numOfData) = 0;				//리스트에 저장된 데이터의 수는 0
	(plist->curPosition) = -1;			//현재 아무 위치도 가리키지 않음
}
void LInsert(List* plist, LData data)	//데이터 저장
{
	if (plist->numOfData > LIST_LEN)	//저장공간이 꽉 차서 저장할 공간이 없다면
	{
		puts("저장이 불가능합니다.");
		return;
	}
	plist->arr[plist->numOfData] = data;	//데이터 저장
	(plist->numOfData)++;				//저장된 데이터의 수 증가
}

int LFirst(List* plist, LData* pdata)	//첫 데이터 참조
{
	if (plist->numOfData == 0)			//저장된 데이터가 하나도 없다면
		return false;

	(plist->curPosition) = 0;			//참조 위치 초기화! 첫 번째 데이터의 참조를 의미
	*pdata = plist->arr[0];				//pdata가 가리키는 공간에 데이터 저장
	return true;
}

int LNext(List* plist, LData* pdata)	//두 번째 이후 데이터 참조
{
	if (plist->curPosition >= (plist->numOfData) - 1)	//더 이상 참조할 데이터가 없다면
		return false;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return true;
}

LData LRemove(List* plist)				//참조한 데이터 삭제
{
	int rpos = plist->curPosition;		//삭제할 데이터의 인덱스 값 참조
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];		//삭제할 데이터를 임시로 저장
	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;				//데이터의 수 감소
	(plist->curPosition)--;				//참조위치를 하나 되돌린다
	return rdata;						//삭제된 데이터의 반환
}

int LCount(List* plist)				//저장된 데이터의 수 반환
{
	return plist->numOfData;
}

int main()
{

    return 0;
}

