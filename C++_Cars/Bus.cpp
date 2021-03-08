#pragma once
#include "Bus.h"
#include<fstream>
#include<iomanip>
Bus::Bus( string name , string color , int engines , double fuel,int passangers ) :PubTransport(name, color, engines, passangers),Transport(name,color,engines)
{
	/*cout << "Bus constructor" << endl;*/
	this->fuel = fuel;
}
Bus::~Bus()
{
	/*cout << "Bus destructor" << endl;*/
}
double Bus::getfuel()
{
	return fuel;
}
void Bus::setfuel(double fuel)
{
	this->fuel = fuel;
}
istream& operator>>(istream& stream, Bus& ob)
{
	PubTransport* transport;
	transport = &ob;
	stream >> *(dynamic_cast<PubTransport*>(transport));
	cout << "Enter fuel(max 200)";
	ob.fuel= MyEx_input::CheckInt(5, 0, 200);
	return stream;
}
ostream& operator<<(ostream& stream, Bus& ob)
{
	PubTransport* transport;
	transport = &ob;
	stream << *(dynamic_cast<PubTransport*>(transport));
	stream << setw(6) << ob.fuel<<setw(6) << "|" << endl;
	return stream;
}

bool Bus::operator==(Bus& ob)
{
	if (this->name != ob.name && ob.name != "0") return false;
	if (this->color != ob.color && ob.color != "0") return false;
	if (this->engines != ob.engines && ob.engines != 0) return false;
	if (this->passangers != ob.passangers && ob.passangers != 0) return false;
	if (this->fuel != ob.fuel && ob.fuel != 0) return false;
	return true;
}

bool Bus::operator>(Bus& ob)
{
	return(this->fuel > ob.fuel);
}

bool Bus::operator<(Bus& ob)
{
	return(this->fuel < ob.fuel);
}

void Bus::tableheader()
{
	cout << "Bus: " << endl;
	cout << "_________________________________________________________________________"<<endl;
	cout << '|' << setw(14) << " Name     " << '|' << setw(14) << "Color    " << '|' << setw(14) << "Engines  " << setw(1);
	cout << '|' << setw(12) << "  Passangers  ";
	cout << '|' <<setw(11)<< "  Fuel   " << '|' << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Bus::write(fstream& stream)
{
	size_t len1 = name.length() + 1;
	stream.write((char*)&len1, sizeof(len1));
	stream.write((char*)name.c_str(), len1);
	size_t len2 = color.length() + 1;
	stream.write((char*)&len2, sizeof(len2));
	stream.write((char*)color.c_str(), len2);
	stream.write((char*)&engines, sizeof(engines));
	stream.write((char*)&passangers, sizeof(passangers));
	stream.write((char*)&fuel, sizeof(fuel));
}

void Bus::read(fstream& stream)
{
		size_t len1=0;
		stream.read((char*)&len1, sizeof(len1));
		char* buf1 = new char[len1];
		stream.read(buf1, len1);
		name = buf1;
		if (!len1)
			name = "";
		size_t len2=0;
		stream.read((char*)&len2, sizeof(len2));
		char* buf2 = new char[len2];
		stream.read(buf2, len2);
		color = buf1;
		if (!len2)
			color = "";
		stream.read((char*)&engines, sizeof(engines));
		stream.read((char*)&passangers, sizeof(passangers));
		stream.read((char*)&fuel, sizeof(fuel));
}