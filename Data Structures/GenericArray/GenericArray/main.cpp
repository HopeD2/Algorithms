#include "GenericArray.h"

int main()
{
	int option = 0;
	int size;
	CArray<int> *iArr;
	CArray<float> *fArr;
	CArray<char> *cArr;
	CArray<string> *sArr;    //TODO: Find a way to change this disgusting stuff.

	while (1)
	{
		cout << "Select the data type :\n1)Integer\n2)Float\n3)Character\n4)String\n";
		cin >> option;

		cout << "Enter the size of the array : \n";
		cin >> size;
		cout << "Enter the array elements : \n";
			
		switch (option)
		{
		case 1:
		    iArr = new CArray<int>(size);
			iArr->vPerformAction();
			break;
		case 2:
			fArr = new CArray<float>(size);
			fArr->vPerformAction();
			break;
		case 3:
			cArr = new CArray<char>(size);
			cArr->vPerformAction();
			break;
		case 4:
			sArr = new CArray<string>(size);
			sArr->vPerformAction();
			break;
		default:
			cout << "Data type doesn't exist, retry some other option\n";
		}
	}
	return 0;
}
