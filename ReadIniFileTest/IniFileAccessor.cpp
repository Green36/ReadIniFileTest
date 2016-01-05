
#include "stdafx.h"

#include "IniFileAccessor.h"

static LPCTSTR INI_FILE_PATH = TEXT(".\\TESTDEBUG.ini");
static LPCTSTR INI_SECTION = TEXT("SECTION");

static LPCTSTR INI_KEY_AAA = TEXT("KEY_AAA");
static LPCTSTR INI_KEY_BBB = TEXT("KEY_BBB");
static LPCTSTR INI_KEY_CCC = TEXT("KEY_CCC");

static LPCTSTR INI_DEFAULT_AAA = TEXT("DEFAULT_AAA");
static LPCTSTR INI_DEFAULT_BBB = TEXT("3");
static LPCTSTR INI_DEFAULT_CCC = TEXT("DEFAULT_CCC");

// 初回ロード判定フラグ
static bool gIsLoaded;

// outValueは サイズ_MAX_PATH のメモリ領域を確保しておくこと
short GetIniValueString(LPCTSTR key, LPCTSTR defaultValue, LPTSTR outBuff, DWORD buffSize)
{
	DWORD dwLen = 0;
	dwLen = GetPrivateProfileString(
		INI_SECTION,		// セクション名
		key,				// キー名
		defaultValue,		// デフォルト値
		outBuff,			// 読み込んだ値を格納するエリア
		buffSize,			// 上記のエリアのサイズ
		INI_FILE_PATH);		// iniファイル名
	return 0;
}

IniFileAccessor::IniFileAccessor()
{
	gIsLoaded = false;

	// メンバ初期化
	memset(mAAA, 0x00, _MAX_PATH);
	mBBB = 0;
	memset(mCCC, 0x00, _MAX_PATH);
}

IniFileAccessor& IniFileAccessor::LoadIniFileAccessor()
{
	static IniFileAccessor iniFileAccessor;
	if (gIsLoaded == false)
	{
		// 各Keyを読み込み保持する
		iniFileAccessor.SetTestAAA();
		iniFileAccessor.SetTestBBB();
		iniFileAccessor.SetTestCCC();
		gIsLoaded = true;
	}
	return iniFileAccessor;
}

short IniFileAccessor::SetTestAAA()
{
	TCHAR outBuff[_MAX_PATH] = { 0x00 };
	GetIniValueString(INI_KEY_AAA, INI_DEFAULT_AAA, outBuff, _MAX_PATH);

	// 範囲値を判定してメンバへ保持

	memcpy(mAAA, outBuff, _MAX_PATH);

	return 0;
}

short IniFileAccessor::SetTestBBB()
{
	TCHAR outBuff[_MAX_PATH] = { 0x00 };
	GetIniValueString(INI_KEY_BBB, INI_DEFAULT_BBB, outBuff, _MAX_PATH);

	// 範囲値を判定してメンバへ保持

	mBBB = atoi((char*)outBuff);

	return 0;
}

short IniFileAccessor::SetTestCCC()
{
	TCHAR outBuff[_MAX_PATH] = { 0x00 };
	GetIniValueString(INI_KEY_CCC, INI_DEFAULT_CCC, outBuff, _MAX_PATH);

	// 範囲値を判定してメンバへ保持

	memcpy(mCCC, outBuff, _MAX_PATH);

	return 0;
}
