// BubbleSort.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "UserInterface.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main()
{
	
	while (1)
	{
		int n;
		int arr[MAX_LENGTH];

		UserInterface ui;
		ui.vDisplayMenu();
		int option = ui.iGetUserInput();

		if (option == 6) break;

		n = ui.iGetArraySizeFromUser();
		ui.vGetArrayFromUser(arr,n);

		//TODO: Move this to Factory Class Implementation
		Sort *sorter;
		switch (option)
		{
		case 1:
			sorter = new BubbleSort(arr,n);
			break;
		case 2:
			sorter = new SelectionSort(arr, n);
			break;
		case 3:
			sorter = new InsertionSort(arr, n);
			break;
		case 4:
			sorter = new MergeSort(arr, n);
			break;
		case 5:
			sorter = new QuickSort(arr, n);
			break;
		default:
			cout << "Option unavailable, Please try again" << endl;
		}
		ui.vDisplayArray(sorter->iGetArray(),sorter->iGetArraySize());
		sorter->vSort();
		ui.vDisplayArray(sorter->iGetArray(),sorter->iGetArraySize());
	}
    return 0;
}

