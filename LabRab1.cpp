// Win32Project3.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Win32Project4.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst; // текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING]; // Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING]; // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

HWND hEditRead1;
HWND hEditRead2;
HWND hEditResult;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPTSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: разместите код здесь.
    MSG msg;
    HACCEL hAccelTable;

    // Инициализация глобальных строк
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_WIN32PROJECT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT4));

    // Цикл основного сообщения:
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
// ФУНКЦИЯ: MyRegisterClass()
//
// НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT4));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT4);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassEx(&wcex);
}

//
// ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
// НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
// КОММЕНТАРИИ:
//
// В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
// создается и выводится на экран главное окно программы.
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

//
// ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
// НАЗНАЧЕНИЕ: обрабатывает сообщения в главном окне.
//
// WM_COMMAND - обработка меню приложения
// WM_PAINT -Закрасить главное окно
// WM_DESTROY - ввести сообщение о выходе и вернуться.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_CREATE:
        hEditRead1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 10, 35, 550, 20, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        hEditRead2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 10, 65, 550, 20, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        hEditResult = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 10, 95, 550, 20, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);
        CreateWindow(L"button", L"Объединить, ок-да?", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 210, 125, 150, 20, hWnd, (HMENU)2, NULL, NULL);
    case WM_COMMAND:
        wmId = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        if ((HIWORD(wParam) == 0) && (LOWORD(wParam) == 2))
        {
            char Box1[150], Box2[150], Box3[300], Adapter[150];
            int Set1[150], Set2[150], Set3[300], SizeOfBox1=0, SizeOfBox2=0, Fuse , SizeOfSet1 = 0, SizeOfSet2 = 0, SizeOfSet3, Counter = 0, SizeOfNumber=0, LocalNumber, SaveNumber=0;
            int i,j,l;
            SendMessage(hEditRead1, WM_GETTEXT, 150, (LPARAM)Box1);
            SendMessage(hEditRead2, WM_GETTEXT, 150, (LPARAM)Box2);

            for (i = 0; i < 150; i++)
            {
                if (Box1[i] == -52)
                    break;
                SizeOfBox1 = SizeOfBox1 + 1;
            }

            for (i = 0; i < 150; i++)
            {
                if (Box2[i] == -52)
                    break;
                SizeOfBox2 = SizeOfBox2 + 1;
            }

            for (i = 0; i<SizeOfBox1; i++) //Запись цифр из бокс1 в массив сет1
            {
                if (Box1[i] == 32)
                {
                    for (l = 0; l<150; l++)
                    {
                        Adapter[l] = 0;
                    }
                    for (j = Counter; j<i; j++)
                        Adapter[j - Counter] = Box1[j];
                    for (j = 0; j < 149; j++)
                    {
                        if (Adapter[j] == 0 && Adapter[j + 1] != 0)
                        {
                            for (l = j; l < 149; l++)
                                Adapter[l] = Adapter[l + 1];
                        }
                    }
                    Set1[SizeOfSet1] = atoi(Adapter);
                    Counter = i+2;
                    SizeOfSet1 = SizeOfSet1 + 1;
                    continue;
                }
                if (i == SizeOfBox1 - 1)
                {
                    for (l = 0; l<150; l++)
                    {
                        Adapter[l] = 0;
                    }
                    for (j = Counter; j<i; j++)
                        Adapter[j - Counter] = Box1[j];
                    for (j = 0; j < 149; j++)
                    {
                        if (Adapter[j] == 0 && Adapter[j + 1] != 0)
                        {
                            for (l = j; l < 149; l++)
                                Adapter[l] = Adapter[l + 1];
                        }
                    }
                    Adapter[i] = 0; Adapter[i + 1] = 0;
                    Set1[SizeOfSet1] = atoi(Adapter);
                    Counter = i + 2;
                    SizeOfSet1 = SizeOfSet1 + 1;
                    continue;
                }
                
            }

            Counter = 0;
            for (i = 0; i<SizeOfBox2; i++)  //Запись цифр из бокс2 в массив сет2
            {
                if (Box2[i] == 32)
                {
                    for (l = 0; l<150; l++)
                    {
                        Adapter[l] = 0;
                    }
                    for (j = Counter; j<i; j++)
                        Adapter[j - Counter] = Box2[j];
                    for (j = 0; j < 149; j++)
                    {
                        if (Adapter[j] == 0 && Adapter[j + 1] != 0)
                        {
                            for (l = j; l < 149; l++)
                                Adapter[l] = Adapter[l + 1];
                        }
                    }
                    Set2[SizeOfSet2] = atoi(Adapter);
                    Counter = i + 2;
                    SizeOfSet2 = SizeOfSet2 + 1;
                    continue;
                }
                if (i == SizeOfBox2 - 1)
                {
                    for (l = 0; l<150; l++)
                    {
                        Adapter[l] = 0;
                    }
                    for (j = Counter; j<i; j++)
                        Adapter[j - Counter] = Box2[j];
                    for (j = 0; j < 149; j++)
                    {
                        if (Adapter[j] == 0 && Adapter[j + 1] != 0)
                        {
                            for (l = j; l < 149; l++)
                                Adapter[l] = Adapter[l + 1];
                        }
                    }
                    Set2[SizeOfSet2] = atoi(Adapter);
                    Counter = i + 2;
                    SizeOfSet2 = SizeOfSet2 + 1;
                    continue;
                }
            }

            for (i = 0; i < SizeOfSet1; i++)   //Записываем элементы сет 1 и 2 в сет 3 без повторений
                Set3[i] = Set1[i];
            i = SizeOfSet1 - 1;
            for (j = 0; j < SizeOfSet2; j++)
            {
                Fuse = 0;
                for (l = 0; l < SizeOfSet1; l++)
                {
                    if (Set2[j] == Set1[l])
                        Fuse = 1;
                }
                if (Fuse == 1)
                    continue;
                if (Fuse == 0)
                {
                    i = i + 1;
                    Set3[i] = Set2[j];
                    continue;
                }
            }
            SizeOfSet3 = i;

            for (i = 0; i < SizeOfSet3+1; i++)  //Запись элементов сет3 в бокс 3 через пробел
            {
                LocalNumber = Set3[i];
                Counter = 0;
                while (1)
                {
                    Counter = Counter + 1;
                    LocalNumber = LocalNumber / 10;
                    if (LocalNumber == 0)
                        break;
                }
                LocalNumber = Set3[i];
                SaveNumber = SaveNumber + 2 * Counter;
                Box3[SaveNumber] = 0;
                for (j = 0; j < Counter; j++)
                {
                    Box3[SaveNumber-1]=0;
                    Box3[SaveNumber-2] = LocalNumber % 10 + 48;
                    SaveNumber = SaveNumber - 2;
                    LocalNumber = LocalNumber / 10;
                }
                SaveNumber = SaveNumber + 2 * Counter;
                Box3[SaveNumber] = ' ';
                if (i == SizeOfSet3)
                {
                    Box3[SaveNumber] = 0;
                }
                Box3[SaveNumber + 1] = 0;
                SaveNumber = SaveNumber + 2;
            }

            SendMessage(hEditResult, WM_SETTEXT, 300, (LPARAM)Box3);
            }
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
