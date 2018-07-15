#pragma once

using namespace std;

namespace ds{
	template <class T>
	struct Node {
	T elem;
	Node<T> *next;
	public:
	Node(T elem) :elem(elem)
	{
		next = NULL;
	}

	~Node()
	{
		//elem = NULL;
		next = NULL;
	}
	};
}