#pragma once
template<typename T>
struct Node
{
	T node;
	Node* next;
	Node* prev;
	Node();
	Node(const T ptr);
	~Node() = default;
	void tableheader()
	{
		node.tableheader();
	}
};
template<typename T>
Node<T>::Node()
{};
template<typename T>
Node<T>::Node(const T ptr) :next(nullptr), prev(nullptr), node(ptr)
{};