#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[])		//수식 트리 구성
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);

	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))	// 피연산자라면...
		{
			SetData(pnode, exp[i] - '0');	//문자를 정수로 바꿔서 저장
		}
		else					//연산자라면...
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode * bt)		//수식 트리 계산
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)	//단말노드라면
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));	//첫 번째 피연산자 왼쪽 서브 트리 계산
	op2 = EvaluateExpTree(GetRightSubTree(bt));	//두 번째 피연산자 오른쪽 서브 트리 계산

	switch (GetData(bt))			//연산자를 확인하여 연산을 진행
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		cout << data << endl;		//피연산자 출력
	else
		cout << data << endl;		//연산자 출력
}
void ShowPrefixTypeExp(BTreeNode * bt)	//전위 표기법 기반 출력
{
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt)	//중위 표기법 기반 출력
{
	InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode * bt)	//후위 표기법 기반 출력
{
	PostorderTraverse(bt, ShowNodeData);
}


int main()
{

    return 0;
}

