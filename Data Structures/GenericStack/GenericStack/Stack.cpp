#include "Stack.h"

template class ds::Stack<int>;
template class ds::Stack<float>;
template class ds::Stack<char>;
template class ds::Stack<string>;

template<class T_Stack>
ds::Stack<T_Stack>::Stack()
{
	m_size = 0;
	m_top = NULL;

}

template<class T_Stack>
ds::Stack<T_Stack>::Stack(T_Stack * elem, unsigned int size)
{
	m_top = NULL;
	m_size = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		bPush(elem[i]);
	}
}

template<class T_Stack>
ds::Stack<T_Stack>::~Stack()
{
	Node<T_Stack> *tempNode;
	while (tempNode->next != NULL)
	{
		tempNode = m_top;
		m_top = m_top->next;
		delete tempNode;
	}
}

template<class T_Stack>
void ds::Stack<T_Stack>::Init()
{
	m_top = NULL;
	m_size = 0;
}

template<class T_Stack>
bool ds::Stack<T_Stack>::bPush(T_Stack elem)
{
	Node<T_Stack> *newNode = new Node<T_Stack>(elem);
	if (m_top == NULL)
	{
		m_top = newNode;
		m_size++;
		return true;
	}
	else
	{
		Node<T_Stack> *tempNode = m_top;
		m_top = newNode;
		m_top->next = tempNode;
		m_size++;
		return true;
	}
	return false;
}

template<class T_Stack>
bool ds::Stack<T_Stack>::bPop(T_Stack *value)
{
	if (m_top != NULL)
	{
		Node<T_Stack> *tempNode = m_top;
		m_top = m_top->next;
		*value = tempNode->elem;
		delete tempNode;
		m_size--;
		return true;
	}
	else
	{
		return false;
	}
	
}

template<class T_Stack>
T_Stack ds::Stack<T_Stack>::sPeek()
{
	if (m_top != NULL)
	{
		return m_top->elem;
	}
	else
	{
		return NULL;
	}
}

template<class T_Stack>
void ds::Stack<T_Stack>::vDisplay()
{
	if (!bIsEmpty())
	{
		cout << "Stack\n";
		Node<T_Stack> *tempNode = m_top;
		while (tempNode->next != NULL)
		{
			cout << "____________________\n";
			cout << "|        " << tempNode->elem << "          |\n";
			tempNode = tempNode->next;
		}
		cout << "____________________\n";
		cout << "|        " << tempNode->elem << "          |\n";
		cout << "____________________\n";
	}
	else
	{
		cout << "===================\n";
		cout << "Stack Empty! \n";
		cout << "===================\n";
	}
}

template<class T_Stack>
void ds::Stack<T_Stack>::vPerformAction()
{
	int option = 0;

	while (1)
	{
		cout << "Select the action you want to perform\n1)Push\n2)Pop \
\n3)Peek\n4)Display\n5)Display Stack Size\n6)Reselect data type or Exit this menu\n";


		cin >> option;
		T_Stack value;
		int position;

		switch (option)
		{
		case 1:
			cout << "Enter the new value\n";
			cin >> value;
			if (this->bPush(value))
			{
				this->vDisplay();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}
			break;
		case 2:
			if (this->bPop(&value))
			{
				cout << "Popped Value : "<<value<<"\n";
			}
			else
			{
				cout << "===================\n";
				cout << "Stack Empty! \n";
				cout << "===================\n";
			}
			this->vDisplay();
			break;
		case 3:
			value = sPeek();
			if (value != (T_Stack)NULL)
			{
				cout << "==============================\n";
				cout << "Value at Stack top : "<<value<<"\n";
				cout << "==============================\n";
			}
			else
			{
				cout << "===================\n";
				cout << "Stack Empty! \n";
				cout << "===================\n";
			}
			break;
		case 4:
			this->vDisplay();
			break;
		case 5:
			this->uiGetSize();
			break;
		case 6: //Exit
			return;
		default:
			cout << "Action does not exist\n";
		}
	}
}

template<class T_Stack>
bool ds::Stack<T_Stack>::bIsEmpty()
{
	return (m_size == 0);
}

template<class T_Stack>
unsigned int ds::Stack<T_Stack>::uiGetSize()
{
	return m_size;
}
