#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T_Array>
class CArray {
private:
	T_Array *m_pArr;
	int m_size;
	int m_actualSize;
	bool bInsertElement(T_Array val, int position);
	bool bRemoveElementByValue(T_Array val);
	bool bRemoveElementByPosition(int position);
	bool bChangeValue(T_Array val, int position);
	void vPrintArray();
public:
	CArray(T_Array *arr, int size);
	CArray(int size);
	CArray();
	~CArray();
	void vPerformAction();
	void resizeArray();
	int getCurrentSize() const;
	int getActualSize() const;
};
