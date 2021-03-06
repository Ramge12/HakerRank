#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
	int count = 0;
	int answer = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int preCount = count;
		if (s[i] == 'U')count++;
		if (s[i] == 'D')count--;
		if (count == 0 && preCount<0)answer++;
	}
	return answer;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(cin, s);

	int result = countingValleys(n, s);

	fout << result << "\n";

	fout.close();

	return 0;
}