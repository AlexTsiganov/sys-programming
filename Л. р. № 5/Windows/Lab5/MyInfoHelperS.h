#pragma once
#include <windows.h>

namespace MyInfoHelperS
{
	class MyInfoHelperS
	{
	public:
		static int fileSize(wchar_t* path);
		static void totalHDInfo();
	};
}
