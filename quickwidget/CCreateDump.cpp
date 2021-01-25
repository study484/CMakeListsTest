#include <Windows.h>
#include "CCreateDump.h"
#include <DbgHelp.h>
#include <iostream>
#include <fstream>
#pragma comment(lib,  "dbghelp.lib")

CCreateDump* CCreateDump::__instance = NULL;
std::string CCreateDump::strDumpFile = "";

CCreateDump::CCreateDump()
{
}

CCreateDump::~CCreateDump(void)
{

}

long  CCreateDump::UnhandleExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo)
{
	HANDLE hFile = CreateFile(strDumpFile.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MINIDUMP_EXCEPTION_INFORMATION   ExInfo;
		ExInfo.ThreadId = ::GetCurrentThreadId();
		ExInfo.ExceptionPointers = ExceptionInfo;
		ExInfo.ClientPointers = FALSE;
		//   write   the   dump
		BOOL   bOK = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpNormal, &ExInfo, NULL, NULL);
		CloseHandle(hFile);

        ofstream outfile("out.txt", ios::app);       

		if (!bOK)
		{
			DWORD dw = GetLastError();
			//写dump文件出错处理,异常交给windows处理
            outfile << "write dump failure." << endl;
			return EXCEPTION_CONTINUE_SEARCH;
		}
		else
		{    //在异常处结束
            outfile << "write dump success." << endl;
			return EXCEPTION_EXECUTE_HANDLER;
		}

	}
	else
	{
		return EXCEPTION_CONTINUE_SEARCH;
	}
}

void CCreateDump::DeclarDumpFile(std::string dmpFileName)
{
	SYSTEMTIME syt;
	GetLocalTime(&syt);
	char c[MAX_PATH];
	sprintf_s(c, MAX_PATH, "[%04d-%02d-%02d %02d：%02d：%02d]", syt.wYear, syt.wMonth, syt.wDay, syt.wHour, syt.wMinute, syt.wSecond);
	strDumpFile = std::string(c);
	if (!dmpFileName.empty())
	{
		strDumpFile += dmpFileName;
	}
	strDumpFile += std::string(".dmp");
	SetUnhandledExceptionFilter(UnhandleExceptionFilter);
}

CCreateDump* CCreateDump::Instance()
{
	if (__instance == NULL)
	{
		__instance = new CCreateDump;
	}
	return __instance;
}

