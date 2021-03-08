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
	if (end == NULL)                      //если создается первый элемент очереди
	{
		end = new Node<T>;                  //выделяем память под первый элемент
		end->node = tmp;                 //присваиваем элементу переданное в скобках значение
		begin = end;              //приравниваем указатели первого и последнего элемента к созданному первому элементу
		end->next = NULL;                //зануляем указатель первого элемента на следующий
		end->prev = NULL;
		size++;                           //увеличиваем счетчик узлов
	}
	else                                  //если создаются последующие элементы
	{
		Node<T>* temp = new Node<T>;            //выделяем память под элемент
		temp->node = tmp;                 //присваиваем элементу значение
		end->next = temp;
		temp->prev = end;
		temp->next = NULL;                //записываем  указатель на следующий элемент
		end = temp;                      //записываем в last указатель только что созданного элемента
		size++;                           //увеличиваем счетчик узлов
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
	Node<T>* temp = new Node<T>;                 //выделяем память под временную переменную tmp
	temp = begin;
	temp->node.tableheader();
	while (temp != NULL)                    //цикл проходки по очереди
	{
		cout << temp->node;        //печать элемента очереди
		temp = temp->next;                  //переписываем указатель на следующий элемент
	}
	delete temp;                           //освобождаем память от ранее созданной переменной
}
template<typename T>
void Queue<T>::Delete_End()
{
	if (end == NULL) // если очередь пуста
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (size == 1) // если в очереди один элемент
	{
		Node<T>* temp = end;
		delete temp;
		begin = end = NULL;
		cout << "Object has been deleted." << endl;
		size = 0;
		return;
	}
	// если в очереди больше одного элемента
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
	if (end == NULL) // если очередь пуста
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (size == 1) // если в очереди один элемент
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
	if (end == NULL) // если очередь пуста
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (size == 1) // если в очереди один элемент
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