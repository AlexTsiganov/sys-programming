// TestLab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyInfoHelperS.h"
#include "MyInfoHelperD.h"
#include <iostream>

using namespace std;

int main()
{
	wchar_t* path = L"C:\\vm\\OS X Yosemite\\OS X Yosemite.vmdk";
	int size = MyInfoHelperS::MyInfoHelperS::fileSize(path);
	printf("MyInfoHelper static\n");
	wcout << "File size of " << path << " - " << size << endl;
	MyInfoHelperS::MyInfoHelperS::totalHDInfo();

	size = MyInfoHelperD::MyInfoHelperD::fileSize(path);
	printf("\nMyInfoHelper dynamic\n");
	wcout << "File size of " << path << " - " << size << endl;
	MyInfoHelperD::MyInfoHelperD::totalHDInfo();
	

	system("pause");
    return 0;
}

