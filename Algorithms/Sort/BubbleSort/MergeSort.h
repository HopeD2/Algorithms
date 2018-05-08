#pragma once
#include "stdafx.h"
#include "Sort.h"

class MergeSort : public Sort{
public:
	MergeSort(int *m_arr,int sizeOfArray);
	~MergeSort();
	void vSort();
	void vMergeSort(int *arr, int l, int r);
	void vMerge(int *arr, int l, int m, int r);
};
