#pragma once
#include"MyException.h"

class MyEx_input:public MyException
{
protected:
		string message;
public:	
	MyEx_input(int ErrNum,string message);
	static int CheckInt(int ErrNum, int min, int max);//Статическая функция проверки int перемнной
	static string CheckString(int ErrNum, int lenght,bool name,bool letter);//Статическая функция проверки на ввод строки
	string GetMessage()
	{
		return message;
	}
};
