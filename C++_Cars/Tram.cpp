#pragma once
#include "Tram.h"
#include<iomanip>
Tram::Tram(string name, string color, int engines, double voltage, int passangers) :PubTransport(name, color, engines, passangers),Transport(name,color,engines)
{
	/*cout << "Tram constructor" << endl;*/
	this->voltage = voltage;
}
Tram::~Tram()
{
	/*cout << "Tram destructor" << endl;*/
}
double Tram::getvoltage()
{
	return voltage;
}
void Tram::setvoltage(double voltage)
{
	this->voltage = voltage;
}
istream& operator>>(istream& stream, Tram& ob)
{
	PubTransport* transport;
	transport = &ob;
	stream >> *(dynamic_cast<PubTransport*>(transport));
	cout << "Enter Voltage(max 440V)";
	ob.voltage= MyEx_input::CheckInt(6, 0, 1000);;
	return stream;
}
ostream& operator<<(ostream& stream, Tram& ob)
{
	PubTransport* transport;
	transport = &ob;
	stream << *(dynamic_cast<PubTransport*>(transport));
	stream << setw(7) << ob.voltage<<setw(5) << "|" << endl;
	return stream;
}

bool Tram::operator==(Tram& ob)
{

	if (this->name != ob.name && ob.name != "0") return false;
	if (this->color != ob.color && ob.color != "0") return false;
	if (this->engines != ob.engines && ob.engines != 0) return false;
	if (this->passangers != ob.passangers && ob.passangers != 0) return false;
	if (this->voltage != ob.voltage && ob.voltage != 0) return false;
	return true;
}

bool Tram::operator>(Tram& ob)
{
	return(this->voltage > ob.voltage);
}

bool Tram::operator<(Tram& ob)
{
	return(this->voltage < ob.voltage);
}

void Tram::tableheader()
{
	cout << "Tram: " << endl;
	cout << "_________________________________________________________________________" << endl;
	cout << '|' << setw(14) << " Name     " << '|' << setw(14) << "Color    " << '|' << setw(14) << "Engines  " << setw(1);
	cout << '|' << setw(12) << "  Passangers  ";
	cout << '|'  << "  Voltage  " << '|' << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Tram::write(fstream& stream)
{
	size_t len1 = name.length() + 1;
	stream.write((char*)&len1, sizeof(len1));
	stream.write((char*)name.c_str(), len1);
	size_t len2 = color.length() + 1;
	stream.write((char*)&len2, sizeof(len2));
	stream.write((char*)color.c_str(), len2);
	stream.write((char*)&engines, sizeof(engines));
	stream.write((char*)&passangers, sizeof(passangers));
	stream.write((char*)&voltage, sizeof(voltage));
}

void Tram::read(fstream& stream)
{
	size_t len1 = 0;
	stream.read((char*)&len1, sizeof(len1));
	char* buf1 = new char[len1];
	stream.read(buf1, len1);
	name = buf1;
	if (!len1)
		name = "";
	size_t len2 = 0;
	stream.read((char*)&len2, sizeof(len2));
	char* buf2 = new char[len2];
	stream.read(buf2, len2);
	color = buf1;
	if (!len2)
		color = "";

	stream.read((char*)&engines, sizeof(engines));
	stream.read((char*)&passangers, sizeof(passangers));
	stream.read((char*)&voltage, sizeof(voltage));
}