#ifndef __STREET_H
#define __STREET_H

#include "House.h"
#include <string>

class Street
{
public:
	int NumberOfHouses;
	std::string NameStreet;

	Street();
	~Street();

	void SetStreet(std::string NameStreet, int NumberOfHouses);
	void SetFirst();
	void SetHouses();
	void AddHouse(int n);
	void DeleteHouse(int n);
	void GetHouseData(int n);
	void Print();

	House * last;
	House * first;
	House * iter;
};

#endif
