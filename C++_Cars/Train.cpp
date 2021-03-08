#pragma once
#include "Train.h"
#include<iomanip>
Train::Train(string name, string color, int engines , double weight , int passangers, int wagons) :Trucks(name, color, engines, weight), PubTransport(name, color, engines, passangers), Transport(name, color, engines)
{
	/*cout << "Train constructor" << endl;*/
	this->wagons = wagons;
}
Train::~Train()
{
	/*cout << "Train destructor" << endl;*/
}
int Train::getwagons()
{
	return wagons;
}
void Train::setwagons(int wagons)
{
	this->wagons = wagons;
}
istream& operator>>(istream& stream, Train& ob)
{
	PubTransport* transport;
	transport = &ob;
	stream >> *(dynamic_cast<PubTransport*>(transport));
	cout << "Enter weight(max 1000)";
	ob.weight = MyEx_input::CheckInt(7, 0, 1000);
	cout << "Enter wagons(max 100)";
	ob.wagons= MyEx_input::CheckInt(9, 0, 100);
	return stream;
}
ostream& operator<<(ostream& stream, Train& ob)
{
	PubTransport* transport;
	transport = &ob;
	stream << *(dynamic_cast<PubTransport*>(transport));
	stream<<setw(6) << ob.getweight() << setw(5)<<'|';
	stream << setw(5) << ob.wagons << setw(4) << "|"  << endl;
	return stream;
}

bool Train::operator==(Train& ob)
{

	if (this->name != ob.name && ob.name != "0") return false;
	if (this->color != ob.color && ob.color != "0") return false;
	if (this->engines != ob.engines && ob.engines != 0) return false;
	if (this->passangers != ob.passangers && ob.passangers != 0) return false;
	if (this->weight != ob.weight && ob.weight != 0) return false;
	if (this->wagons != ob.wagons && ob.wagons != 0) return false;
	return true;
}

bool Train::operator>(Train& ob)
{
	return(this->wagons > ob.wagons);
}

bool Train::operator<(Train& ob)
{
	return(this->wagons < ob.wagons);
}


void Train::tableheader()
{
	cout << "Train: " << endl;
	cout << "_________________________________________________________________________________" << endl;
	cout << '|' << setw(14) << " Name     " << '|' << setw(14) << "Color    " << '|' << setw(14) << "Engines   ";
	cout << '|' << setw(12) << "  Passangers  " << '|' <<setw(10)<<"Weight  ";
	cout << '|' << setw(8) << " Wagons " << '|' << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Train::write(fstream& stream)
{
	size_t len1 = name.length() + 1;
	stream.write((char*)&len1, sizeof(len1));
	stream.write((char*)name.c_str(), len1);
	size_t len2 = color.length() + 1;
	stream.write((char*)&len2, sizeof(len2));
	stream.write((char*)color.c_str(), len2);
	stream.write((char*)&engines, sizeof(engines));
	stream.write((char*)&passangers, sizeof(passangers));
	stream.write((char*)&weight, sizeof(weight));
	stream.write((char*)&wagons, sizeof(wagons));
}

void Train::read(fstream& stream)
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
	stream.read((char*)&weight, sizeof(weight));
	stream.read((char*)&wagons, sizeof(wagons));
}