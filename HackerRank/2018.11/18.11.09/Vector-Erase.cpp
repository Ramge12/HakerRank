
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int firstNum;
	cin >> firstNum;
	vector<int> answer;
	for (int i = 0; i < firstNum; i++)
	{
		int dummy;
		cin >> dummy;
		answer.push_back(dummy);
	}
	int thirdNum;
	cin >> thirdNum;
	answer.erase(answer.begin() + thirdNum-1);
	int startNum, endNum;
	cin >> startNum >> endNum;
	answer.erase(answer.begin() + startNum-1, answer.begin() + endNum-1);
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)cout << answer[i] << " ";
	
	return 0;
}