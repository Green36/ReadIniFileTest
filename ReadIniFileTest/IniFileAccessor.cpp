
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

// ���񃍁[�h����t���O
static bool gIsLoaded;

// outValue�� �T�C�Y_MAX_PATH �̃������̈���m�ۂ��Ă�������
short GetIniValueString(LPCTSTR key, LPCTSTR defaultValue, LPTSTR outBuff, DWORD buffSize)
{
	DWORD dwLen = 0;
	dwLen = GetPrivateProfileString(
		INI_SECTION,		// �Z�N�V������
		key,				// �L�[��
		defaultValue,		// �f�t�H���g�l
		outBuff,			// �ǂݍ��񂾒l���i�[����G���A
		buffSize,			// ��L�̃G���A�̃T�C�Y
		INI_FILE_PATH);		// ini�t�@�C����
	return 0;
}

IniFileAccessor::IniFileAccessor()
{
	gIsLoaded = false;

	// �����o������
	memset(mAAA, 0x00, _MAX_PATH);
	mBBB = 0;
	memset(mCCC, 0x00, _MAX_PATH);
}

IniFileAccessor& IniFileAccessor::LoadIniFileAccessor()
{
	static IniFileAccessor iniFileAccessor;
	if (gIsLoaded == false)
	{
		// �eKey��ǂݍ��ݕێ�����
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

	// �͈͒l�𔻒肵�ă����o�֕ێ�

	memcpy(mAAA, outBuff, _MAX_PATH);

	return 0;
}

short IniFileAccessor::SetTestBBB()
{
	TCHAR outBuff[_MAX_PATH] = { 0x00 };
	GetIniValueString(INI_KEY_BBB, INI_DEFAULT_BBB, outBuff, _MAX_PATH);

	// �͈͒l�𔻒肵�ă����o�֕ێ�

	mBBB = atoi((char*)outBuff);

	return 0;
}

short IniFileAccessor::SetTestCCC()
{
	TCHAR outBuff[_MAX_PATH] = { 0x00 };
	GetIniValueString(INI_KEY_CCC, INI_DEFAULT_CCC, outBuff, _MAX_PATH);

	// �͈͒l�𔻒肵�ă����o�֕ێ�

	memcpy(mCCC, outBuff, _MAX_PATH);

	return 0;
}
