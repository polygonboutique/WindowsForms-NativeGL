#include "LibClass.h"
#include <iostream>
#include <GL/gl.h>

static PIXELFORMATDESCRIPTOR GetPixelFormat()
{
	PIXELFORMATDESCRIPTOR result = {};
	result.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	result.nVersion = 1;
	result.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	result.iPixelType = PFD_TYPE_RGBA;
	result.cColorBits = 32;
	result.cDepthBits = 24;
	result.cStencilBits = 8;
	result.cAuxBuffers = 0;
	result.iLayerType = PFD_MAIN_PLANE;
	return result;
}

LibClass::LibClass()
{
}


LibClass::~LibClass()
{
}

void LibClass::SetHWND(HWND hwnd)
{
	hWnd = hwnd;
}

void LibClass::Update()
{
	glClearColor(0.2, 1, 0.5, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(hDc);
}

void LibClass::Init()
{

	printf(" - - - Init - - - - \n");

	// use hwnd and hook into it

	if (!hWnd)
	{
		printf("Could create window editor win32. Missing hwnd.\n");
		return;
	}

	hDc = GetDC(hWnd);
	if (!hDc) {
		printf("Could create window editor win32. Missing Hdc.\n");
		return;
	}

	PIXELFORMATDESCRIPTOR pfd = GetPixelFormat();
	int pixelFormat = ChoosePixelFormat(hDc, &pfd);
	if (pixelFormat)
	{
		if (!SetPixelFormat(hDc, pixelFormat, &pfd))
		{
			printf("Failed setting pixel format!\n");
			return;
		}
	}
	else
	{
		printf("Failed choosing pixel format!\n");
		return;
	}


	HGLRC hrc = wglCreateContext(hDc);
	if (hrc)
	{
		if (!wglMakeCurrent(hDc, hrc))
		{
			printf("Failed setting OpenGL context!\n");
		}
	}
	else
	{
		printf("Failed creating OpenGL context!!\n");
	}

}

