// AlexWinHookLib.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//
#include "stdafx.h"
#include <iostream>
#include "AlexWinHookLib.h"
#include <Windows.h>

using namespace std;
static HHOOK mMouseHook, mKeyboardHook;
static onAlexWinHook_keyboard mcbHook_keyboard;
static onAlexWinHook_mouse mcbHook_mouse;

	// ��� ��� ����������
	LRESULT CALLBACK CAlexWinHookLib::CBKeyboard(int nCode, WPARAM wParam, LPARAM lParam)
	{
		// �������� �� ��, ��� ��������� ������ ������� ������
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
		{
			//�������� ���������, ����������� ������� �������
			PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;
			//��������� � ������� ���� �������
			// ��������� ��������� ��� VK_PRIOR (page up)
			DWORD d = pKey->vkCode;
			mcbHook_keyboard(d);
		}
		return CallNextHookEx(mKeyboardHook, nCode, wParam, lParam);
	}

	//��� ��� �����
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
		// �������� ���������� ������, ������������ �������
		HMODULE hInstance = GetModuleHandle(NULL);
		mKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, CBKeyboard, hInstance, NULL);
		//������� ��������� ��������� �� ������� ��������� ������.
		MSG msg;
		GetMessage(&msg, 0, 0, 0);
		//���������� mKeyboardHook
		UnhookWindowsHookEx(mKeyboardHook);
	}

	// ������������� ��� �� ������������ ������� ����
	void CAlexWinHookLib::mouseHook(onAlexWinHook_mouse hook)
	{
		mcbHook_mouse = hook;
		// �������� ���������� ������, ������������ �������
		HMODULE hInstance = GetModuleHandle(NULL);

		mMouseHook = SetWindowsHookEx(WH_MOUSE_LL, CBMouse, hInstance, NULL);

		//������� ��������� ��������� �� ������� ��������� ������.
		MSG msg;
		GetMessage(&msg, NULL, NULL, NULL);

		//���������� mMouseHook
		UnhookWindowsHookEx(mMouseHook);

	}
