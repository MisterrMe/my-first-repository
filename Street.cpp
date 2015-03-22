#include "Street.h"
#include <iostream>

Street::Street()
{
	this->NumberOfHouses = 0;
	this->NameStreet = "";
}
Street::~Street()
{}

void Street::SetStreet(std::string NameStreet, int NumberOfHouses)
{
	this->NameStreet = NameStreet;
	this->NumberOfHouses = NumberOfHouses;
}

void Street::SetFirst()
{
	House *frst;
	frst = new House();
	frst->HomeNumber = 1;
	std::cout << "Enter the number of residents in first house.";
	while (1)
	{
		std::cin >> frst->NumberOfPeople;
		if (frst->NumberOfPeople < 0)
		{
			std::cout << "Number of people in first house can not be negative. Re-enter. ";
			continue;
		}
		break;
	}
	frst->next = frst;
	frst->prev = frst;
	last = frst;
	first = frst;
	this->NumberOfHouses = this->NumberOfHouses + 1;
}

void Street::SetHouses()
{
	int i;
	while (1)
	{
		switch (this->NumberOfHouses)
		{
		case 0:
			int a;
			while (1)
			{
				while (1)
				{
					std::cout << "You create an empty street.Confirm this? 1-Yes,0-No";
					std::cin >> a;
					if (a != 0 && a != 1)
					{
						std::cout << "Invalid input data. Re-enter.\n";
						continue;
					}
					if (a == 1 || a == 0)
						break;
				}
				if (a == 0)
				{
					std::cout << "Enter the new number of houses.";
					std::cin >> this->NumberOfHouses;
				}
				break;
			}
			if (a == 1)
				break;
			continue;

		case 1:
			SetFirst();
			this->NumberOfHouses = this->NumberOfHouses - 1;
			break;

		default:
			SetFirst();
			this->NumberOfHouses = this->NumberOfHouses - 1;
			for (i = 1; i < this->NumberOfHouses; i++)
			{
				iter = first;
				for (int j = 0; j < i; j++)
					iter = iter->next;
				House *tmp;
				tmp = new House;
				tmp->HomeNumber = i + 1;
				std::cout << "Enter the number of residents in " << i + 1 << " house.";
				while (1)
				{
					std::cin >> tmp->NumberOfPeople;
					if (tmp->NumberOfPeople < 0)
					{
						std::cout << "Number of people in " << i + 1 << " house can not be negative. Re-enter. ";
						continue;
					}
					break;
				}
				tmp->next = iter;
				tmp->prev = iter->prev;
				iter->prev->next = tmp;
				iter->prev = tmp;
			}
			break;
		}
		break;
	}
}

void Street::AddHouse(int n)
{
	if (this->NumberOfHouses == 0)
		SetFirst();
	else
	{
		int i;
		iter = first;
		for (i = 0; i < n; i++)
			iter = iter->next;
		House *tmp;
		tmp = new House;
		tmp->HomeNumber = n + 1;
		std::cout << "Enter the number of residents in " << n + 1 << " house.";
		while (1)
		{
			std::cin >> tmp->NumberOfPeople;
			if (tmp->NumberOfPeople < 0)
			{
				std::cout << "Number of people in " << n + 1 << " house can not be negative. Re-enter. ";
				continue;
			}
			break;
		}
		tmp->next = iter;
		tmp->prev = iter->prev;
		iter->prev->next = tmp;
		iter->prev = tmp;

		for (i = n; i < this->NumberOfHouses; i++)
		{
			iter->HomeNumber = iter->HomeNumber + 1;
			iter = iter->next;
		}
		this->NumberOfHouses = this->NumberOfHouses + 1;
	}
}

void Street::DeleteHouse(int n)
{
	int i;
	iter = first;
	for (i = 0; i < n - 1; i++)
		iter = iter->next;
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	iter = iter->next;
	for (i = n; i < this->NumberOfHouses; i++)
	{
		iter->HomeNumber = iter->HomeNumber - 1;
		iter = iter->next;
	}
	this->NumberOfHouses = this->NumberOfHouses - 1;
}

void Street::GetHouseData(int n)
{
	int i;
	iter = first;
	for (i = 0; i < n - 1; i++)
		iter = iter->next;
	std::cout << "The number of residents is " << iter->NumberOfPeople;
}

void Street::Print()
{
	int num = 0;
	std::cout << this->NameStreet << " street\n";
	iter = first;
	for (int i = 0; i < this->NumberOfHouses; i++)
	{
		num = num + iter->NumberOfPeople;
		std::cout << "House number " << iter->HomeNumber << ". Number of residents is " << iter->NumberOfPeople << "\n";
		iter = iter->next;
	}
	std::cout << "The total number of residents is " << num << "\n";
}
