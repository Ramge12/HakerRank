#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
	//map<int, int> arrMap;
	//int maxNum = 0;
	//for (int i = 0; i < arr.size(); i++)
	//{
	//	if (arrMap.find(arr[i]) == arrMap.end())
	//	{
	//		arrMap.insert(make_pair(arr[i], 1));
	//	}
	//	else
	//	{
	//		arrMap.find(arr[i])->second = (arrMap.find(arr[i])->second)++;
	//		if (arrMap.find(arr[i])->second > maxNum)
	//		{
	//			maxNum = arrMap.find(arr[i])->second;
	//		}
	//	}
	//}
	//vector<int> answer;
	//for (int i = 0; i < arr.size(); i++)
	//{
	//	if (arrMap.find(arr[i])->second == maxNum)
	//	{
	//		answer.push_back(arr[i]);
	//	}
	//}
	//sort(answer.begin(), answer.end());
	//return  answer[0];
	vector<int> arrVector(5);
	for (int i = 0; i < arr.size(); i++)
	{
		switch (arr[i])
		{
		case 1:
			arrVector[0]++;
			break;
		case 2:
			arrVector[2]++;
			break;
		case 3:
			arrVector[3]++;
			break;
		case 4:
			arrVector[4]++;
			break;
		case 5:
			arrVector[5]++;
			break;
		}
	}
	int maxCount=0;
	for (int i = 0; i < arrVector.size(); i++)
	{
		if (maxCount < arrVector[i])maxCount = arrVector[i];
	}
	for (int i = 0; i < arrVector.size(); i++)
	{
		if (arrVector[i] == maxCount)return i + 1;
	}
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	string arr_count_temp;
	getline(cin, arr_count_temp);

	int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(arr_count);

	for (int i = 0; i < arr_count; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int result = migratoryBirds(arr);

	//fout << result << "\n";

	//fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	/*s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);
*/
	return s;
}

string rtrim(const string &str) {
	string s(str);

	/*s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);*/

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
