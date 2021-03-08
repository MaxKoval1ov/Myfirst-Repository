#pragma once
#include"Trucks.h"
#include"PubTransport.h"
class Train:public Trucks,public PubTransport
{
private:
	int wagons;
public:
	Train(string name = "", string color = "", int engines= 0, double weight = 0, int passangers = 0, int wagons = 0);
	~Train();
	int getwagons();
	void setwagons(int wagons);
	friend istream& operator>>(istream& stream, Train& ob);
	friend ostream& operator<<(ostream& stream, Train& ob);
	bool operator ==(Train& ob);
	bool operator >(Train& ob);
	bool operator <(Train& ob);
	virtual void tableheader();
	void read(fstream& stream);
	void write(fstream& stream);
};