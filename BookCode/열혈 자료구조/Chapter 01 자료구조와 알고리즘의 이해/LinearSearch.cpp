#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int LSearch(int ar[], int len, int target)
{
	for (int i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;			//찾은 대상의 인덱스 값 반환
	}
	return -1;					//찾지 못했음을 의미하는 값 반환
}

int main()
{
	int arr[] = { 3,5,7,9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);

	if (idx == -1)
		cout << "탐색 실패" << endl;
	else
		cout << "타겟 저장 인덱스:" << idx << endl;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);

	if (idx == -1)
		cout << "탐색실패" << endl;
	else
		cout << "타겟 저장 인덱스:" << idx << endl;

    return 0;
}

