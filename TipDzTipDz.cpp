// Street.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

class House
{
private:
	int HomeNumber;
	int NumberOfPeople;
public:
	House()
	{
		HomeNumber = 0;
		NumberOfPeople = 0;
	}

	~House()
	{}

	House(const House &src)
	{
		HomeNumber = src.HomeNumber;
		NumberOfPeople = src.NumberOfPeople;
	}

	const int getHomeNumber() const
	{ 
		return this->HomeNumber;
	};

	void setHomeNumber(int a)
	{
		this->HomeNumber = a;
	};

	const int getNumberOfPeople() const
	{
		return this->NumberOfPeople;
	};

	void setNumberOfPeople(int a)
	{
		this->NumberOfPeople = a;
	}

	House &operator=(const House &src)
	{
		this->HomeNumber = src.HomeNumber;
		this->NumberOfPeople = src.NumberOfPeople;
		return *this;
	}

	int operator==(const House &src) const
	{
		if (this->HomeNumber != src.HomeNumber) return 0;
		if (this->NumberOfPeople != src.NumberOfPeople) return 0;
		return 1;
	}
};

class Street
{
private:
	int NumberOfHouses;
	std::string NameStreet;
public:
	std::list<House> list;
	std::list<House>::iterator iter;
	Street()
	{
		this->NumberOfHouses = 0;
		this->NameStreet = "";
	}

	~Street()
	{}
	
	const int GetNumberOfHouses() const
	{
		return this->NumberOfHouses;
	}

	const std::string GetNameStreet() const
	{
		return this->NameStreet;
	}

	void SetStreet(const std::string NameStreet, const int NumberOfHouses)
	{
		this->NameStreet = NameStreet;
		this->NumberOfHouses = NumberOfHouses;
	}

	void SetHouses(int *Value)
	{
		for (int i = 0; i < this->NumberOfHouses; i++)
		{
			House *src;
			src = new House();
			src->setHomeNumber(i + 1);
			src->setNumberOfPeople(Value[i]);
			list.push_back(*src);
			delete src;
		}
	}

	void AddHouse(const int n, const int p)
	{
		House *src;
		src = new House();
		src->setHomeNumber(n);
		src->setNumberOfPeople(p);
		if (n == 1)
		{
			list.push_front(*src);
			iter = list.begin();
			++iter;
			for (int i = n; i < NumberOfHouses+1; i++)
			{
				iter->setHomeNumber(iter->getHomeNumber() + 1);
				++iter;
			}
		}
		if (n == this->NumberOfHouses+1)
			list.push_back(*src);
		if (n>1 && n<this->NumberOfHouses+1)
		{
			iter = list.begin();
			for (int i = 0; i < n-1; i++)
				++iter;
			list.insert(iter, *src);
			for (int i = n; i < NumberOfHouses + 1; i++)
			{
				iter->setHomeNumber(iter->getHomeNumber() + 1);
				++iter;
			}
		}
		this->NumberOfHouses = this->NumberOfHouses + 1;
		delete src;
	}

	void DeleteHouse(int n)
	{
		iter = list.begin();
		for (int i = 0; i < n-1; i++)
			++iter;
		iter = list.erase(iter);
		for (int i = n; i < NumberOfHouses; i++)
		{
			iter->setHomeNumber(iter->getHomeNumber() - 1);
			++iter;
		}
		this->NumberOfHouses = this->NumberOfHouses - 1;
	}

	void GetHouseData(int n)
	{
		int i,a;
		iter = list.begin();
		for (i = 0; i < n - 1; i++)
			++iter;
		a = iter->getNumberOfPeople();
		std::cout << "The number of residents is " << a;
	}

	void Print()
	{
		int num=0;
		std::cout << this->NameStreet << " street\n";
		iter = list.begin();
		for (int i = 0; i < this->NumberOfHouses; i++)
		{
			int a = iter->getNumberOfPeople();
			num = num + a;
			std::cout << "House number " << iter->getHomeNumber() << ". Number of residents is " << iter->getNumberOfPeople() << "\n";
			++iter;
 		}
		std::cout << "The total number of residents is " << num << "\n";
		std::cout << "The totel number of houses is " << this->NumberOfHouses << "\n";
	}
};

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
				if (Number > Str->GetNumberOfHouses()+1 || Number<1)
				{
					cout << "There is no such home. Re-enter.\n";
					continue;
				}

				cout << "Enter the number of residents in " << Number  << " house.";
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
				Str->AddHouse(Number,people);
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
				std::cout << "Number of people in " << i+1 << " house can not be negative. Re-enter. ";
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
