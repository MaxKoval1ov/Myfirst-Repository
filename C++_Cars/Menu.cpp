#include"algorithm.h"
#include"bfile.h"
template<typename T>
void write_in_queue(Queue<T>& ob, string name)
{
	bFile<T> f;
	f.create(name);
	if (!f.openFileIn(name)) cout << "Error";
	T temp;
	while (!f.feof())
	{
		temp.read(f.ret());
		string strtmp = temp.getname();
		if (strtmp != "")
			ob.Push(temp);
	}
}

template<typename T>
void read_from_queue(Queue<T>& ob, string name)
{
	bFile<T> f;
	f.openFileOut(name);
	for (Iterator<T>i = ob.Begin(); i != ob.End()->next; i++)
	{
		(*i).write(f.ret());
	}
}

template<typename T>
void menu(string name)
{
	algorithm<T>fun;
	while (1)
	{
		system("cls");
		cout << "Choose command:" << endl;
		cout << " 1 - Add object" << endl;
		cout << " 2 -Show" << endl;
		cout << " 3 - Delete begin" << endl;
		cout << " 4 - Delete end" << endl;
		cout << " 5-Delete according to num" << endl;
		cout << " 6-sort" << endl;
		cout << " 7-find according to compairing word" << endl;
		cout << " 8-find according to multi parameters" << endl;
		cout << " 0 - Exit" << endl;
		cin.sync();
		cin.clear(); //Возвращаем поток в исходное состояние
		rewind stdin;//Чистим поток
		switch (cin.get())
		{
		case '1':
		{
			Queue<T>a;
			write_in_queue(a, name);
			system("cls");
			do
			{
				T temp;
				cout << "New object:";
				cin >> temp;
				a.Push(temp);
				cout << "Continue-any; exit- 0)" << endl;
				cin.clear();
				rewind(stdin);
				cin.sync();
			} while (cin.get() != '0');
			read_from_queue(a, name);
			break;
		}
		case '2':
		{
			Queue<T>a;
			write_in_queue(a, name);
			system("cls");
			a.Show();
			cout << "Size:" << a.GetSize() << endl;
			system("pause");
			break;
		}
		case '3':
		{
			Queue<T>a;
			write_in_queue(a, name);
			system("cls");
			a.Delete_Begin();
			system("pause");
			read_from_queue(a, name);
			break;
		}
		case '4':
		{
			Queue<T>a;
			write_in_queue(a, name);
			system("cls");
			a.Delete_End();
			system("pause");
			read_from_queue(a, name);
			break;
		}
		case '5':
		{
			Queue<T>a;
			write_in_queue(a, name);
			if (a.GetSize() == 0) 
			{
				cout << "Queue is empty" << endl;
				break;
			}
			system("cls");
			cout << "Which object would you like to delete?(from 0 to"<<a.GetSize()<<")" << endl;
			int temp;
			do
			{
				cin.clear(); //Возвращаем поток в исходное состояние
				rewind stdin;//Чистим поток
				cin >> temp;
			} while (temp < 0 || temp >= a.GetSize());
			a.Delete_choose(temp);
			read_from_queue(a, name);
			break;
		}
		case '6':
		{
			Queue<T>a;
			write_in_queue(a, name);
			fun.sortnum(a);
			read_from_queue(a, name);
			break;
		}
		case '7':
		{
			Queue<T>a;
			write_in_queue(a, name);
			fun.find(a);
			read_from_queue(a, name);
			break;
		}
		case '8':
		{
			Queue<T>a;
			write_in_queue(a, name);
			cout << "Enter object to compair(press 0 to ignor)"<<endl;
			T compair;
			cin >> compair;
			Queue<T>temp_que;
			for (Iterator<T>begin=a.Begin(); begin != a.End()->next; ++begin)
			{
				if (*begin == compair) temp_que.Push(*begin);
			}
			temp_que.Show();
			cin.clear();
			rewind(stdin);
			cin.get();
			break;
		}
		case '0':
		{
			return;
		}
		default:
		{
			cout << "Unknown command." << endl;
		}
		}
	}
	return;
}