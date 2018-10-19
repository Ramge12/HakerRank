// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

void update(int *a, int *b) {
	// Complete this function    
	int m_a = *a;
	int m_b = *b;
	*a = m_a + m_b;
	*b = m_a - m_b;
	if (*b < 0)*b *= -1;
}

int main() {
	int a, b;
	int *pa = &a, *pb = &b;

	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);

	return 0;
}