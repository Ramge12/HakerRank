// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <deque> 
#include <algorithm>
#include <vector>

using namespace std;

void printKMax(int arr[], int n, int k) {
	deque<int> kDeque;
	for (int i = 0; i < n; i++)kDeque.push_back(arr[i]);

	int maxNum=0;
	while (kDeque.size()>=k)
	{
		vector<int> answer;
		if (maxNum == 0)
		{
			for (int i = 0; i < k; i++)answer.push_back(kDeque[i]);
			sort(answer.begin(), answer.end());
			maxNum = answer[k - 1];
		}
		else
		{
			if (maxNum < kDeque[k - 1])
			{
				maxNum = kDeque[k - 1];
			}
		}
		cout << maxNum <<" ";
		if (maxNum == kDeque.front())maxNum = 0;
		kDeque.pop_front();
	}
	cout << endl;
}

int main() {

	int t;
	cin >> t;
	while (t>0) {
		int n, k;
		cin >> n >> k;
		int i;
		int *arr = new int[n];
		for (i = 0; i<n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}