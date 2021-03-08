#pragma once
#include<string>
#include<fstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class bFile
{
protected:
	string nameFile;
	fstream ft; //поток ввода и вывода
public:
	  ~bFile();
	  bFile();
	//деструктор
	bool is_open();//проверяем открытия файла
	bool feof();//проверяем есть ли еще данные для чтения
	bool openFileIn(string nameFile);//открыть файл для чтения
	void closeFile();//закрыть файл после чтения
	void closeWriteFile();//закрыть файл после записи
	bool openFileOut(string nameFile);//открыть файл для записи
	void readFile(T& temp);//чтение
	void writeFile(T& temp);
	void create(string nameFile);
	fstream& ret()
	{
		return ft;
	}
	//запись
};

template <typename T>
bFile<T>::~bFile()
{
	ft.close();
	if (ft.is_open())
	{
		ft.close();
	}
}

template<typename T>
bFile<T>::bFile() {}

template<typename T>
bool bFile<T>::is_open()
{
	if (!ft.is_open())
		return false;
	else
		return true;
}

template<typename T>
bool bFile<T>::feof()
{
	if (!ft.eof())
		return false;
	else
		return true;
}

template <typename T>
bool bFile<T>::openFileIn(string nameFile)
{
	ft.open(nameFile, ios::in | ios::binary);
	if (!ft.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return false;
	}
	else
		return true;
}

template <typename T>
bool bFile<T>::openFileOut(string nameFile)
{
	ft.open(nameFile, ios::out | ios::binary);
	if (!ft.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return false;
	}
	else
		return true;
}

template <typename T>
void bFile<T>::create(string nameFile)
{
	ft.open(nameFile, ios::out | ios::binary|ios::app);
	ft.close();
}


template <typename T>
void bFile<T>::closeFile()
{
	if (ft.is_open())
		ft.close();
}

template <typename T>
void bFile<T>::closeWriteFile()
{
	if (ft.is_open())
		ft.close();
}

template <typename T>
void bFile<T>::readFile(T& temp)
{
	ft.read((char*)&temp, sizeof(T));
}

template <typename T>
void bFile<T>::writeFile(T& temp)
{
	ft.write((char*)&temp, sizeof(T));
}

