// ReadIniFileTest.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <windows.h>

#include "IniFileAccessor.h"



int main()
{
	IniFileAccessor iniFile = IniFileAccessor::LoadIniFileAccessor();
	printf("AAA = %s\n", iniFile.GetTestAAA());
	printf("BBB = %d\n", iniFile.GetTestBBB());
	printf("CCC = %s\n", iniFile.GetTestCCC());

    return 0;
}
