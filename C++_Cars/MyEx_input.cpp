#pragma once
#include"MyEx_input.h"
MyEx_input::MyEx_input(int ErrNum, string message):MyException(ErrNum)
{
    this->message = message;
}

int MyEx_input::CheckInt(int Errnum, int min, int max)
{
    int temp;
    bool flag;
    do {
        flag = false;
        try {
            cin >> temp;
            if (cin.peek()!='\n')//Проверка на отсутствие введенных символов 
            {
                throw MyEx_input(Errnum,"You entered symbol.");
            }else
                if (temp < min || temp > max)//Проверка входит ли число в заданные заранее границы
                {
                    throw MyEx_input(Errnum, "Your value should be within limits.");
                }
        }
        catch (MyEx_input& ex)
        {
            cin.clear();
            rewind(stdin);
            cout << "Invailid " << ex.getErrorState() << endl;//Выводит имя поля, где была совершена ошибка
            cout << "Message:"<<ex.GetMessage()<<endl;//Указывает, что именно было сделано не так. 
            flag = true;
        }
        catch (...)//Абсолютный аброботчик исключений
        {
            cout << "Unknown error!";
        }
    } while (flag);//Цикл повторяется пока не будет введено верное значение
    return temp;
}
string MyEx_input::CheckString(int ErrNum, int lenght, bool name,bool letter)
{
    string temp;
    bool flag;

    do {
        flag = false;
        try {
            cin >> temp;
            if (temp.empty()) // Проверка не пуста ли строка
            {
                throw MyEx_input(ErrNum,"You didnt enter your str.");
            }
            if (letter&& (temp[0] < 'A' || temp[0]>'Z'))
            {
               throw MyEx_input(ErrNum, "At the beginning of the word shold be capital letter ");
            }
            if(temp.length()>lenght) //Проверка на превышение макс кол-ва символов
            {
                throw MyEx_input(ErrNum,"Your str is too big.");
            } 
            for (int i=0; i < temp.length(); i++) //Проверка на все символы кроме английских и цифр
            {
                if (name)
                {
                    if ((temp[i] < 'A' || temp[i]>'Z') && (temp[i] < 'a' || temp[i]>'z'))
                    {
                        throw MyEx_input(ErrNum, "You entere russian symbol.");
                    }
                }
                else
                    if ((temp[i] < 'A' || temp[i]>'Z') && (temp[i] < 'a' || temp[i]>'z') && (temp[i] < '0' || temp[i]>'9'))
                    {
                        throw MyEx_input(ErrNum, "You entere russian symbol.");
                    }
            }
        }
        catch (MyEx_input& exception)
        {
            cin.clear(); //Возвращаем поток в исходное состояние
            rewind stdin;//Чистим поток
            cout << "Invalid " << exception.getErrorState() << endl;//Выводит имя поля, где была совершена ошибка
            cout << "Message:" << exception.GetMessage()<<endl;//Указывает, что именно было сделано не так. 
            flag = true;
        }
        catch (...)//Абсолютный аброботчик исключений
        {
            cout << "Unknown error!";
        }
    } while (flag);//Цикл повторяется пока не будет введено верное значение
    return temp;
}