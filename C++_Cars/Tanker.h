#pragma once
#include "Trucks.h"
class Tanker :public Trucks
{
private:
		double volume;
public:
	Tanker(string name = "", string color = "", int engines = 0, double weight = 0, double volume = 0);
	~Tanker();
	double getvolume();
	void setvolume();
	friend istream& operator>>(istream& stream, Tanker& ob);
	friend ostream& operator<<(ostream& stream, Tanker& ob);
	bool operator ==(Tanker& ob);
	bool operator >(Tanker& ob);
	bool operator <(Tanker& ob);
	virtual void tableheader();
	void read(fstream& stream);
	void write(fstream& stream);
};