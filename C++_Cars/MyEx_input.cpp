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
            if (cin.peek()!='\n')//�������� �� ���������� ��������� �������� 
            {
                throw MyEx_input(Errnum,"You entered symbol.");
            }else
                if (temp < min || temp > max)//�������� ������ �� ����� � �������� ������� �������
                {
                    throw MyEx_input(Errnum, "Your value should be within limits.");
                }
        }
        catch (MyEx_input& ex)
        {
            cin.clear();
            rewind(stdin);
            cout << "Invailid " << ex.getErrorState() << endl;//������� ��� ����, ��� ���� ��������� ������
            cout << "Message:"<<ex.GetMessage()<<endl;//���������, ��� ������ ���� ������� �� ���. 
            flag = true;
        }
        catch (...)//���������� ���������� ����������
        {
            cout << "Unknown error!";
        }
    } while (flag);//���� ����������� ���� �� ����� ������� ������ ��������
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
            if (temp.empty()) // �������� �� ����� �� ������
            {
                throw MyEx_input(ErrNum,"You didnt enter your str.");
            }
            if (letter&& (temp[0] < 'A' || temp[0]>'Z'))
            {
               throw MyEx_input(ErrNum, "At the beginning of the word shold be capital letter ");
            }
            if(temp.length()>lenght) //�������� �� ���������� ���� ���-�� ��������
            {
                throw MyEx_input(ErrNum,"Your str is too big.");
            } 
            for (int i=0; i < temp.length(); i++) //�������� �� ��� ������� ����� ���������� � ����
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
            cin.clear(); //���������� ����� � �������� ���������
            rewind stdin;//������ �����
            cout << "Invalid " << exception.getErrorState() << endl;//������� ��� ����, ��� ���� ��������� ������
            cout << "Message:" << exception.GetMessage()<<endl;//���������, ��� ������ ���� ������� �� ���. 
            flag = true;
        }
        catch (...)//���������� ���������� ����������
        {
            cout << "Unknown error!";
        }
    } while (flag);//���� ����������� ���� �� ����� ������� ������ ��������
    return temp;
}