#include "LinkedList.h"

#define MAX 1000

int main()
{
	int option = 0;
	int size;
	ds::LinkedList<int> *iLl;
	ds::LinkedList<float> *fLl;
	ds::LinkedList<char> *cLl;
	ds::LinkedList<string> *sLl;    //TODO: Find a way to change this disgusting stuff.

	int iArr[MAX];
	float fArr[MAX];
	char cArr[MAX];
	string sArr[MAX];


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
			for (size_t i = 0; i < size; i++)
			{
				cin >> iArr[i];
			}
			iLl = new ds::LinkedList<int>(iArr,size);
			iLl->vPerformAction();
			break;
		case 2:
			for (size_t i = 0; i < size; i++)
			{
				cin >> fArr[i];
			}
			fLl = new ds::LinkedList<float>(fArr,size);
			fLl->vPerformAction();
			break;
		case 3:
			for (size_t i = 0; i < size; i++)
			{
				cin >> cArr[i];
			}
			cLl = new ds::LinkedList<char>(cArr,size);
			cLl->vPerformAction();
			break;
		case 4:
			for (size_t i = 0; i < size; i++)
			{
				cin >> sArr[i];
			}
			sLl = new ds::LinkedList<string>(sArr,size);
			sLl->vPerformAction();
			break;
		default:
			cout << "Data type doesn't exist, retry some other option\n";
		}
	}
	return 0;
}