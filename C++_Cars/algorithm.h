#pragma once
#include"Queue.h"
#include "MyEx_input.h"//////
template<typename T>
class algorithm
{
public:
	void sortnum(Queue<T>&q);
	void find(Queue<T>&q);
	Queue<T> search(Iterator<T> begin, Iterator<T> end, T searching_point);
};

template<typename T>
void algorithm<T>::sortnum(Queue<T>&q)
{
	cout << "Choose type of sorting:" << endl;
	cout << "1-according to name" << endl;
	cout << "2-according to color" << endl;
	cout << "3-according to engines amounth"<<endl;
	cin.clear();
	rewind(stdin);
	switch (cin.get())
	{
	case '1':
	{
		for (Iterator<T>i = q.Begin(); i != q.End()->next; i++)
		{
			for (Iterator<T>it = i; it != q.End()->next; it++)
			{
				if ((*i).getname() > (*it).getname())
					q.swap(&i, &it);
			}
		}
	}
	break;
	case '2':
	{
		for (Iterator<T>i = q.Begin(); i != q.End()->next; i++)
		{
			for (Iterator<T>it = i; it != q.End()->next; it++)
			{
				if ((*i).getcolor() > (*it).getcolor())
					q.swap(&i, &it);
			}
		}
	}
	break;
	case '3':
	{
		for (Iterator<T>i = q.Begin(); i != q.End()->next; i++)
		{
			for (Iterator<T>it = i; it != q.End()->next; it++)
			{
				if ((*i).getengines() > (*it).getengines())
					q.swap(&i, &it);
			}
		}
	}
	break;
	default:
		cout << "Unknown command"<<endl;
		break;
	}
}

template<typename T>
void algorithm<T>::find(Queue<T>&q)
{
	Queue<T>temp_q;
	cout << "Enter compairing word:";
	string compair;
	compair = MyEx_input::CheckString(1, 11, 0, 0);
	for (Iterator<T>it = q.Begin(); it != q.End()->next; it++)
	{
		if ((*it).getname().find(compair) != string::npos || (*it).getcolor().find(compair) != string::npos)
			temp_q.Push(*it);
	}
	temp_q.Show();
	cin.clear();
	rewind(stdin);
	cin.get();
}

template <class T>
Queue<T> algorithm<T>::search(Iterator<T> begin, Iterator<T> end, T searching_point) //поиск
{
	Queue<T> found;
	for (; begin != end; ++begin)
	{
		if (*begin == searching_point) found.Push(*begin);
	}
	return found;
}

