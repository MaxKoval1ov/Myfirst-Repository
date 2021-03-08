#pragma once
#include"transport.h"
class Trucks:public virtual Transport
{
protected:
	double weight;
public:
	Trucks(string name = "", string color = "", int engines = 0, double weight = 0);
	virtual~Trucks();
	double getweight();
	void setweight(double weight);
	friend istream& operator>>(istream& stream, Trucks& ob);
	friend ostream& operator<<(ostream& stream, Trucks& ob);
	virtual void tableheader() {};
};