#include "street.h"
#include <iostream>
#include <string>

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
			cout << "Enter the number of house in front of which will be new.\nIf you add the last house-enter a number one greater than the number of homes\n(if the house is not the last, the numbering of the remaining will be shifted)\n";
			while (1)
			{
				cin >> Number;
				if (Number > Str->GetNumberOfHouses() + 1 || Number<1)
				{
					cout << "There is no such home. Re-enter.\n";
					continue;
				}

				cout << "Enter the number of residents in " << Number << " house.";
				int people;
				while (1)
				{
					cin >> people;
					if (people < 0)
					{
						cout << "Number of people in " << Number + 1 << " house can not be negative. Re-enter. ";
						continue;
					}
					break;
				}
				Str->AddHouse(Number, people);
				break;
			}
		}
		if (ch == 2)
		{
			while (1)
			{
				cout << "Enter the number of house to remove.";
				cin >> Number;
				if (Number > Str->GetNumberOfHouses() || Number < 0)
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
				if (Number > Str->GetNumberOfHouses() || Number < 0)
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
			Str->SetStreet(Name, Str->GetNumberOfHouses());
		}
		if (ch == 0)
			break;
	}
}

void Create(Street *Str)
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
		if (Number == 0)
		{
			int a;
			while (1)
			{
				cout << "You create an empty street.Confirm this? 1-Yes,0-No";
				cin >> a;
				if (a != 0 && a != 1)
				{
					cout << "Invalid input data. Re-enter.\n";
					continue;
				}
				if (a == 1 || a == 0)
					break;
			}
			if (a == 0)
			{
				cout << "Enter the new number of houses.";
				continue;
			}
			if (a == 1)
				break;
		}
		if (Number > 0)
		{
			break;
		}
		continue;
	}
	int *value = new int[Number];
	for (int i = 0; i < Number; i++)
	{
		cout << "Enter the number of residents in " << i + 1 << " house.";
		while (1)
		{
			cin >> value[i];
			if (value[i] < 0)
			{
				std::cout << "Number of people in " << i + 1 << " house can not be negative. Re-enter. ";
				continue;
			}
			break;
		}
	}
	Str->SetStreet(Name, Number);
	Str->SetHouses(value);
	cout << "The street was successfully created.\nNow you can control your street\n";
	delete[] value;
}

int main()
{
	using namespace std;
	Street *Str = new Street;
	Create(Str);
	DialogWithTheUser(Str);
	return 0;
}
