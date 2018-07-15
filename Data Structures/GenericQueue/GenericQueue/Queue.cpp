#include "Queue.h"

template class ds::Queue<int>;
template class ds::Queue<float>;
template class ds::Queue<char>;
template class ds::Queue<string>;

template<class T_Queue>
ds::Queue<T_Queue>::Queue()
{
	m_front = NULL;
	m_rear = NULL;
	m_size = 0;
}

template<class T_Queue>
ds::Queue<T_Queue>::Queue(T_Queue * elem, unsigned int size)
{
	init();
	for (unsigned int i = 0; i < size; i++)
	{
		bEnqueue(elem[i]);
	}
}

template<class T_Queue>
ds::Queue<T_Queue>::~Queue()
{
	while (m_front != m_rear)
	{
		Node<T_Queue> *tempNode = m_front;
		m_front = m_front->next;
		delete tempNode;
	}
	delete m_front;
}

template<class T_Queue>
void ds::Queue<T_Queue>::init()
{
	m_front = NULL;
	m_rear = NULL;
	m_size = 0;
}

template<class T_Queue>
bool ds::Queue<T_Queue>::bEnqueue(T_Queue elem)
{
	Node<T_Queue> *newNode = new Node<T_Queue>(elem);
	if (newNode)
	{
		if (bIsEmpty())
		{
			m_front = m_rear = newNode;
			m_size++;
			return true;
		}
		else
		{
			m_rear->next = newNode;
			m_rear = newNode;
			m_size++;
			return true;
		}
	}
	else
	{
		return false; 
	}
	
}

template<class T_Queue>
bool ds::Queue<T_Queue>::bDequeue(T_Queue *elem)
{
	if (!bIsEmpty())
	{
		Node<T_Queue> *tempNode = m_front;
		m_front = m_front->next;
		*elem = tempNode->elem;
		delete tempNode;
		m_size--;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T_Queue>
bool ds::Queue<T_Queue>::bIsEmpty()
{
	return (m_size==0);
}

template<class T_Queue>
T_Queue ds::Queue<T_Queue>::qPeek()
{
	return m_front->elem;
}

template<class T_Queue>
unsigned int ds::Queue<T_Queue>::uiGetSize()
{
	return m_size;
}

template<class T_Queue>
void ds::Queue<T_Queue>::vDisplay()
{
	if (!bIsEmpty())
	{
		Node<T_Queue> *tempNode = m_front;
		while (tempNode->next != NULL)
		{
			cout << "|      " << tempNode->elem << "     |";
			tempNode = tempNode->next;
		}
		cout << "|      " << tempNode->elem << "     |\n";
	}
	else
	{
		cout << "===================\n";
		cout << "Queue Empty! \n";
		cout << "===================\n";
	}
}

template<class T_Queue>
void ds::Queue<T_Queue>::vPerformAction()
{
	int option = 0;

	while (1)
	{
		cout << "Select the action you want to perform\n1)Enqueue\n2)DeQueue \
\n3)Peek\n4)Display\n5)Display queue size\n6)Reselect data type or Exit this menu\n";


		cin >> option;
		T_Queue value;
		int position;

		switch (option)
		{
		case 1:
			cout << "Enter the new value\n";
			cin >> value;
			if (this->bEnqueue(value))
			{
				this->vDisplay();
			}
			else
			{
				cout << "Enqueue unsuccessful \n";
			}
			break;
		case 2:
			if (this->bDequeue(&value))
			{
				cout << "Dequeued Value : " << value << "\n";
			}
			else
			{
				cout << "===================\n";
				cout << "Queue Empty! \n";
				cout << "===================\n";
			}
			this->vDisplay();
			break;
		case 3:
			value = qPeek();
			if (value != (T_Queue)NULL)
			{
				cout << "==============================\n";
				cout << "Value at Queue front : " << value << "\n";
				cout << "==============================\n";
			}
			else
			{
				cout << "===================\n";
				cout << "Queue Empty! \n";
				cout << "===================\n";
			}
			break;
		case 4:
			this->vDisplay();
			break;
		case 5:
			cout<<"Size is :"<< this->uiGetSize()<<"\n";
			break;
		case 6: //Exit
			return;
		default:
			cout << "Action does not exist\n";
		}
	}
}

