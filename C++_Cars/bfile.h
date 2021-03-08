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
	fstream ft; //����� ����� � ������
public:
	  ~bFile();
	  bFile();
	//����������
	bool is_open();//��������� �������� �����
	bool feof();//��������� ���� �� ��� ������ ��� ������
	bool openFileIn(string nameFile);//������� ���� ��� ������
	void closeFile();//������� ���� ����� ������
	void closeWriteFile();//������� ���� ����� ������
	bool openFileOut(string nameFile);//������� ���� ��� ������
	void readFile(T& temp);//������
	void writeFile(T& temp);
	void create(string nameFile);
	fstream& ret()
	{
		return ft;
	}
	//������
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
		cout << "������ �������� �����!" << endl;
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
		cout << "������ �������� �����!" << endl;
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

