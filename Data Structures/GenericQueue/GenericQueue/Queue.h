#pragma once

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

namespace ds {

	template <class T_Queue>
	class Queue {
	private:
		Node<T_Queue> *m_front;
		Node<T_Queue> *m_rear;
		unsigned int m_size;
	public:
		Queue();
		Queue(T_Queue *elem,unsigned int size);
		~Queue();
		void init();
		bool bEnqueue(T_Queue elem);
		bool bDequeue(T_Queue *elem);
		bool bIsEmpty();
		T_Queue qPeek();
		unsigned int uiGetSize();
		void vDisplay();
		void vPerformAction();
	};

	

}