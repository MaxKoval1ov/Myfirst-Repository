#pragma once
#include "transport.h"
#include<iomanip>
Transport::Transport(string name , string color , int engines )
{
	/*cout << "Transport constructor" << endl;*/
	this->name = name;
	this->color = color;
	this->engines = engines;
}
Transport::~Transport()
{
	/*cout << "Transport destructor" << endl;*/
}
string Transport:: getname()
{
	return name;
}
void Transport::setname(string name)
{
	this->name = name;
}
string Transport::getcolor()
{
	return color;
}
void Transport::setcolor(string color)
{
	this->color = color;
}
int Transport::getengines()
{
	return engines;
}
void Transport::setengines(int wheels)
{
	this->engines = wheels;
}
istream& operator>>(istream& stream, Transport& ob)
{
	cout << "Enter name(max length:11)";
	ob.name = MyEx_input::CheckString(1, 11,0,0);
			cout << "Enter color(max length:10)";
			ob.color= MyEx_input::CheckString(2, 11,0,0);
			cout << "Enter engines (max 10)";
			ob.engines= MyEx_input::CheckInt(3,0,10);
		return stream;
}
ostream& operator<<(ostream& stream, const Transport& ob)
{
	    stream << "|" << setw(9) << ob.name << setw(6) << "|" << setw(11) << ob.color << setw(4) << "|" << setw(8) << ob.engines << setw(7) << "|" << setw(4);
	    return stream;
}

