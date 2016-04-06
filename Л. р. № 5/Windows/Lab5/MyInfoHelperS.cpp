#include "MyInfoHelperS.h"
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <strsafe.h>

using namespace std;

namespace MyInfoHelperS
{
	__int64 convertToGB(__int64 size)
	{
		return size / (1024 * 1024 * 1024);
	}

	int MyInfoHelperS::fileSize(wchar_t* path) {
		HANDLE hFile = CreateFile(path,
			GENERIC_READ,          // open for reading
			0,                      // do not share
			NULL,                   // default security
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,  // normal file
			NULL);
		DWORD size = GetFileSize(hFile, NULL);
		CloseHandle(hFile);
		if (size == INVALID_FILE_SIZE && (size = GetLastError()) != NO_ERROR)
			return -1;
		else
			return size;
	}

	void MyInfoHelperS::totalHDInfo() {
		cout << "Total HD info: : " << endl;
		int sz = GetLogicalDriveStrings(NULL, 0);
		TCHAR* szLogicalDrives = new TCHAR[sz];
		GetLogicalDriveStrings(sz, szLogicalDrives);
		while (*szLogicalDrives)
		{
			TCHAR szDisk[80];
			lstrcpy(szDisk, szLogicalDrives);
			UINT uDriveType = GetDriveType(szDisk);
			if (uDriveType == DRIVE_FIXED)
			{
				wcout << szDisk << endl;
				__int64 free = 0, total = 0;
				GetDiskFreeSpaceEx(szDisk, NULL, (PULARGE_INTEGER)&total, (PULARGE_INTEGER)&free);
				cout << "Total : " << convertToGB(total) << " GB" << endl;
				cout << "Free : " << convertToGB(free) << " GB" << endl;
				cout << "Used : " << convertToGB(total - free) << " GB" << endl;
			}
			while (*szLogicalDrives) szLogicalDrives++;
			szLogicalDrives++;
		}
	}

}
