#include "stdafx.h"
#include "QuickSort.h"

QuickSort::QuickSort(int * arr, int sizeOfArr):Sort(arr,sizeOfArr) { }

QuickSort::~QuickSort() { }

void QuickSort::vSort()
{
	quickSort(m_arr, 0, m_sizeOfArray-1);
}

int QuickSort::partition(int * arr, int low, int high)
{
	int pivotPosition = low;

	int pivot = arr[low];
	low++;

	while (1)
	{
		while (low <= high)
		{
			if (arr[low] > pivot)
				break;
			else
				low++;
		}

		while (high >= low)
		{
			if (arr[high] < pivot)
				break;
			else
				high--;
		}

		if (high < low)
		{
			vSwap(&arr[pivotPosition], &arr[high]);
			break;
		}
		else
		{
			vSwap(&arr[low], &arr[high]);
		}
	}
	pivotPosition = high;
	return pivotPosition;
}

void QuickSort::quickSort(int * arr, int low, int high)
{
	if (low > high)
		return;

	int pivotPosition = partition(arr, low, high);

	quickSort(arr, low, pivotPosition - 1);
	quickSort(arr, pivotPosition + 1, high);
}
