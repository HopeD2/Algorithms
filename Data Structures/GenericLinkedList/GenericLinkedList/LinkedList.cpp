
#include "LinkedList.h"

template class ds::LinkedList<int>;
template class ds::LinkedList<float>;
template class ds::LinkedList<char>;
template class ds::LinkedList<string>;



template<class T_LinkedList>
ds::LinkedList<T_LinkedList>::LinkedList()
{
	m_head = NULL;
	m_tail = NULL;
}

template<class T_LinkedList>
ds::LinkedList<T_LinkedList>::LinkedList(T_LinkedList *elem, int size)
{
	m_size = size;
	for (size_t i = 0; i < size; i++)
	{
		ds::Node<T_LinkedList> *newNode = new ds::Node<T_LinkedList>(elem[i]);
		if (newNode)
		{
			//newNode->elem = elem[i];
			//newNode->next = NULL;
			if (i == 0)
			{
				m_tail = m_head = newNode;
			}
			else
			{
				m_tail->next = newNode;
				m_tail = newNode;
			}
		}
		else
		{
			cout << "Construction failed\n";
		}
	}
}

template<class T_LinkedList>
ds::LinkedList<T_LinkedList>::~LinkedList()
{ 
	Node<T_LinkedList> *temp;
	while (m_head != m_tail)
	{
		temp = m_head;
		m_head= m_head->next;
		delete temp;
	}
	cout << "Destructor called"<<endl;
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bInsertLast(T_LinkedList elem)
{
	Node<T_LinkedList> *newNode = new Node<T_LinkedList>(elem);
	if (newNode)
	{
		m_tail->next = newNode;
		m_tail = newNode;
		m_size++;
		return true;
	}
	return false;
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bInsert(T_LinkedList elem, int pos)
{
	if (pos <= m_size)
	{
		ds::Node<T_LinkedList> *newNode = new Node<T_LinkedList>(elem);
		if (newNode)
		{
			ds::Node<T_LinkedList> *temp = m_head;
			if (temp)
			{
				for (size_t i = 0; i < pos-2; i++)
				{
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
				m_size++;
				return true;
			}
			else
			{
				cout << "Head Node empty\n";
				return false;
			}
		}
		else
		{
			cout << "Construction failed\n";
			return false;
		}
	}
	else
	{
		cout << "Incorrect Position\n";
		return false;
	}
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bInsertStart(T_LinkedList elem)
{
	ds::Node<T_LinkedList> *newNode = new Node<T_LinkedList>(elem);
	if (newNode)
	{
		newNode->next = m_head;
		m_head = newNode;
		m_size++;
		return true;
	}
	else
	{
		cout << "Construction failed\n";
		return false;
	}
	
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bDeleteStart()
{
	ds::Node<T_LinkedList> *temp = m_head;
	if (temp)
	{
		m_head = temp->next;
		delete temp;
		m_size--;
		return true;
	}
	else
	{
		cout << "Head Node Empty\n";
		return false;
	}
	
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bDelete(int pos)
{
	if (pos <= m_size)
	{
		ds::Node<T_LinkedList> *temp = m_head;
		if (temp)
		{
			for (size_t i = 0; i < pos-2; i++)
			{
				temp = temp->next;
			}
			ds::Node<T_LinkedList> *nextNode = temp->next->next;
			delete temp->next;
			temp->next = nextNode;
			m_size--;
			return true;
		}
		else
		{
			cout << "Head Node empty\n";
			return false;
		}
	}
	else
	{
		cout << "Incorrect Position\n";
		return false;
	}
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bDeleteLast()
{
	ds::Node<T_LinkedList> *temp = m_head;
	if (temp)
	{
		ds::Node<T_LinkedList> *prevNode;
		while (temp->next != NULL)
		{
			prevNode = temp;
			temp = temp->next;
		}
		prevNode->next = NULL;
		delete m_tail;
		m_tail = prevNode;
		m_size--;
		return true;
	}
	else
	{
		cout << "Empty Head Node\n";
		return false;
	}
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bChangeElement(T_LinkedList elem, int pos)
{
	ds::Node<T_LinkedList> *curNode;
	if (pos <= m_size)
	{
		ds::Node<T_LinkedList> *tempNode = m_head;
		if (tempNode)
		{
			for (size_t i = 0; i < pos; i++)
			{
				curNode = tempNode;
				tempNode = tempNode->next;
			}
			curNode->elem = elem;
			return true;
		}
		else
		{
			cout << "Head Node Empty\n";
			return false;
		}
	}
	else
	{
		cout << "Incorrect Position\n";
		return false;
	}
	
}

template<class T_LinkedList>
bool ds::LinkedList<T_LinkedList>::bRemoveElementByValue(T_LinkedList elem)
{
	ds::Node<T_LinkedList> *prevNode;
	ds::Node<T_LinkedList> *tempNode = m_head;

	bool result = false;
	if (tempNode)
	{
		if (elem == m_head->elem)
		{
			if(!bDeleteStart())
			{ 
				cout << "Delete at head Unsuccessful\n";
			}
			else
			{
				tempNode = m_head;
				result = true;
			}
		}
		if (elem == m_tail->elem)
		{
			if (!bDeleteLast())
			{
				cout << "Delete at tail Unsuccessful\n";
			}
			else
			{
				result = true;
			}
		}
		while (tempNode->next != NULL)
		{
			prevNode = tempNode;
			tempNode = tempNode->next;
			if (tempNode->elem == elem)
			{
				prevNode->next = tempNode->next;
				delete tempNode;
				tempNode = prevNode->next;
				result = true;
			}
		}
		return result;
	}
	else
	{
		return false;
	}
}

template<class T_LinkedList>
void ds::LinkedList<T_LinkedList>::vDisplay()
{
	cout << "Linked List::\n";
	ds::Node<T_LinkedList> *temp = m_head;
	cout << "================================================================================\n";
	while (temp->next != NULL)
	{
		cout << temp->elem << "      ";
		temp = temp->next;
	}
	cout << temp->elem;
	cout << "\n";
	cout << "================================================================================\n";
	cout << endl;
}

template<class T_LinkedList>
void ds::LinkedList<T_LinkedList>::vPerformAction()
{
	int option = 0;

	while (option != 6)
	{
		cout << "Select the action you want to perform\n1)Change element\n2)Insert \
Element\n3)Remove Element by value\n4)Remove element by Position\n5)Disp\
layArray\n6)Get LinkedList Size\n7)Reselect data type or Exit this menu\n";


		cin >> option;
		T_LinkedList value;
		int position;

		switch (option)
		{
		case 1:
			cout << "Enter the new value,position\n";
			cin >> value >> position;
			if (this->bChangeElement(value, position))
			{
				this->vDisplay();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}
			break;
		case 2:
			cout << "Enter the new value,position\n";
			cin >> value >> position;
			if (position == 1)
			{
				if (this->bInsertStart(value))
				{
					cout << "Insertion at Head Successful\n";
				}
			}
			else if (position == m_size)
			{
				if (this->bInsertLast(value))
				{
					cout << "Insertion at tail successful\n";
				}
			}
			else
			{
				if (this->bInsert(value, position))
				{
					cout << "Insertion at position " << position << " Successful\n";
				}
			}
			this->vDisplay();
			break;
		case 3:
			cout << "Enter the value of the element you want to remove\n";
			cin >> value;
			if (this->bRemoveElementByValue(value))
			{
				this->vDisplay();
			}
			else
			{
				cout << "Position entered is invalid, please retry\n";
			}

			break;
		case 4:
			cout << "Enter the postion of the element you want to remove\n";
			cin >> position;
			if (position == 1)
			{
				if (this->bDeleteStart())
				{
					cout << "Deletion at head successful\n";
				}
			}
			else if (position == m_size)
			{
				if (this->bDeleteLast())
				{
					cout << "Deletion at tail successful\n";
				}
			}
			else
			{
				if (this->bDelete(position))
				{
					cout << "Deletion at position " << position << " Successful\n";
				}
			}
			this->vDisplay();
			break;
		case 5:
			this->vDisplay();
			break;
		case 6:
			cout<<"Size is : "<<this->iGetSize();
			break;
		case 7: //Exit
			return;
		default:
			cout << "Action does not exist\n";
		}
	}
}

template<class T_LinkedList>
int ds::LinkedList<T_LinkedList>::iGetSize()
{
	return m_size;
}
