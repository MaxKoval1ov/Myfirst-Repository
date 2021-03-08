#pragma once
#include"PubTransport.h"
class Bus:public PubTransport
{
private:
	double fuel;
public:
	Bus(string name = "", string color = "", int engines = 0, double fuel = 0,int passangers = 0);
	~Bus();
	double getfuel();
	void setfuel(double fuel);
	friend istream& operator>>(istream& stream, Bus& ob);
	friend ostream& operator<<(ostream& stream, Bus& ob);
	bool operator ==(Bus& ob);
	bool operator >(Bus& ob);
	bool operator <(Bus& ob);
	virtual void tableheader();
	void write(fstream& stream);
	void read(fstream& stream);
};