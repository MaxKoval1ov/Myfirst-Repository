#pragma once
#include"MyException.h"

class MyEx_input:public MyException
{
protected:
		string message;
public:	
	MyEx_input(int ErrNum,string message);
	static int CheckInt(int ErrNum, int min, int max);//����������� ������� �������� int ���������
	static string CheckString(int ErrNum, int lenght,bool name,bool letter);//����������� ������� �������� �� ���� ������
	string GetMessage()
	{
		return message;
	}
};
