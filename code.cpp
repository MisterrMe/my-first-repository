#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,N;
	unsigned char tmp;
	setlocale(LC_ALL, "rus");
	cout << "Введите N=";
	cin >> N;
	unsigned char *mass = new unsigned char[N];
	for (i = 0; i < N; i++)
	{
		cin >> mass[i];
	}

	for (i = N - 1; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		cout << "\n" << mass[i];
	}

	delete[] mass;
	system("pause");
	return 0;
}
