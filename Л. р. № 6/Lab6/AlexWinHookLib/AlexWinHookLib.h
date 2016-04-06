// Приведенный ниже блок ifdef - это стандартный метод создания макросов, упрощающий процедуру 
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа ALEXWINHOOKLIB_EXPORTS,
// в командной строке. Этот символ не должен быть определен в каком-либо проекте
// использующем данную DLL. Благодаря этому любой другой проект, чьи исходные файлы включают данный файл, видит 
// функции ALEXWINHOOKLIB_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef ALEXWINHOOKLIB_EXPORTS
#define ALEXWINHOOKLIB_API __declspec(dllexport)
#else
#define ALEXWINHOOKLIB_API __declspec(dllimport)
#endif

#include<windows.h>

typedef void(*onAlexWinHook_keyboard)(DWORD keyCode);
typedef void(*onAlexWinHook_mouse)(WPARAM wParam);

// Этот класс экспортирован из AlexWinHookLib.dll
	class ALEXWINHOOKLIB_API CAlexWinHookLib {
	private:

		// хук для клавиатуры
		static LRESULT CALLBACK CBKeyboard(int nCode, WPARAM wParam, LPARAM lParam);
		//хук для мышки
		static LRESULT CALLBACK CBMouse(int nCode, WPARAM wParam, LPARAM lParam);
	public:
		// устанавливает хук на отслеживание нажатия клавиш
		void keyboardHook(onAlexWinHook_keyboard hook);
		// устанавливает хук на отслеживание нажатия мыши
		void mouseHook(onAlexWinHook_mouse hook);
	};

