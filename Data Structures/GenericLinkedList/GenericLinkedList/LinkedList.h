#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace ds {

	template <class T_LinkedList>
	struct Node {
		T_LinkedList elem;
		Node<T_LinkedList> *next;
	public:
		Node(T_LinkedList elem):elem(elem) 
		{
			next = NULL;
		}
		
		~Node()
		{
			//elem = NULL;
			next = NULL;
		}
	};

	template <class T_LinkedList>
	class LinkedList {
	public:
		LinkedList();
		LinkedList(T_LinkedList *elem, int size);
		~LinkedList();
		bool bInsertLast(T_LinkedList elem);
		bool bInsert(T_LinkedList elem, int pos);
		bool bInsertStart(T_LinkedList elem);
		bool bDeleteStart();
		bool bDelete(int pos);
		bool bDeleteLast();
		bool bChangeElement(T_LinkedList elem, int pos);
		bool bRemoveElementByValue(T_LinkedList elem);  // Doesn't delete all occurences for now.
		void vDisplay();
		void vPerformAction();
		int iGetSize();
	private:
		Node<T_LinkedList> *m_head;
		Node<T_LinkedList> *m_tail;
		unsigned int m_size;
	};
}