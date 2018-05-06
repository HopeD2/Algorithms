#include "stdafx.h"
#include "Sort.h"

Sort::Sort() { }

Sort::Sort(int *arr, int size)
{
	m_sizeOfArray = size;
	memcpy(m_arr, arr, sizeof(int)*size);
}

Sort::~Sort()
{
}

void Sort::vSwap(int * num1, int * num2)
{
	int tempNum;
	tempNum = *num1;
	*num1 = *num2;
	*num2 = tempNum;
}

int * Sort::iGetArray()
{
	return m_arr;
}

int Sort::iGetArraySize()
{
	return m_sizeOfArray;
}
