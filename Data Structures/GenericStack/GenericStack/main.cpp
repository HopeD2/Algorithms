#include "Stack.h"

#define MAX 100

int main()
{
	int option = 0;
	int size;
	ds::Stack<int> *iLl;
	ds::Stack<float> *fLl;
	ds::Stack<char> *cLl;
	ds::Stack<string> *sLl;    //TODO: Find a way to change this disgusting stuff.

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
			iLl = new ds::Stack<int>(iArr, size);
			iLl->vPerformAction();
			break;
		case 2:
			for (size_t i = 0; i < size; i++)
			{
				cin >> fArr[i];
			}
		//	fLl->Init();
			fLl = new ds::Stack<float>(fArr, size);			
			fLl->vPerformAction();
			break;
		case 3:
			for (size_t i = 0; i < size; i++)
			{
				cin >> cArr[i];
			}
		//	cLl->Init();
			cLl = new ds::Stack<char>(cArr, size);
			cLl->vPerformAction();
			break;
		case 4:
			for (size_t i = 0; i < size; i++)
			{
				cin >> sArr[i];
			}
	//		sLl->Init();
			sLl = new ds::Stack<string>(sArr, size);
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