#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

typedef int BTData;

struct BTreeNode	//이진 트리의 노드를 표현한 구조체
{
	BTData data;
	BTreeNode * left;
	BTreeNode * right;
};

BTreeNode * MakeBTreeNode(void)				//노드의 생성
{
	BTreeNode * nd = new BTreeNode;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
BTData GetData(BTreeNode * bt)				//노드에 저장된 데이터를 반환
{
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data)	//노드에 데이터를 저장
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)	//왼쪽 서브 트리의 주소 값 반환
{
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt)	//오른쪽 서브 트리의 주소 값 반환
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)		// 왼쪽 서브 트리를 연결한다
{
	if (main->left != NULL)
		delete(main->left);		//메모리의 소멸까지 진행한다

	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)	// 오른쪽 서브 트리를 연결한다.
{
	if (main->right != NULL)
		delete(main->right);

	main->right = sub;
}
void DeleteTree(BTreeNode * bt)		//이진 트리 삭제 함수
{
	if (bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	cout << bt->data << endl;
	delete(bt);
}
void InorderTraverse(BTreeNode * bt)	//이진 트리 전체를 중위 순회하는 함수
{
	if (bt == NULL)	//bt가 NULL이면 재귀 탈출
		return;

	InorderTraverse(bt->left);		//1단계 왼쪽 서브 트리의 순회
	cout << bt->data << endl;		//2단계 루트 노드 방문
	InorderTraverse(bt->right);		//3단계 오른쪽 서브 트리의 순회
}
void PreorderTraverse(BTreeNode * bt)	//전위 순회 함수
{
	if (bt == NULL)
		return;

	cout << bt->data << endl;	//전위 순회이므로 루트 노드 먼저 방문
	PreorderTraverse(bt->left);	
	PreorderTraverse(bt->right);
}
void PostorderTraverse(BTreeNode * bt)	//후위 순회 함수
{
	if (bt == NULL)
		return;
	
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	cout << bt->data << endl;	//후위 순회이므로 루트 노드 나중 방문
}

int main()
{

    return 0;
}

