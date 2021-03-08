#pragma once
#include<iomanip>
#include"PubTransport.h"
PubTransport::PubTransport(string name , string color , int engines , int passangers ) :Transport(name, color, engines)
{
	/*cout << "PubTransport constructor" << endl;*/
	this->passangers = passangers;
}
PubTransport::~PubTransport()
{
	/*cout << "PubTransport destructor" << endl;*/
}
int PubTransport::getpassangers()
{
	return passangers;
}
void PubTransport::setpassangers(int passangers)
{
	this->passangers = passangers;
}
istream& operator>>(istream& stream, PubTransport& ob)
{
	Transport* transport;
	transport = &ob;
	stream >> *(dynamic_cast<Transport*>(transport));
	cout << "Enter passangers(max 100)";
	ob.passangers= MyEx_input::CheckInt(4, 0,100);
		return stream;
}
ostream& operator<<(ostream& stream, PubTransport& ob)
{
	Transport* transport;
	transport = &ob;
	stream<< *(dynamic_cast<Transport*>(transport));
	stream << setw(8) << ob.passangers << setw(7) <<"|" ;
	return stream;
}