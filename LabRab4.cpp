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
	Vector(double x, double y)
	{
		this->x = x; this->y = y;
	}
	void Length()
	{
		this->len = sqrt(x*x + y*y);
	}
	virtual void PrintCoordinate()
	{
		cout << "\nx=" << x << " y=" << y;
	}
	virtual void PrintLenght()
	{
		cout << "\nlenght=" << len;
	}
};
class Vector3d : public Vector
{
	double z;
public:
	Vector3d(double x, double y, double z) : Vector(x, y)
	{
		this->z = z;
	}
	void PrintCoordinate()
	{
		Vector::PrintCoordinate();
		cout << " z=" << z;
	}
	void PrintLenght()
	{
		cout << "\nlenght=" << sqrt(x*x + y*y + z*z) << "\n";
	}
};
int main(int argc, char* argv[])
{
	Vector p1(1, 2);
	Vector3d p2(1, 2, 3);
	Vector *pp;
	pp = &p1;
	pp->PrintCoordinate();
	pp->Length();
	pp->PrintLenght();
	pp = &p2;
	pp->PrintCoordinate();
	pp->PrintLenght();
	system("pause");
	return 0;
}
