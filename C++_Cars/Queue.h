#pragma once
#include<iostream>
#include"Iterator.h"
using namespace std;
template<typename T>
class Queue
{
private:
	Node<T>* begin;
	Node<T>* end;
	int size;
public:
	Queue();
	~Queue();
    int GetSize() 
	{ return this->size; };
	void Push(T tmp);
	void Show();
	void Delete_End();
	void Delete_Begin();
	void Delete_choose(int num);
	void ShowIT();
	void ShowITreverse();
	Node<T>* Begin()
	{
		return begin;
	}
	Node<T>* End()
	{
		return end;
	}

	void swap(Node<T>* first, Node<T>* second);
};
template<typename T>
Queue<T>::Queue()
{
	begin = NULL;
	end = NULL;
	size = 0;
}
template<typename T>
Queue<T>::~Queue()
{
	if (end == NULL)
		return;
	if (size == 1)
	{
		Node<T>* temp = this->begin;
		delete temp;
		begin = end = NULL;
		size = 0;
		return;
	}
	Node<T>* temp = begin;
	while (1)
	{
		begin = begin->next;
		delete temp;
		temp = begin;
		if (begin->next == NULL)
			break;
	}
	delete end;
	begin = end = NULL;
	size = 0;
}
template<typename T>
void Queue<T>::Push(T tmp)
{
	if (end == NULL)                      //���� ��������� ������ ������� �������
	{
		end = new Node<T>;                  //�������� ������ ��� ������ �������
		end->node = tmp;                 //����������� �������� ���������� � ������� ��������
		begin = end;              //������������ ��������� ������� � ���������� �������� � ���������� ������� ��������
		end->next = NULL;                //�������� ��������� ������� �������� �� ���������
		end->prev = NULL;
		size++;                           //����������� ������� �����
	}
	else                                  //���� ��������� ����������� ��������
	{
		Node<T>* temp = new Node<T>;            //�������� ������ ��� �������
		temp->node = tmp;                 //����������� �������� ��������
		end->next = temp;
		temp->prev = end;
		temp->next = NULL;                //����������  ��������� �� ��������� �������
		end = temp;                      //���������� � last ��������� ������ ��� ���������� ��������
		size++;                           //����������� ������� �����
	}
}
template<typename T>
void Queue<T>::Show()
{
	if (end == NULL)
	{
		cout << "Queue is empty" << endl;
		return;
	}
	Node<T>* temp = new Node<T>;                 //�������� ������ ��� ��������� ���������� tmp
	temp = begin;
	temp->node.tableheader();
	while (temp != NULL)                    //���� �������� �� �������
	{
		cout << temp->node;        //������ �������� �������
		temp = temp->next;                  //������������ ��������� �� ��������� �������
	}
	delete temp;                           //����������� ������ �� ����� ��������� ����������
}
template<typename T>
void Queue<T>::Delete_End()
{
	if (end == NULL) // ���� ������� �����
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (size == 1) // ���� � ������� ���� �������
	{
		Node<T>* temp = end;
		delete temp;
		begin = end = NULL;
		cout << "Object has been deleted." << endl;
		size = 0;
		return;
	}
	// ���� � ������� ������ ������ ��������
	Node<T>* tmp_del = end;
	Node<T>* tmp_prev = end->prev;
	tmp_prev->next = NULL;
	end = tmp_prev;
	delete tmp_del;
	/*tmp_del = tmp_prev->next;
	tmp_prev->next = NULL;
	begin = tmp_prev;
	if (tmp_prev->next != NULL)
		delete tmp_del;*/
	size--;
	cout << "Object has been deleted." << endl;
}
template<typename T>
void Queue<T>::Delete_Begin()
{
	if (end == NULL) // ���� ������� �����
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (size == 1) // ���� � ������� ���� �������
	{
		Node<T>* temp = begin;
		delete temp;
		begin = end = NULL;
		cout << "Object has been deleted." << endl;
		size = 0;
		return;
	}
	Node<T>* tmp_del = begin;
	Node<T>* tmp_next = begin->next;
	tmp_next->prev = NULL;
	begin = tmp_next;
	delete tmp_del;
	size--;
};

template<typename T>
void Queue<T>::Delete_choose(int num)
{
	if (end == NULL) // ���� ������� �����
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (size == 1) // ���� � ������� ���� �������
	{
		Node<T>* temp = begin;
		delete temp;
		begin = end = NULL;
		cout << "Object has been deleted." << endl;
		size = 0;
		return;
	}
	Node<T>* tmp_del = begin;
	for(int i=0;i<num;i++)
		tmp_del = begin->next;
	if (tmp_del->prev == NULL) 
	{
		/*Node<T>* tmp_next = tmp_del->next;
		tmp_next->prev = NULL;
		begin = tmp_next;
		delete tmp_del;
		size--;*/
			Delete_Begin();
			return;
	}
	if (tmp_del->next == NULL)
	{
		/*Node<T>* tmp_prev = tmp_del->prev;
		tmp_prev->next = NULL;
		end = tmp_prev;
		delete tmp_del;
		size--*/
		Delete_End();
		return;
	}
	Node<T>* tmp_next = tmp_del->next;
	Node<T>* tmp_prev = tmp_del->prev;
	tmp_next->prev = tmp_prev;
	tmp_prev->next = tmp_next;
		delete tmp_del;
		size--;
};

template < typename T >
void Queue<T>::swap(Node<T>* first,Node<T>* second)
{
	T temp = first->node;
	first->node = second->node;///
	second->node = temp;//
}

template < typename T >
void Queue<T>::ShowIT()
{
	T table;
	table.tableheader();
	for (Iterator<T>i = this->begin; i != End()->next; i++)
	{
		cout << *i << "\n";
	}
}

template < typename T >
void Queue<T>::ShowITreverse()
{
	T table;
	table.tableheader();
	for (Iterator<T>i = end; i != begin; i--)
	{
		cout << *i << "\n";
	}
}