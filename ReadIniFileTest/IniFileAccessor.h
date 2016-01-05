#pragma once

#include <windows.h>



class IniFileAccessor
{
private:

	// コンストラクタ呼び出し禁止
	IniFileAccessor();

	short SetTestAAA();
	short SetTestBBB();
	short SetTestCCC();

	TCHAR mAAA[_MAX_PATH];
	DWORD mBBB;
	TCHAR mCCC[_MAX_PATH];

	// 初回Load 判定フラグ
	static bool mIsLoaded;

public:
	static IniFileAccessor& LoadIniFileAccessor();

	LPTSTR GetTestAAA() { return mAAA; }
	DWORD GetTestBBB() { return mBBB; }
	LPTSTR GetTestCCC() { return mCCC; }
};


