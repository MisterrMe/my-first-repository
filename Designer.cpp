// StreetDesigner.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include "Street.h"

void DialogWithTheUser(Street *Str)
{
	using namespace std;
	string Name;
	int Number, ch;
	while (1)
	{
		cout << "\nPress: \n1-to add new house, \n2-to remove house, \n3-to get house data, \n4-to get street data, \n5-to rename street, \n0-to exit\n";
		cin >> ch;
		if (ch != 0 && ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5)
		{
			cout << "Invalid input data. Re-enter.\n";
			continue;
		}
		if (ch == 1)
		{
			cout << "Enter the house number followed by addition of a new.\nIf you add the first house-enter 0\n(if the house is not the last, the numbering of the remaining will be shifted)\n";
			while (1)
			{
				cin >> Number;
				if (Number > Str->NumberOfHouses || Number<0)
				{
					cout << "There is no such home. Re-enter.\n";
					continue;
				}
				Str->AddHouse(Number);
				break;
			}
		}
		if (ch == 2)
		{
			while (1)
			{
				cout << "Enter the number of house to remove.";
				cin >> Number;
				if (Number > Str->NumberOfHouses || Number < 0)
				{
					cout << "There is no such home. Re-enter.\n";
					continue;
				}
				Str->DeleteHouse(Number);
				break;
			}
		}
		if (ch == 3)
		{
			while (1)
			{
				cout << "Enter the number of house to get data.";
				cin >> Number;
				if (Number > Str->NumberOfHouses || Number < 0)
				{
					cout << "There is no such home. Re-enter.\n";
					continue;
				}
				Str->GetHouseData(Number);
				break;
			}
		}
		if (ch == 4)
			Str->Print();
		if (ch == 5)
		{
			cout << "Enter the new name of the street - ";
			cin >> Name;
			Str->SetStreet(Name, Str->NumberOfHouses);
		}
		if (ch == 0)
			break;
	}
}

int main()
{
	using namespace std;
	string Name;
	int Number;
	cout << "Welcome to the design of streets\n";
	cout << "To start, enter the name of the street - ";
	cin >> Name;
	cout << "Very good. Now enter the number of houses - ";
	while (1)
	{
		cin >> Number;
		if (Number < 0)
		{
			cout << "Number of houses can not be negative. Re-enter. ";
			continue;
		}
		break;
	}
	Street *Str = new Street;
	Str->SetStreet(Name, Number);
	Str->SetHouses();
	cout << "The street was successfully created.\nNow you can control your street\n";
	DialogWithTheUser(Str);
	system("pause");
	return 0;
}
