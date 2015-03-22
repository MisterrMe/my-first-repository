#ifndef __HOUSE_H
#define __HOUSE_H

class House
{
public:
	int HomeNumber;
	int NumberOfPeople;

	House();
	~House();

	House * next;
	House * prev;
	House * ptr;
};

#endif
