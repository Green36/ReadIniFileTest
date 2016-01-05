#pragma once

#include <windows.h>



class IniFileAccessor
{
private:

	// �R���X�g���N�^�Ăяo���֎~
	IniFileAccessor();

	short SetTestAAA();
	short SetTestBBB();
	short SetTestCCC();

	TCHAR mAAA[_MAX_PATH];
	DWORD mBBB;
	TCHAR mCCC[_MAX_PATH];

	// ����Load ����t���O
	static bool mIsLoaded;

public:
	static IniFileAccessor& LoadIniFileAccessor();

	LPTSTR GetTestAAA() { return mAAA; }
	DWORD GetTestBBB() { return mBBB; }
	LPTSTR GetTestCCC() { return mCCC; }
};


