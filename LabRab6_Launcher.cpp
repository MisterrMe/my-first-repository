#include <conio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;
int main()
{
	HANDLE hEvent;
	setlocale(LC_ALL, "rus");
	// Открываем объект- событие,созданное в другом приложении
	hEvent = OpenEvent(EVENT_ALL_ACCESS,TRUE,L"MyEvent1");
	if (hEvent == 0)
	{
		cout << "Ошибка открытия объекта- события, созданного в другом приложе-нии";
		_getch();
		return 0;
	}
	cout << "Для запуска потоков в другом приложении нажмите любую клавишу" << endl;
	_getch();
	SetEvent(hEvent); // Объект-событие свободен
	cout << "Для завершения потоков в другом приложении нажмите любую клавишу" << endl;
	_getch();
	ResetEvent(hEvent); // Объект-событие занят
	cout << "Для выхода из приложения нажмите любую клавишу" << endl;
	_getch();
	return 0;
}
