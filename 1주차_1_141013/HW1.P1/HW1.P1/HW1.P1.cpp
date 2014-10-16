// Internal node 개수 구하는 함수
//

#include "stdafx.h"

struct Node
{
	Node* leftChild;
	Node* rightChild;
};


int InteralNodeNum(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	if (node->leftChild == nullptr && node->rightChild == nullptr)
	{
		return 0;

	}

	return 1 + InteralNodeNum(node->leftChild) + InteralNodeNum(node->rightChild);
}

int _tmain(int argc, _TCHAR* argv[])
{


	

	return 0;
}

