#include "street.h"
#include <iostream>
#include <string>

Street::Street()
{
	this->NumberOfHouses = 0;
	this->NameStreet = "";
}

Street::~Street()
{}

const int Street::GetNumberOfHouses() const
{
	return this->NumberOfHouses;
}

const std::string Street::GetNameStreet() const
{
	return this->NameStreet;
}

void Street::SetStreet(const std::string NameStreet, const int NumberOfHouses)
{
	this->NameStreet = NameStreet;
	this->NumberOfHouses = NumberOfHouses;
}

void Street::SetHouses(int *Value)
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

void Street::AddHouse(const int n, const int p)
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
		for (int i = n; i < NumberOfHouses + 1; i++)
		{
			iter->setHomeNumber(iter->getHomeNumber() + 1);
			++iter;
		}
	}
	if (n == this->NumberOfHouses + 1)
		list.push_back(*src);
	if (n>1 && n<this->NumberOfHouses + 1)
	{
		iter = list.begin();
		for (int i = 0; i < n - 1; i++)
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

void Street::DeleteHouse(int n)
{
	iter = list.begin();
	for (int i = 0; i < n - 1; i++)
		++iter;
	iter = list.erase(iter);
	for (int i = n; i < NumberOfHouses; i++)
	{
		iter->setHomeNumber(iter->getHomeNumber() - 1);
		++iter;
	}
	this->NumberOfHouses = this->NumberOfHouses - 1;
}

void Street::GetHouseData(int n)
{
	int i, a;
	iter = list.begin();
	for (i = 0; i < n - 1; i++)
		++iter;
	a = iter->getNumberOfPeople();
	std::cout << "The number of residents is " << a;
}

void Street::Print()
{
	int num = 0;
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
