// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

class Vectors
{
	double *v;
	int n;

public:

	Vectors()                    //конструктор без параметров, задающий пустой вектор (число элементов равно 0) (в нашем случае два пустых вектора)
	{
		v = 0;
		n = 0;
	}

	Vectors(double *p, int n)   //конструктор, создающий объект вектор на основе обычного одномерного массива размерности n(в нашем случае два вектора)
	{
		this->n = n;
		this->v = new double[n];
		for (int i = 0; i < n; i++)
			this->v[i] = p[i];
	}

	void print()                  //печать элемента класса Vectors
	{
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << "\n";
	}

	friend Vectors & operator +(Vectors& V1, Vectors& V2);
};

	Vectors & operator +(Vectors& V1, Vectors& V2)
	{
		Vectors Vr;
		Vr.n = V1.n;
		Vr.v = new double[Vr.n];
		for (int i = 0; i < V1.n; i++)
			Vr.v[i] = V1.v[i] + V2.v[i];
		return Vr;
	}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	int i, j;
	int n = rand() % 5 + 2; //задаю значение размера массива от 2 до 7

	double **p = new double*[2];  //выделяю память под 2 массива размерностью n
	for (j = 0; j < 2; j++)
		p[j] = new double[n];

	for (j = 0; j < 2; j++)  //задаю значения жлементов массивов случайными числами от 0 до 9
	{
		for (i = 0; i < n; i++)
			p[j][i] = rand() % 90 +10;
	}

	Vectors * V = new Vectors[2];  //выделяю память под два элемента класса Vectors (и один результирующий)
	for (j = 0; j < 2; j++)
		V[j]=Vectors(p[j],n);      //задаю два элемента класса Vectors

	for (j = 0; j < 2; j++)  //печать координат исходных векторов
		V[j].print();

	Vectors Vr;
	Vr = V[0] + V[1];
	Vr.print();
	
	delete[] V;          //очистка памяти
	for (i=0;i<2;i++)
		delete[] p[i];
	delete[] p;

	system("pause");
	return 0;
}

