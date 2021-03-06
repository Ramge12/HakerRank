// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>

using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << "0x";
		int firstNum = A/16;
		while (true)
		{
			if (firstNum == 0)
			{
				firstNum = (int)A%16;
				cout << firstNum << endl;
				break;
			}
			cout << firstNum;
			firstNum = firstNum / 16;
		}

		B = round(B * 100) / 100;
		string Bstring = to_string(B);
		Bstring = "+"+Bstring.substr(0, Bstring.find('.') + 3);
		while (true)
		{
			Bstring = "_" + Bstring;
			if (Bstring.size() == 15)break;
		}
		cout << Bstring << endl;

		int countNum = 0;
		while (true)
		{
			if (C >= 10)
			{
				C /= 10;
				countNum++;
			}
			else break;
		}
	/*	C = round(C * 1000000000) / 1000000000;
		string Cstring = to_string(C);
		Cstring = Cstring.substr(0, Cstring.find('.') + 18)+"E+0"+to_string(countNum);*/
		
		printf("%#lx\n", (long int)A);
		printf("%.*s%+.2f\n", 15 - to_string((int)B).length() - 4, "_______________", B);
		printf("%.9E\n", C);
	}
	return 0;

}