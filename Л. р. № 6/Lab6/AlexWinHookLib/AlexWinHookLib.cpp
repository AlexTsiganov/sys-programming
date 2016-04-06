// AlexWinHookLib.cpp: определ€ет экспортированные функции дл€ приложени€ DLL.
//
#include "stdafx.h"
#include <iostream>
#include "AlexWinHookLib.h"
#include <Windows.h>

using namespace std;
static HHOOK mMouseHook, mKeyboardHook;
static onAlexWinHook_keyboard mcbHook_keyboard;
static onAlexWinHook_mouse mcbHook_mouse;

	// хук дл€ клавиатуры
	LRESULT CALLBACK CAlexWinHookLib::CBKeyboard(int nCode, WPARAM wParam, LPARAM lParam)
	{
		// проверка на то, что произошло именно нажатие клавиш
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
		{
			//получаем структуру, описывающую нажатую клавишу
			PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;
			//извлекаем и выводим коде клавиши
			// отдельна€ обработка дл€ VK_PRIOR (page up)
			DWORD d = pKey->vkCode;
			mcbHook_keyboard(d);
		}
		return CallNextHookEx(mKeyboardHook, nCode, wParam, lParam);
	}

	//хук дл€ мышки
	LRESULT CALLBACK CAlexWinHookLib::CBMouse(int nCode, WPARAM wParam, LPARAM lParam)
	{
		MSLLHOOKSTRUCT * pMouseStruct = (MSLLHOOKSTRUCT *)lParam;

		if (nCode == 0 && pMouseStruct && wParam) {
				mcbHook_mouse(wParam);
		}
		return CallNextHookEx(mKeyboardHook, nCode, wParam, lParam);

	}

	void CAlexWinHookLib::keyboardHook(onAlexWinHook_keyboard hook)
	{
		mcbHook_keyboard = hook;
		// получаем дескриптор модул€, запустившего процесс
		HMODULE hInstance = GetModuleHandle(NULL);
		mKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, CBKeyboard, hInstance, NULL);
		//ожидает получение сообщени€ из очереди сообщений потока.
		MSG msg;
		GetMessage(&msg, 0, 0, 0);
		//отв€зывает mKeyboardHook
		UnhookWindowsHookEx(mKeyboardHook);
	}

	// устанавливает хук на отслеживание нажати€ мыши
	void CAlexWinHookLib::mouseHook(onAlexWinHook_mouse hook)
	{
		mcbHook_mouse = hook;
		// получаем дескриптор модул€, запустившего процесс
		HMODULE hInstance = GetModuleHandle(NULL);

		mMouseHook = SetWindowsHookEx(WH_MOUSE_LL, CBMouse, hInstance, NULL);

		//ожидает получение сообщени€ из очереди сообщений потока.
		MSG msg;
		GetMessage(&msg, NULL, NULL, NULL);

		//отв€зывает mMouseHook
		UnhookWindowsHookEx(mMouseHook);

	}
