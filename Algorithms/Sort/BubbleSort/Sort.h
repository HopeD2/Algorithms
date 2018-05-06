#pragma once

class Sort
{
protected:
	int m_arr[MAX_LENGTH];
	int m_sizeOfArray;
public:
	Sort();
	Sort(int *arr,int sizeOfArray);
	virtual ~Sort();
	virtual void vSort() = 0;
	void vSwap(int *num1,int *num2);
	int *iGetArray();
	int  iGetArraySize();
};
