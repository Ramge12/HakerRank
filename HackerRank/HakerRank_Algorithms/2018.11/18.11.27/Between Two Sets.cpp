#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

vector<string> split_string(string);


int EU(int x, int y)
{
	int n;
	while (true)
	{
		n = x % y;
		if (n == 0)return y;
		x = y;
		y = n;
	}
}
int lcm(int a, int b)
{
	return a * b / EU(a, b);
}
int getTotalX(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	int firstNum =a[0];
	for (int i = 0; i < a.size(); i++)
	{
		firstNum =lcm(firstNum, a[i]);
	}
	//최소 공배수

	sort(b.begin(), b.end());
	int secondNum =b[0];
	for (int i = 0; i < b.size(); i++)
	{
		secondNum = EU(secondNum, b[i]);
	}
	//최소 공약수
	
	int count = 0;
	int addNum = firstNum;
	while (true)
	{
		if(firstNum > secondNum)break;
		if (secondNum%firstNum == 0)count++;
		firstNum += addNum;
	}
	return count;
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	vector<int> a(n);

	for (int a_itr = 0; a_itr < n; a_itr++) {
		int a_item = stoi(a_temp[a_itr]);

		a[a_itr] = a_item;
	}

	string b_temp_temp;
	getline(cin, b_temp_temp);

	vector<string> b_temp = split_string(b_temp_temp);

	vector<int> b(m);

	for (int b_itr = 0; b_itr < m; b_itr++) {
		int b_item = stoi(b_temp[b_itr]);

		b[b_itr] = b_item;
	}

	int total = getTotalX(a, b);

	//fout << total << "\n";

	//fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
