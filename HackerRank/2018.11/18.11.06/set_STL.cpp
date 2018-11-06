// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	set<int> setNum;
	int inputNum;
	cin >> inputNum;
	for (int i = 0; i < inputNum; i++)
	{
		int firstNum, secondNum;
		cin >> firstNum >> secondNum;
		switch (firstNum)
		{
		case 1:
			setNum.insert(secondNum);
			break;
		case 2:
			if (setNum.find(secondNum) != setNum.end())
			{
				setNum.erase(setNum.find(secondNum));
			}
			break;
		case 3:
			if (setNum.find(secondNum) != setNum.end())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			break;
		}
	}
	
	
	return 0;
}



