#pragma once

#include "stdafx.h"
#include "Sort.h"

class InsertionSort :public Sort{
public:
	InsertionSort(int *arr, int sizeOfArray);
	~InsertionSort();
	void vSort();
};