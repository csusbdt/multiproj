#include "stdafx.h"
#include "CCEGLView.h"
#include "main.h"
#include "MPApplication.h"
#include "MPKeyboard.h"

USING_NS_CC;

CCEGLView * eglView = NULL;

LRESULT CustomWindowProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL* pProcessed)
{
	if (message == WM_KEYUP)
	{
		if (wParam == 'A') MPKeyboard::aUp();
		else if (wParam == 'W') MPKeyboard::wUp();
		else if (wParam == 'S') MPKeyboard::sUp();
		else if (wParam == 'D') MPKeyboard::dUp();
	}
	else if (message == WM_KEYDOWN)
	{
		if (wParam == 'A') MPKeyboard::aDown();
		else if (wParam == 'W') MPKeyboard::wDown();
		else if (wParam == 'S') MPKeyboard::sDown();
		else if (wParam == 'D') MPKeyboard::dDown();
	}
	*pProcessed = false;
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    MPApplication app;
    eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("Multiproj");
    eglView->setFrameSize(1024, 768); // 4/3
    eglView->setFrameZoomFactor(1.0f);

	eglView->setWndProc(CustomWindowProc);

    return CCApplication::sharedApplication()->run();
}
