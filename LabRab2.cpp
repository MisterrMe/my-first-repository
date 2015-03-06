// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class SC
{
private:
char name;
int number;
public:

void Set_name(char inname)
{
name=inname;
}

void Set_number(int innumber)
{
number=innumber;
}

int check(int SN)
{
int arg=0;
if (number<=SN)
arg=1;
return arg;
}

void print()
{
printf("%c\n", name);
}

};

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL,"Rus");
char name[7];
int number[7],arg[7];
int i,SN;

name[0]='A';
name[1]='B';
name[2]='C';
name[3]='D';
name[4]='E';
name[5]='F';
name[6]='G';

for (i=0;i<7;i++)   
	number[i]=i+1;

SC * C = new SC[7];
for (i=0;i<7;i++)     //задание элементов
{
	C[i].Set_name(name[i]);
	C[i].Set_number(number[i]);
}

cout<<"Введите класс защищенности";
cin>>SN;

for (i=0;i<7;i++)   //check
	arg[i]=C[i].check(SN);

for(i=0;i<7;i++)    //print
{
	if (arg[i]==1)
		C[i].print();
}

delete [] C;
system("pause");
return 0;
}
