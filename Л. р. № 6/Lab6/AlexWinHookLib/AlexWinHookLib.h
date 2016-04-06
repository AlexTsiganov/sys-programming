// ����������� ���� ���� ifdef - ��� ����������� ����� �������� ��������, ���������� ��������� 
// �������� �� ��������� DLL. ��� ����� ������ DLL �������������� � �������������� ������� ALEXWINHOOKLIB_EXPORTS,
// � ��������� ������. ���� ������ �� ������ ���� ��������� � �����-���� �������
// ������������ ������ DLL. ��������� ����� ����� ������ ������, ��� �������� ����� �������� ������ ����, ����� 
// ������� ALEXWINHOOKLIB_API ��� ��������������� �� DLL, ����� ��� ������ DLL ����� �������,
// ������������ ������ ��������, ��� ����������������.
#ifdef ALEXWINHOOKLIB_EXPORTS
#define ALEXWINHOOKLIB_API __declspec(dllexport)
#else
#define ALEXWINHOOKLIB_API __declspec(dllimport)
#endif

#include<windows.h>

typedef void(*onAlexWinHook_keyboard)(DWORD keyCode);
typedef void(*onAlexWinHook_mouse)(WPARAM wParam);

// ���� ����� ������������� �� AlexWinHookLib.dll
	class ALEXWINHOOKLIB_API CAlexWinHookLib {
	private:

		// ��� ��� ����������
		static LRESULT CALLBACK CBKeyboard(int nCode, WPARAM wParam, LPARAM lParam);
		//��� ��� �����
		static LRESULT CALLBACK CBMouse(int nCode, WPARAM wParam, LPARAM lParam);
	public:
		// ������������� ��� �� ������������ ������� ������
		void keyboardHook(onAlexWinHook_keyboard hook);
		// ������������� ��� �� ������������ ������� ����
		void mouseHook(onAlexWinHook_mouse hook);
	};

