// LabWindowsException.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	INT32 a = 1, b = 0;
	__try {
		goto my;
		int result = a / b;
	}
	__finally {
		if (AbnormalTermination())
			cout << "Abnormal termination with goto." << endl;
		else
			cout << "Normal termination with goto." << endl;
	}
my:
	__try {
		__leave;
		RaiseException(EXCEPTION_SINGLE_STEP, 0, 0, NULL);
	}
	__finally {
		if (AbnormalTermination())
			cout << "Abnormal termination with leave." << endl;
		else
			cout << "Normal termination with leave." << endl;
	}

	system("pause");
	return 0;
}
