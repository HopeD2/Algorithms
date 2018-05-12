#include "stdafx.h"
#include "SelectionSort.h"

SelectionSort::SelectionSort(int * arr, int size) : Sort(arr,size) { }

SelectionSort::~SelectionSort() { }

void SelectionSort::vSetMinimum(int * arr, int currentSize)
{
	int minimum = arr[0];
	int indexOfMinimum = 0;
	for (int i = 0; i < currentSize; i++)
	{
		if (arr[i] < minimum)
		{
			minimum = arr[i];
			indexOfMinimum = i;
		}
	}
	vSwap(&arr[0], &arr[indexOfMinimum]);

}

void SelectionSort::vSort()
{
	for (int i = 0; i < m_sizeOfArray; i++)
	{
		vSetMinimum(&m_arr[i], m_sizeOfArray - i);
	}
}

