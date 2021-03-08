#pragma once
#include"Tanker.h"
#include<iomanip>
Tanker::Tanker(string name , string color , int engines, double weight , double volume ) :Trucks(name, color, engines, weight),Transport(name,color,engines)
{
	this->volume = volume;
}
Tanker::~Tanker()
{
	/*cout << "Tanker destructor" << endl;*/
}
double Tanker::getvolume()
{
	return volume;
}
void Tanker::setvolume()
{
	this->volume = volume;
}
istream& operator>>(istream& stream, Tanker& ob)
{
	Trucks* transport;
	transport = &ob;
	stream >> *(dynamic_cast<Trucks*>(transport));
	cout << "Enter volume(max 1000)";
	ob.volume= MyEx_input::CheckInt(8, 0, 1000);
	return stream;
}
ostream& operator<<(ostream& stream, Tanker& ob)
{
	Trucks* transport;
	transport = &ob;
	stream << *(dynamic_cast<Trucks*>(transport));
	stream << setw(8) << ob.volume<<setw(3)<< "|" << endl;
	return stream;
}

bool Tanker::operator==(Tanker& ob)
{

	if (this->name != ob.name && ob.name != "0") return false;
	if (this->color != ob.color && ob.color != "0") return false;
	if (this->engines != ob.engines && ob.engines != 0) return false;
	if (this->weight != ob.weight && ob.weight != 0) return false;
	if (this->volume != ob.volume && ob.volume != 0) return false;
	return true;
}

bool Tanker::operator>(Tanker& ob)
{
	return(this->volume > ob.volume);
}

bool Tanker::operator<(Tanker& ob)
{
	return(this->volume < ob.volume);
}

void Tanker::tableheader()
{
	cout << "Tanker: " << endl;
	cout << "______________________________________________________________________" << endl;
	cout << '|' << setw(14) << " Name     " << '|' << setw(14) << "Color    " << '|' << setw(14) << "Engines  " << setw(1);
	cout << '|' << setw(12) << "  Weight  ";
	cout << '|' << "  Volume  " << '|' << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Tanker::write(fstream& stream)
{
	size_t len1 = name.length() + 1;
	stream.write((char*)&len1, sizeof(len1));
	stream.write((char*)name.c_str(), len1);
	size_t len2 = color.length() + 1;
	stream.write((char*)&len2, sizeof(len2));
	stream.write((char*)color.c_str(), len2);
	stream.write((char*)&engines, sizeof(engines));
	stream.write((char*)&weight, sizeof(weight));
	stream.write((char*)&volume, sizeof(volume));
}

void Tanker::read(fstream& stream)
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
	stream.read((char*)&weight, sizeof(weight));
	stream.read((char*)&volume, sizeof(volume));
}