// MaxHeap.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
141014 김성연

HW#2.C1

2014-11-03

maxHeapify문제

*/

struct heap_t
{
	int size; //node 개수
	int capacity; //배열 최대 크기
	int* element;
};


void maxHeapify(heap_t* heap, int pos)
{
	//이게 배열에서의 값이니까 노드가 되는 거고 
	//이 노드의 left child subtree와 r은 모두 maxheap이다
	int leftChildIdx = pos * 2;
	int rightChildIdx = pos * 2 + 1;
	int largestIdx = pos;

	if (leftChildIdx <= heap->size &&
		(heap->element[leftChildIdx] > heap->element[pos]))
	{
		largestIdx = leftChildIdx;
	}
	
	if (rightChildIdx <= heap->size &&
		(heap->element[rightChildIdx] > heap->element[largestIdx]))
	{
		largestIdx = rightChildIdx;
	}

	if (largestIdx != pos)
	{
		int tmpElement = 0;
		tmpElement = heap->element[pos];
		heap->element[pos] = heap->element[largestIdx];
		heap->element[largestIdx] = tmpElement;
		maxHeapify(heap, largestIdx);
	}
}

heap_t* makeSampleHeap(int n)
{
	if (n == 0)
	{
		return nullptr;
	}

	heap_t* tmpHeap = (heap_t*)malloc(sizeof(heap_t));
	tmpHeap->element = (int*)malloc(sizeof(int) * n+1);
	
	//element[0]은 사용하지 않으므로
	tmpHeap->element[0] = -INT_MAX;
	/////////////////////////////
	tmpHeap->capacity = n;
	tmpHeap->size = n;

	for (int i = 1; i <= n; ++i)
	{
		tmpHeap->element[i] = rand() % n;
	}

	for (int j = n; j >= 1; --j)
	{
		maxHeapify(tmpHeap, j);
	}
	
	return tmpHeap;
}

bool isMaxHeap(heap_t* heap)
{
	if (heap == nullptr || heap->size <= 0)
	{
		return false;
	}

	for (int i = 1; i < heap->size; ++i)
	{
		int leftChildIdx = i * 2;
		int rightChildIdx = i * 2 + 1;
		if (leftChildIdx <= heap->size)
		{
			if (heap->element[leftChildIdx] > heap->element[i])
			{
				return false;
			}
		}

		if (rightChildIdx <= heap->size)
		{
			if (heap->element[rightChildIdx] > heap->element[i])
			{
				return false;
			}
		}
	}

	return true;
}

void printHeap(heap_t* heap)
{
	static int testNum = 1;
	printf_s("\n");
	printf_s("TestHeapPrint%d\n", testNum++);
	if (heap == nullptr)
	{
		printf_s("no element\n");
		return;
	}

	for (int i = 1; i <= heap->size; ++i)
	{
		int leftChildIdx = i * 2;
		int rightChildIdx = i * 2 + 1;
		printf_s("curIdx = %d\t", i);
		printf_s("curElement = %d\t", heap->element[i]);
		if (leftChildIdx <= heap->size)
		{
			printf_s("leftChildElement = %d\t", heap->element[leftChildIdx]);
		}
		if (rightChildIdx <= heap->size)
		{
			printf_s("rightCHildElement = %d\t", heap->element[rightChildIdx]);
		}
		
		if (leftChildIdx > heap->size || rightChildIdx > heap->size)
		{
			printf_s("\n");
		}
	
	}
}

void testHeapify(int n)
{
	heap_t* testHeap = makeSampleHeap(n);
	printHeap(testHeap);
	isMaxHeap(testHeap) ? printf_s("MaxHeap\n") : printf_s("Not MaxHeap\n");
}




int _tmain(int argc, _TCHAR* argv[])
{
	srand(unsigned int (time(NULL)));
	testHeapify(0);
	testHeapify(1);
	testHeapify(5);
	testHeapify(10);
	testHeapify(20);

	getchar();
	return 0;
}

