#pragma once
#include "Sort.h"
#include"stdafx.h"

using namespace std;

class SelectionSort : public Sort{
public:
	SelectionSort(int *arr, int size);
	virtual ~SelectionSort();
	void vSetMinimum(int *arr,int currentSize);
	void vSort();
};