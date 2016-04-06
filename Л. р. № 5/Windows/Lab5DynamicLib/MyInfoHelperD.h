#pragma once

#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport) 
#else
#define MATHFUNCSDLL_API __declspec(dllimport) 
#endif

namespace MyInfoHelperD
{
	class MyInfoHelperD
	{
	public:
		static MATHFUNCSDLL_API int fileSize(wchar_t* path);
		static MATHFUNCSDLL_API void totalHDInfo();
	};
}
