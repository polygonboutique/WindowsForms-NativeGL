#pragma once
#include <Windows.h>

class LibClass
{
private:
	HWND hWnd;
	HDC  hDc;
	HINSTANCE hInstance;
public:
	LibClass();
	~LibClass();
	void SetHWND(HWND hwnd);
	void Init();
	void Update();
};