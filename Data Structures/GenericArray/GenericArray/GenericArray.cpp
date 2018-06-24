#include "GenericArray.h"

//TODO : Move this to LIB. Later to be used by the runner application.

template class CArray<int>;
template class CArray<float>;
template class CArray<char>;
template class CArray<string>;

template<class T_Array>
void CArray<T_Array>::vPrintArray()
{
	for (int i = 0; i < m_size; i++)
	{
		cout << m_pArr[i] << " ";
	}
	cout << endl;
}

template<class T_Array>
void CArray<T_Array>::vPerformAction() //TODO : Create a generic class (template of template) for User Interface, so that you can test such programs with that.
{
	int option = 0;

	while (option != 6)
	{
		cout << "Select the action you want to perform\n1)Change element\n2)Insert \
Element\n3)Remove Element by value\n4)Remove element by Position\n5)Disp\
layArray\n6)Reselect data type or Exit this menu\n";
		

		cin >> option;
		T_Array value;
		int position;

		switch (option)
		{
		case 1:
			cout << "Enter the new value,position\n";
			cin >> value >> position;
			if (this->bChangeValue(value, position))
			{
				this->vPrintArray();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}
			break;
		case 2:
			cout << "Enter the new value,position\n";
			cin >> value >> position;
			if (this->bInsertElement(value, position))
			{
				this->vPrintArray();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}
			break;
		case 3:
			cout << "Enter the value of the element you want to remove\n";
			cin >> value;
			if (this->bRemoveElementByValue(value))
			{
				this->vPrintArray();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}
			
			break;
		case 4:
			cout << "Enter the postion of the element you want to remove\n";
			cin >> position;
			if (this->bRemoveElementByPosition(position))
			{
				this->vPrintArray();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}
			break;
		case 5:
			this->vPrintArray();
			break;
		case 6: //Exit
			return;
		default:
			cout << "Action does not exist\n";
		}
	}

}

template<class T_Array>
void CArray<T_Array>::resizeArray()
{
	m_actualSize *= 2;
	T_Array *resized_Array = new T_Array[m_actualSize];

	copy(m_pArr, m_pArr + m_size, resized_Array);
	
	delete [] m_pArr;
	m_pArr = resized_Array;
}

template<class T_Array>
int CArray<T_Array>::getCurrentSize() const
{
	return m_size;
}

template<class T_Array>
int CArray<T_Array>::getActualSize() const
{
	return m_actualSize;
}

template<class T_Array>
CArray<T_Array>::CArray(T_Array *arr,int size)
{
	m_size = size;
	m_actualSize = size;
	m_pArr = new T_Array[size];
	for (int i = 0; i < m_size; i++)
	{
		m_pArr[i] = arr[i];
	}
}

template<class T_Array>
CArray<T_Array>::CArray(int size)
{
	m_size = size;
	m_actualSize = size;
	m_pArr = new T_Array[size];
	for (int i = 0; i < m_size; i++)
	{
		cin >> m_pArr[i];
	}
}

template<class T_Array>
CArray<T_Array>::CArray()
{
}

template<class T_Array>
CArray<T_Array>::~CArray()
{
	delete[] m_pArr;
}

template<class T_Array>
bool CArray<T_Array>::bInsertElement(T_Array val, int position)
{
	if (position <= m_size)
	{
		if (m_size == m_actualSize)
		{
			resizeArray();
		}

		for (int i = m_size; i > position - 1; i--)
		{
			m_pArr[i + 1] = m_pArr[i];
		}
		m_pArr[position] = val;
		m_size++;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T_Array>
bool CArray<T_Array>::bChangeValue(T_Array newVal, int position)
{
	if (position < m_size)
	{
		m_pArr[position] = newVal;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T_Array>
bool CArray<T_Array>::bRemoveElementByPosition(int position)
{
	if (position < m_size)
	{
		for (int i = position; i < m_size; i++)
		{
			m_pArr[i] = m_pArr[i + 1];
		}
		m_size--;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T_Array>
bool CArray<T_Array>::bRemoveElementByValue(T_Array value)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_pArr[i] == value)
		{
			if (bRemoveElementByPosition(i))
			{
				return true;
			}
		}
	}
	return false;
}