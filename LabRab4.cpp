// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

class Vector 
{
protected:
	double x, y; 
	double len;
public:
	Vector (double x, double y)
	{
		this->x = x; this->y = y;
	}

	void Length()
	{
		this->len = sqrt(x*x + y*y);
	}

	void PrintCoordinate()
	{
		cout << "\nx=" << x << " y=" << y;
	}

	void PrintLenght()
	{
		cout << "\nlenght=" << len;
	}
};

class Vector3d : protected Vector 
{
	double z;
public:
	Vector3d(double x, double y, double z) : Vector(x, y)
	{
		this->z = z;
	}
	void Print()
	{
		Vector::PrintCoordinate(); 
		cout << " z=" << z;
		cout << "\nlenght=" << sqrt(x*x+y*y+z*z);
	}
};

int main(int argc, char* argv[])
{
	Vector p1(1, 2);
	Vector3d p2(3, 4, 5);
	Vector *pp1;
	Vector3d *pp2;
	pp1 = &p1; 
	pp1->PrintCoordinate(); 
	pp1->Length();
	pp1->PrintLenght();
	pp2 = &p2;
	pp2->Print();
	system("pause");
	return 0;
}
