#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class Iterator
{
private:
	Node<T>* ptr;//////////
public:
	Iterator();
	Iterator(Node<T>* tmp);
	~Iterator();
	void operator ++ ();
	void operator -- ();
	void operator ++ (int value);
	void operator -- (int value);
	T& operator * ();
	Node<T>* operator & ();
	bool operator == (const Iterator& other);
	bool operator != (const Iterator& other);
	/*Iterator<T> Begin(Queue<T>* A, Node<T>* begin)
	{
		return Iterator(A, *begin);
	}
	Iterator<T>* End(Queue<T>* A, Node<T>* end)
	{
		return Iterator(A, end->next);
	}*/
};
template<typename T>
Iterator<T>::Iterator()
{
	ptr = NULL;
}
template<typename T>
Iterator<T>::Iterator(Node<T>* tmp)
{
	ptr = tmp;
}
template<typename T>
Iterator<T>::~Iterator()
{
};
template<typename T>
void Iterator<T>:: operator ++ ()
{
	if (ptr->next == NULL)
	{
		cout << "Error" << endl;
		ptr = NULL;
		return;
	}

	ptr = ptr->next;
}

template<typename T>
void Iterator<T>:: operator ++ (int value)
{
	if (ptr->next == NULL)
	{
		cout << "Error" << endl;
		ptr = NULL;
		return;
	}

	ptr = ptr->next;
}
template<typename T>
void Iterator<T>:: operator -- ()
{
	if (ptr->prev == NULL)
	{
		ptr = NULL;
		return;
	}

	ptr = ptr->prev;
}

template<typename T>
void Iterator<T>:: operator -- (int value)
{
	if (ptr->prev == NULL)
	{
		ptr = NULL;
		return;
	}

	ptr = ptr->prev;
}

template<typename T>
T& Iterator<T> ::operator * ()
{
	return ptr->node;
}
template<typename T>
Node<T>* Iterator<T>::operator&()
{
	return ptr;
}
template<typename T>
bool Iterator<T>:: operator == (const Iterator& other) { return ptr == other.ptr; }
template<typename T>
bool Iterator<T>::operator != (const Iterator& other) { return ptr != other.ptr; }