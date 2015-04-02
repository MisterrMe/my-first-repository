// Win32Project5.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "MyGrahics.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT5, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT5));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT5));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT5);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

class Figure
{
protected: 
	int x, y; // Координаты геометр центра
	int R; // Расстояние от центра до вершины
	int Ang; // Угловое положение в градусах
	int VAng; // Скорость вращения
	int V; // Скорость движения
	int Napr; // Направление движения 0 - вертикально 1- горизонтально
	COLORREF col;
	HWND hWnd;
	int N_Reg; // Направление перемещение (1 - вправо или вниз; -1 - влево или вверх)
public:
	Figure(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd); // Конструктор
	virtual void step();// Меняет положение фигура за 1 такт таймера
	virtual void draw(int Reg) = 0;// Рисование (стирание) фигуры
};

Figure::Figure(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd)
{
	this->R = R;
	this->VAng = VAng;
	this->V = V;
	this->Napr = Napr;
	this->col = col;
	this->hWnd = hWnd;
	Ang = 0;
	N_Reg = 1; // Координаты увеличиваются
	RECT rect; // Размеры окна
	GetClientRect(hWnd, &rect); // Получаем размеры окна
	// Начальное положение фигуры в центре окна
	x = rect.right / 2;
	y = rect.bottom / 2;
}

void Figure::step()
{
	Ang += VAng;
	if (Ang >= 360) Ang -= 360;
	RECT rect;
	GetClientRect(hWnd, &rect);

	if (Napr == 1) // Движение горизонтально меняется x
	{
		x += V*N_Reg;
		if (N_Reg == 1) // Движемся вправо
		{
			if (x + R >= rect.right) // Достигли правой границы окна
				N_Reg = -1; // Меняем направление движения
		}
		else //  Движемся влево
		{
			if (x - R <= 0) // Достигли левой границы
				N_Reg = 1; // Меняем направление движения
		}
	}
	else // Движение вертикально меняется y
	{
		y += V*N_Reg;
		if (N_Reg == 1) // Движемся вниз
		{
			if (y + R >= rect.bottom) // Достигли нижней границы окна
				N_Reg = -1; // Меняем направление движения
		}
		else //  Движемся вверх
		{
			if (y - R <= 0) // Достигли верхней границы
				N_Reg = 1; // Меняем направление движения
		}
	}
}

// МНОГОУГОЛЬНИК(188-244)

class MyPolygon : public Figure
{
protected:
	int N; // Число вершин
	POINT *p; // Массив координат вершин
public:
	MyPolygon(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd, int N); // Заголовок конструктора 
	void step(); // Метод дополнительно считает новые координаты вершин
	void draw(int Reg); // Метод рисования фигуры
};

MyPolygon::MyPolygon(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd, int N) : Figure(R, VAng, V, Napr, col, hWnd)
{

	this->N = N;
	p = new POINT[N]; // Создаем массив координат вершин
	double A = Ang*M_PI / 180; // Угол в градусах переводим в радианы
	double A1 = 2 * M_PI / N; // Угол между направлениями на соседние вершины из центра фигуры
	for (int i = 0; i<N; i++, A += A1)
	{
		p[i].x = x + R*cos(A);
		p[i].y = y - R*sin(A);
	}
}

void MyPolygon::step() // Метод дополнительно считает новые координаты вершин
{
	Figure::step(); // Вызов метода базового класса
	// Расчет координат вершин многоугольника
	double A = Ang*M_PI / 180; // Угол в градусах переводим в радианы
	double A1 = 2 * M_PI / N; // Угол между направлениями на соседние вершины из центра фигуры
	for (int i = 0; i<N; i++, A += A1)
	{
		p[i].x = x + R*cos(A);
		p[i].y = y - R*sin(A);
	}
}

void MyPolygon::draw(int Reg) // Метод рисования фигуры
{
	HPEN pen;
	if (Reg == 1) // Режим рисования фигуры
		pen = CreatePen(PS_SOLID, 1, col);
	else // Режим стирания (белое перо)
		pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HDC hdc;
	hdc = GetDC(hWnd);
	SelectObject(hdc, pen); // Загрузка пера
	MoveToEx(hdc, p[0].x, p[0].y, 0); // Графический курсор в первую вершину
	for (int i = 1; i<N; i++)
		LineTo(hdc, p[i].x, p[i].y);
	LineTo(hdc, p[0].x, p[0].y); // Последнею вершину соединяем с первой
	ReleaseDC(hWnd, hdc);
	DeleteObject(pen); // Удаляем перо
}

// ТРЕУГОЛЬНИК(247-297)
class MyTreug : public Figure
{
protected:
	POINT *p; // Массив координат вершин
public:
	MyTreug(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd); // Заголовок конструктора 
	void step(); // Метод дополнительно считает новые координаты вершин
	void draw(int Reg); // Метод рисования фигуры
};

MyTreug::MyTreug(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd) : Figure(R, VAng, V, Napr, col, hWnd)
{
	p = new POINT[3]; // Создаем массив координат вершин
	double A = Ang*M_PI / 180; // Угол в градусах переводим в радианы
	double A1 = M_PI / 2; // Угол между направлениями на соседние вершины из центра фигуры
	for (int i = 0; i<3; i++, A += A1)
	{
		p[i].x = x + R*cos(A);
		p[i].y = y - R*sin(A);
	}
}

void MyTreug::step() // Метод дополнительно считает новые координаты вершин
{
	Figure::step(); // Вызов метода базового класса
	double A = Ang*M_PI / 180; // Угол в градусах переводим в радианы
	double A1 = M_PI / 2; // Угол между направлениями на соседние вершины из центра фигуры
	for (int i = 0; i<3; i++, A += A1)
	{
		p[i].x = x + R*cos(A);
		p[i].y = y - R*sin(A);
	}
}

void MyTreug::draw(int Reg) // Метод рисования фигуры
{
	HPEN pen;
	if (Reg == 1) // Режим рисования фигуры
		pen = CreatePen(PS_SOLID, 1, col);
	else // Режим стирания (белое перо)
		pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HDC hdc;
	hdc = GetDC(hWnd);
	SelectObject(hdc, pen); // Загрузка пера
	MoveToEx(hdc, p[0].x, p[0].y, 0); // Графический курсор в первую вершину
	for (int i = 1; i<3; i++)
		LineTo(hdc, p[i].x, p[i].y);
	LineTo(hdc, p[0].x, p[0].y); // Последнею вершину соединяем с первой
	ReleaseDC(hWnd, hdc);
	DeleteObject(pen); // Удаляем перо
}

//ПАРАЛЛЕЛОГРАММ
class MyParall : public Figure
{
protected:
	POINT *p; // Массив координат вершин
public:
	MyParall(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd); // Заголовок конструктора 
	void step(); // Метод дополнительно считает новые координаты вершин
	void draw(int Reg); // Метод рисования фигуры
};

MyParall::MyParall(int R, int VAng, int V, int Napr, COLORREF col, HWND hWnd) : Figure(R, VAng, V, Napr, col, hWnd)
{
	p = new POINT[3]; // Создаем массив координат вершин
	double A = Ang*M_PI / 180; // Угол в градусах переводим в радианы
	double A0 = A + M_PI / 6;
	double A1 = M_PI; // Угол между направлениями на соседние вершины из центра фигуры
	for (int i = 0; i<2; i++, A += A1)
	{
		p[2 * i].x = x + R*0.8*cos(A);
		p[2 * i].y = y - R*0.8*sin(A);
	}
	for (int i = 0; i<2; i++, A0 += A1)
	{
		p[2 * i + 1].x = x + (R) * cos(A0);
		p[2 * i + 1].y = y - (R) * sin(A0);
	}
}

void MyParall::step() // Метод дополнительно считает новые координаты вершин
{
	Figure::step(); // Вызов метода базового класса
	double A = Ang*M_PI / 180; // Угол в градусах переводим в радианы
	double A0 = A+M_PI/6;
	double A1 = M_PI; // Угол между направлениями на соседние вершины из центра фигуры
	for (int i = 0; i<2; i++, A += A1)
	{
		p[2 * i].x = x + R*0.9*cos(A);
		p[2 * i].y = y - R*0.9*sin(A);
	}
	for (int i = 0; i<2; i++, A0 += A1)
	{
		p[2 * i + 1].x = x + (1.1*R) * cos(A0);
		p[2 * i + 1].y = y - (1.1*R) * sin(A0);
	}
}


void MyParall::draw(int Reg) // Метод рисования фигуры
{
	HPEN pen;
	if (Reg == 1) // Режим рисования фигуры
		pen = CreatePen(PS_SOLID, 1, col);
	else // Режим стирания (белое перо)
		pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HDC hdc;
	hdc = GetDC(hWnd);
	SelectObject(hdc, pen); // Загрузка пера
	MoveToEx(hdc, p[0].x, p[0].y, 0); // Графический курсор в первую вершину
	for (int i = 1; i<4; i++)
		LineTo(hdc, p[i].x, p[i].y);
	LineTo(hdc, p[0].x, p[0].y); // Последнею вершину соединяем с первой
	ReleaseDC(hWnd, hdc);
	DeleteObject(pen); // Удаляем перо
}

Figure *pF[9];

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 20, 0);
		pF[0] = new MyPolygon(110, -4, 12, 0, RGB(250, 50, 250), hWnd, 5);
		pF[1] = new MyPolygon(150, 4, 10, 0, RGB(50, 250, 250), hWnd, 6);
		pF[2] = new MyPolygon(70, 6, 8, 1, RGB(250, 250, 50), hWnd, 7);
		pF[3] = new MyTreug(40, 10, 13, 1, RGB(250, 150, 50), hWnd);
		pF[4] = new MyTreug(60, -8, 12, 0, RGB(50, 250, 150), hWnd);
		pF[5] = new MyTreug(80, -10, 8, 1, RGB(150, 50, 250), hWnd);
		pF[6] = new MyParall(80, -1, 4, 1, RGB(50, 50, 50), hWnd);
		pF[7] = new MyParall(60, 2, 6, 0, RGB(150, 150, 0), hWnd);
		pF[8] = new MyParall(40, 1, 10, 1, RGB(150, 150, 250), hWnd);

		break;
	case WM_TIMER:
		for (int i = 0; i<9; i++)
		{
			pF[i]->draw(0);
			pF[i]->step();
			pF[i]->draw(1);
		}
		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: добавьте любой код отрисовки...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
