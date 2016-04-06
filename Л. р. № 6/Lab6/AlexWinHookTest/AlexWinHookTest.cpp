// AlexWinHookTest.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "AlexWinHookLib.h"
#include <iostream>


using namespace std;

void alexWinHook_mouse(WPARAM wParam)
{
	LPCTSTR key;
	switch (wParam) {

	case WM_LBUTTONUP:
		key = L"WM_LBUTTONUP";
		break;
	case WM_LBUTTONDOWN:
		key = L"WM_LBUTTONDOWN";
		break;
	case WM_RBUTTONUP:
		key = L"WM_RBUTTONUP";
		break;
	case WM_RBUTTONDOWN:
		key = L"WM_RBUTTONDOWN";
		break;
	default:
		return;
	}

	MessageBox(NULL, key, L"Mouse clicked", NULL);
}

void alexWinHook_keyboard(DWORD keyCode)
{
	LPCTSTR key;
	if (keyCode == VK_F1) // дл€ примера определение нажати€ на кнопку F1
		key = L"F1";
	else
		key = L"Some botton click";
		
	MessageBox(NULL, key, L"Keybord pressed", NULL);
}

int main()
{
	cout << "Windows hook Keyboard, mouse." << endl;
	CAlexWinHookLib l = CAlexWinHookLib();
	//l.keyboardHook(alexWinHook_keyboard);
	l.mouseHook(alexWinHook_mouse);
    return 0;
}

