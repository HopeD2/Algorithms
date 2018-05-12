#pragma once

#include "stdafx.h"
#include "Sort.h"
using namespace std;

class BubbleSort : public Sort{
public:
	BubbleSort(int *array,int size);
	virtual ~BubbleSort();
	void vSort();
};