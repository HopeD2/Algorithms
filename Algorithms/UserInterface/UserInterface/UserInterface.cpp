#include "UserInterface.h"

UserInterface::UserInterface() { }

UserInterface::~UserInterface() { }

void UserInterface::vDisplayMenu()
{
	cout << "Select the type of Sorting Algorithm you want to use : "<<endl;
	cout << "1)Bubble Sort\n2)Selection Sort\n3)Insertion Sort\n4)MergeSort\n5)QuickSort\n6)Exit\n";
}

int UserInterface::iGetUserInput()
{
	int option;
	cin >> option;
	return option;
}

void UserInterface::vDisplayArray(int * arr, int sizeofArray)
{
	for (int i = 0; i < sizeofArray; i++)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
}

int UserInterface::iGetArraySizeFromUser()
{
	int arraySize;
	cout << "Enter number of elements : ";
	cin>>arraySize;
	cout << "\n";
	return arraySize ;
}

void UserInterface::vGetArrayFromUser(int* arr,int size)
{
	cout << "Enter the Elements : ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}
