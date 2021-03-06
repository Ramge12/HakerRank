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
	string parents;
	string rootValue;
};

string FindHTMLvalue(vector<HTMLvalue> valueVector, string findName)
{
	for (int i = 0; i < valueVector.size(); i++)
	{
		if (findName == valueVector[i].valueString)return valueVector[i].value;
	}
	return "";
}

HTMLtag FindValue(vector<HTMLtag> vectorTag, string Tagname)
{
	for (int i = 0; i < vectorTag.size(); i++)
	{
		if (Tagname == vectorTag[i].name)
		{
			return vectorTag[i];
		}
	}
	HTMLtag nullvalue;
	return nullvalue;
}

int main() {
	int numberLine, numberQusetion;
	cin >> numberLine >> numberQusetion;
	string parentsHTML;
	string rootHTM;
	vector<HTMLtag> vectorHTML;
	for (int i = 0; i < numberLine + 1; i++)
	{
		string information;
		getline(cin, information);
		HTMLtag curLine;
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
			if (information[1] == '/')    //태그 닫음
			{
				if (rootHTM.size() > 1)
				{
					rootHTM.erase(rootHTM.size() - parentsHTML.size(), parentsHTML.size());
				}
				parentsHTML = FindValue(vectorHTML, parentsHTML).parents;
				int a = 0;
			}
			else
			{
				curLine.parents = parentsHTML;
				parentsHTML = curLine.name;
				rootHTM += curLine.name;
				curLine.rootValue = rootHTM;
				if (curLine.name != "")vectorHTML.push_back(curLine);
			}
		}
	}

	for (int i = 0; i < numberQusetion; i++)
	{
		string information;
		getline(cin, information);
		string tagName;
		string rootName;
		for (int j = 0; j < information.size(); j++)
		{
			if (information[j] != '.'&&information[j] != '~')
			{
				tagName += information[j];
			}
			else if (information[j] == '~')
			{
				rootName += tagName;
				for (int k = 0; k < vectorHTML.size(); k++)
				{
					if (vectorHTML[k].rootValue == rootName)
					{
						string vectorVale;
						for (int a = j + 1; a < information.size(); a++)vectorVale += information[a];
						
						string answer = FindHTMLvalue(vectorHTML[k].valueVector, vectorVale);
						if (answer != "")
						{
							cout << answer << endl;
							break;
						}
						else
						{
							cout << "Not Found!" << endl;
							break;
						}
					}
					else if(k ==vectorHTML.size()-1)
					{
						cout << "Not Found!" << endl;
					}
				}
			}
		}
	}
	return 0;
}