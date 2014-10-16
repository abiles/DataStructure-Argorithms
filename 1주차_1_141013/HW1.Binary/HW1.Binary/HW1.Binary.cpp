// HW1.Binary.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define ARRSIZE 10

int getMostLeftValueIdx(int* arr, int arrSize, int key)
{
	int left = 0;
	int right = arrSize -1;
	int mostLeftValueIdx = -1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (arr[middle] < key)
		{
			left = middle+1 ;
		}
		else if (arr[middle] > key)
		{
			right = middle-1 ;
		}
		else
		{

			mostLeftValueIdx = middle;
			right = middle -1;
		}
		
	
	}


	return mostLeftValueIdx;
}

int getMostRightValueIdx(int* arr, int arrSize, int key)
{
	int left = 0;
	int right = arrSize - 1;
	int mostRightValueIdx = -1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (arr[middle] < key)
		{
			left = middle +1;
		}
		else if (arr[middle] > key)
		{
			right = middle -1;
		}
		else
		{

			mostRightValueIdx = middle;
			left = middle +1;
		}


	}

	return mostRightValueIdx;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[ARRSIZE] = { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 };

	int key = 0;
	int SameValueNum = 0;

	printf_s("key input : ");
	scanf_s("%d", &key);


	SameValueNum = getMostRightValueIdx(arr, ARRSIZE, key) - getMostLeftValueIdx(arr, ARRSIZE, key) +1;

	if (SameValueNum >= 0)
	{
		printf_s("%d 개\n", SameValueNum);

	}
	else
	{
		printf_s("0 개\n");
	}

	getchar();
	getchar();
	return 0;
}

