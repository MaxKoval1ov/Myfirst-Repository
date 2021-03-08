#include "library.h"
int main()
{
	cout << "What would you like to add as object." << endl;
	cout << " 1 - Bus" << endl;
	cout << " 2 - Tram" << endl;
	cout << " 3 - Train" << endl;
	cout << " 4 - Tanker" << endl;
	cout << " any other key to exit" << endl;
	switch (cin.get())
	{
	case '1':
	{
		system("cls");
		menu<Bus>("C:\\ÊÏèßÏ\\binary_file\\lib\\Bus.bin");
		break;
	}
	case '2':
	{
		system("cls");
		menu<Tram>("C:\\ÊÏèßÏ\\binary_file\\lib\\Tram.bin");
		break;
	}
	case '3':
	{
		system("cls");
		menu<Train>("C:\\ÊÏèßÏ\\binary_file\\lib\\Train.bin");
		break;
	}
	case '4':
	{
		system("cls");
		menu<Tanker>("C:\\ÊÏèßÏ\\binary_file\\lib\\Tanker.bin");
		break;
	}
	default:
	{
		return 0;
	}
	return 0;
	}
}