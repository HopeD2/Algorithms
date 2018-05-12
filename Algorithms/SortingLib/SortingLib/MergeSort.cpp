#include "stdafx.h"
#include "MergeSort.h"

MergeSort::MergeSort(int * m_arr, int sizeOfArray): Sort(m_arr,sizeOfArray) { }

MergeSort::~MergeSort() { }

void MergeSort::vSort()
{
	vMergeSort(m_arr,0,m_sizeOfArray-1);
}

void MergeSort::vMergeSort(int * arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		// Divide into two halves
		vMergeSort(arr, l, m); 
		vMergeSort(arr, m + 1, r); 

		vMerge(arr, l, m, r); // Sort and Merge.Conquer and Combine !!!
	}
}

void MergeSort::vMerge(int * arr, int l, int m, int r)
{
	int lengthLeft = m - l + 1;
	int lengthRight = r - m;

	int tempLeft[MAX_LENGTH / 2];
	int tempRight[MAX_LENGTH / 2];

	for (int i = 0; i < lengthLeft; i++)
		tempLeft[i] = arr[l+i];

	for (int i = 0; i < lengthRight; i++)
		tempRight[i] = arr[m+1+i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i<lengthLeft && j <lengthRight)
	{
		if (tempLeft[i] < tempRight[j])
		{
			arr[k] = tempLeft[i];
			i++;
		}
		else
		{
			arr[k] = tempRight[j];
			j++;
		}
		k++;
	}


	while (i < lengthLeft)
	{
		arr[k] = tempLeft[i];
		i++;
		k++;
	}

	while (j < lengthRight)
	{
		arr[k] = tempRight[j];
		j++;
		k++;
	}
}
