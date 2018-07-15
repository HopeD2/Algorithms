#pragma once

#include <iostream>
#include <string>
#include "Node.h"

namespace ds{

	template <class T_Stack>
	class Stack {
	private:
		unsigned int m_size;
		Node<T_Stack> *m_top;
	public:
		Stack();
		Stack(T_Stack *elem, unsigned int size);
		~Stack();
		void Init();
		bool bPush(T_Stack elem);
		bool bPop(T_Stack *value);
		T_Stack sPeek();
		void vDisplay();
		void vPerformAction();
		bool bIsEmpty();
		unsigned int uiGetSize();
	};

}
