#pragma once
#include<exception>
#include<string.h>
#include<iostream>
using namespace std;
class MyException:public exception
{
protected:
	int ErrNum;
	string ErrState;
public:
	MyException(int ErrNum)
	{
            this->ErrNum = ErrNum;
            switch (ErrNum) {
            case 1:
                ErrState = "Name";   
                break;
            case 2:
                ErrState = "Color";       
                break;
            case 3:
                ErrState = "Angines";    
                break;
            case 4:
                ErrState = "Passangers";     
                break;
            case 5:
                ErrState = "Fuel";
                break;
            case 6:
                ErrState = "Voltage";
                break;
            case 7:
                ErrState = "Weight";  
                break;
            case 8:
                ErrState = "Volume";
                break;
            case 9:
                ErrState = "Wagons";
                break;
            }
	}
	const int getErrorNum() { return ErrNum; }
	string getErrorState() {
		return ErrState;
	}
	~MyException() {};
};