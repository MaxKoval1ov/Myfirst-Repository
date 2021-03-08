#pragma once
#include"PubTransport.h"
class Tram:public PubTransport
{
private:
	double voltage;
public:
	
	Tram(string name="", string color="", int engines=0, double voltage = 0, int passangers = 0);
	~Tram();
	double getvoltage();
	void setvoltage(double voltage);
	friend istream& operator>>(istream& stream, Tram& ob);
	friend ostream& operator<<(ostream& stream, Tram& ob);
	bool operator ==(Tram& ob);
	bool operator >(Tram& ob);
	bool operator <(Tram& ob);
	virtual void tableheader();
	void read(fstream& stream);
	void write(fstream& stream);
};
