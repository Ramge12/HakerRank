// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class HTMLvalue
{
public:
	string valueString;
	string value;
};
class HTMLtag
{
public:
	string name;
	vector<HTMLvalue> valueVector;
	HTMLtag* parents;
};

int main() {

	int numberLine, numberQusetion;
	cin >> numberLine >> numberQusetion;

	vector<HTMLtag> vectorHTML;
	for (int i = 0; i < numberLine + 1; i++)
	{
		string information;
		getline(cin, information);
		HTMLtag curLine;
		HTMLtag parentsHTML;
		string readLine;
		HTMLvalue curHTML;
		for (int j = 0; j < information.size(); j++)
		{
			if (information[j] != ' ' && information[j] != '=' && information[j] != '"' && information[j] != '>' && information[j] != '<' && information[j] != '/')
			{
				readLine += information[j];
			}
			else
			{
				if (curLine.name == "")curLine.name = readLine;
				else
				{
					if (curHTML.valueString == "")curHTML.valueString = readLine;
					else
					{
						if (readLine != "")
						{
							curHTML.value = readLine;
							curLine.valueVector.push_back(curHTML);
							curHTML.valueString = "";
							curHTML.value = "";
						}
					}
				}
				readLine = "";
			}
		}
		if (information != "")
		{
			if (information[1] == '/')	//태그 닫음
			{
				if (curLine.parents != NULL)parentsHTML = *curLine.parents;
			}
			else
			{
				if (parentsHTML.name == "")parentsHTML = curLine;
				curLine.parents = &parentsHTML;
				if (curLine.name != "")vectorHTML.push_back(curLine);
			}
		}
	}
	
	return 0;
}
