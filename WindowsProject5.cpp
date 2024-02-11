#include <windows.h>
#include <tchar.h>
#include <string>
#include "resource.h"
//прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassWindow[] = TEXT("dz2pp"); /* Имя класса окна */
INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;
	/* 1. Определение класса окна  */
	wcl.cbSize = sizeof(wcl);	// размер структуры WNDCLASSEX 
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// окно сможет получать сообщения о двойном щелчке (DBLCLK)
	wcl.lpfnWndProc = WindowProc;	// адрес оконной процедуры
	wcl.cbClsExtra = 0;		// используется Windows 
	wcl.cbWndExtra = 0; 	// используется Windows 
	wcl.hInstance = hInst;	// дескриптор данного приложения
	wcl.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)); // иконка загружается из ресурсов приложения	
	wcl.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1));	// курсор загружается из ресурсов приложения	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//заполнение окна белым цветом			
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна
	/*  2. Регистрация класса окна  */
	if (!RegisterClassEx(&wcl))
		return 0;	// при неудачной регистрации - выход
	/*  3. Создание окна  */
	// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		szClassWindow,	// имя класса окна
		TEXT("Final"),	// заголовок окна
		/* Заголовок, рамка, позволяющая менять размеры, системное меню,
			кнопки развёртывания и свёртывания окна  */
		WS_OVERLAPPEDWINDOW,	// стиль окна
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		CW_USEDEFAULT,	// ширина окна
		CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL);		// указатель на область данных приложения
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	const _TCHAR str1[] = TEXT("BMW AG — немецкий производитель автомобилей, мотоциклов, двигателей, а также велосипедов. Более 45 % акций принадлежит семье Квандт. Председателем правления компании является Оливер Ципсе. Главный дизайнер — Йозеф Кабан.");
	const _TCHAR str2[] = TEXT("Mercedes-Benz — торговая марка и одноимённая компания — производитель легковых автомобилей премиального класса, грузовых автомобилей, автобусов и других транспортных средств, входящая в состав немецкого концерна «Mercedes-Benz Group». Является одним из самых узнаваемых автомобильных брендов во всём мире.");
	const _TCHAR str3[] = TEXT("Audi AG — немецкая автомобилестроительная компания в составе концерна Volkswagen Group, специализирующаяся на выпуске автомобилей под маркой Audi. Штаб-квартира расположена в городе Ингольштадт. Девиз — Vorsprung durch Technik. Объём производства в 2016 году составил около 1 903 259 автомобилей.");
	TCHAR buffer[100];
	const int symb = (strlen(str1) + strlen(str2) + strlen(str3)) / 3;
	wsprintf(buffer, _TEXT("%d Всего слов"), symb);
	switch (uMessage)
	{
	case WM_CREATE:
	{
		MessageBox(
			0,
			str1,
			TEXT("BMW"),
			MB_OK | MB_ICONINFORMATION
		);
		MessageBox(
			0,
			str2,
			TEXT("Mercedes-Benz"),
			MB_OK | MB_ICONINFORMATION
		);
		MessageBox(
			0,
			str3,
			buffer,
			MB_OK | MB_ICONINFORMATION
		);
	}
	return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}