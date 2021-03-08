#pragma once
#include"transport.h"
class PubTransport :public virtual Transport
{
protected:
	int passangers;
public:
	PubTransport(string name = "", string color = "", int engines = 0, int passangers = 0);
	virtual~PubTransport();
	int getpassangers();
	void setpassangers(int passangers);
	friend istream& operator>>(istream& stream, PubTransport& ob);
	friend ostream& operator<<(ostream& stream, PubTransport& ob);
	virtual void tableheader() {};
};