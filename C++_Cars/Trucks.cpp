#pragma once
#include"Trucks.h"
#include<iomanip>
Trucks::Trucks(string name , string color , int engines, double weight ) :Transport(name, color, engines)
{
	/*cout << "Trucks constructor" << endl;*/
	this->weight = weight;
}
Trucks::~Trucks()
{
	/*cout << "Trucks destructor" << endl;*/
}
double Trucks::getweight()
{
	return weight;
}
void Trucks::setweight(double weight)
{
	this->weight = weight;
}
istream& operator>>(istream& stream, Trucks& ob)
{
	Transport* transport;
	transport = &ob;
	stream >> *(dynamic_cast<Transport*>(transport));
	cout << "Enter weight(max 1000)";
	ob.weight= MyEx_input::CheckInt(7, 1, 1000);
	return stream;
}
ostream& operator<<(ostream& stream, Trucks& ob)
{
	Transport* transport;
	transport = &ob;
	stream << *(dynamic_cast<Transport*>(transport));
	stream << setw(9) << ob.weight << setw(4) << "|";
	return stream;
}