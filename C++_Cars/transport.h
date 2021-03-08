#pragma once
#include<iostream>
#include"MyEx_input.h"
#include<string.h>
#include<fstream>
using namespace std;
class Transport
{
protected:
	string name,color;
	int engines;
public:
	Transport(string name = "", string color = "", int engines = 0);
	virtual~Transport();
	string getname();
	void setname(string name);
	string getcolor();
	void setcolor(string color);
	int getengines();
	void setengines(int wheels);
	friend istream& operator >> (istream& stream, Transport& ob);
	friend ostream& operator << (ostream& stream,const Transport &ob);
	virtual void tableheader() {};
};