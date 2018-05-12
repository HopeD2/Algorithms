#pragma once
#include "stdafx.h"
#include "Sort.h"

class QuickSort:public Sort
{
public:
	QuickSort(int *arr, int sizeOfArr);
	~QuickSort();
	void vSort();
	int partition(int *arr, int low, int high);
	void quickSort(int *arr, int low , int high);
};
