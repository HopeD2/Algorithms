#include "stdafx.h"
#include "BubbleSort.h"

BubbleSort::BubbleSort(int *arr, int size): Sort(arr,size) { }

BubbleSort::~BubbleSort() { }

void BubbleSort::vSort()
{
	for (int i = 0; i < m_sizeOfArray; i++)
	{
		for (int j = 0; j < m_sizeOfArray - i -1; j++)
		{
			if(m_arr[j] > m_arr[j+1])
				vSwap(&m_arr[j], &m_arr[j+1]);
		}
	}
}
