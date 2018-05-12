#pragma once
#include "stdafx.h"

using namespace std;

class UserInterface {
public:
	UserInterface();
	~UserInterface();
	void vDisplayMenu();
	int iGetUserInput();
	void vDisplayArray(int *arr, int sizeofArray);
	int iGetArraySizeFromUser();
	void vGetArrayFromUser(int *arr,int size);
};