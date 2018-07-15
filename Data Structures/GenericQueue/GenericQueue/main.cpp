#include "Queue.h"

#define MAX 100

int main()
{
	int option = 0;
	int size;
	ds::Queue<int> *iLl;
	ds::Queue<float> *fLl;
	ds::Queue<char> *cLl;
	ds::Queue<string> *sLl;    //TODO: Find a way to change this disgusting stuff.

	int iArr[MAX];
	float fArr[MAX];
	char cArr[MAX];
	string sArr[MAX];


	while (1)
	{
		cout << "Select the data type :\n1)Integer\n2)Float\n3)Character\n4)String\n5)Exit\n";
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
			//	iLl->Init();
			iLl = new ds::Queue<int>(iArr, size);
			iLl->vPerformAction();
			break;
		case 2:
			for (size_t i = 0; i < size; i++)
			{
				cin >> fArr[i];
			}
			//	fLl->Init();
			fLl = new ds::Queue<float>(fArr, size);
			fLl->vPerformAction();
			break;
		case 3:
			for (size_t i = 0; i < size; i++)
			{
				cin >> cArr[i];
			}
			//	cLl->Init();
			cLl = new ds::Queue<char>(cArr, size);
			cLl->vPerformAction();
			break;
		case 4:
			for (size_t i = 0; i < size; i++)
			{
				cin >> sArr[i];
			}
			//		sLl->Init();
			sLl = new ds::Queue<string>(sArr, size);
			sLl->vPerformAction();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "Data type doesn't exist, retry some other option\n";
		}
	}

	return 0;
}