// HW1.P3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>

#define ARRSIZE 10


void increaseInsertionSort(int* arr, int arrSize)
{
	if (arr == nullptr || arrSize <=0)
	{
		printf_s("원소가 존재하지 않습니다.");
		return;
	}

	int comparedValue = 0;

	for (int i = 1; i < arrSize; ++i)
	{
		comparedValue = arr[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] > comparedValue)
			{
				arr[j + 1] = arr[j];
				arr[j] = comparedValue;
			}
			else
			{
				break;
			}
		}
	}

	for (int i = 0; i < arrSize; ++i)
	{
		if (i % 10 == 0)
		{
			printf_s("\n");
		}

		printf_s("%d\t", arr[i]);

	}
	printf_s("\n");
	getchar();
	getchar();
}

void decreaseInsertionSort(int* arr, int arrSize)
{
	if (arr == nullptr || arrSize <= 0)
	{
		printf_s("원소가 존재하지 않습니다.");
		return;
	}

	int comparedValue = 0;

	for (int i = 1; i < arrSize; ++i)
	{
		comparedValue = arr[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] < comparedValue)
			{
				arr[j + 1] = arr[j];
				arr[j] = comparedValue;
			}
			else
			{
				break;
			}
		}
	}

	for (int i = 0; i < arrSize; ++i)
	{
		if (i % 10 == 0)
		{
			printf_s("\n");
		}

		printf_s("%d\t", arr[i]);

	}
	printf_s("\n");
	getchar();
	getchar();
}



int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	
	
	int arr1[ARRSIZE] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int arr2[ARRSIZE] = { 4, 4, 4, 2, 2, 2, 2, 1, 1, 1 };
	int arr3[ARRSIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	int arr4[ARRSIZE * 10];
	for (int i = 0; i < ARRSIZE * 10; ++i)
	{
		arr4[i] = 1 + rand() % (ARRSIZE * 10) ;
	}

	int arr5[ARRSIZE * 100];
	for (int i = 0; i < ARRSIZE * 100; ++i)
	{
		arr5[i] = 1 + rand() % (ARRSIZE * 100);
	}


	int arr6[ARRSIZE * 1000];
	for (int i = 0; i < (ARRSIZE * 1000); ++i)
	{
		arr6[i] = 1 + rand() % (ARRSIZE * 1000);
	}
	

	while (input != -1)
	{
		printf_s("1~3는 입력 특성 관점, 4~6은 원소 개수 관점, -1은 종료\n");
		printf_s("case input: ");
		scanf_s("%d", &input, 1);
		switch (input)
		{
		case 1:
		
			increaseInsertionSort(arr1, ARRSIZE);
			break;
		case 2:
			
			increaseInsertionSort(arr2, ARRSIZE);
			break;
		case 3:
			
			increaseInsertionSort(arr3, ARRSIZE);
			break;
		case 4:
			increaseInsertionSort(arr4, ARRSIZE*10);
			break;
		case 5:
			increaseInsertionSort(arr5, ARRSIZE*100);
			break;
		case 6:
			increaseInsertionSort(arr6, ARRSIZE*1000);
			break;
		case -1:
			printf_s("종료합니다\n");
			return 0;
		default:
			printf_s("잘못된 입력입니다");
			break;
		}
		
		system("cls");
	}
	
	getchar();
	return 0;
}

