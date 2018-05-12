#include "stdafx.h"
#include "InsertionSort.h"

InsertionSort::InsertionSort(int * arr, int sizeOfArray) : Sort(arr,sizeOfArray) { }

InsertionSort::~InsertionSort() { }

void InsertionSort::vSort()
{
	for (int i = 1; i < m_sizeOfArray; i++)
	{
		int correctPosition = i;
		for (int j = i-1; j >= 0; j--)
		{
			if (m_arr[correctPosition] < m_arr[j])
			{
				vSwap(&m_arr[correctPosition], &m_arr[j]);   // Could move Entire array to the right of the key instead of swapping one by one.
				correctPosition = j;
			}
			else //found correct position to insert
			{
				break;
			}
		}
	}
}
