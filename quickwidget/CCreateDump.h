#pragma once
#include <string>

using namespace std;
class CCreateDump
{
public:
	CCreateDump();
	~CCreateDump(void);
	static CCreateDump* Instance();
	
	//声明Dump文件，异常时会自动生成。会自动加入.dmp文件名后缀
	void DeclarDumpFile(std::string dmpFileName = "");

private:
    static long /*__stdcall*/ UnhandleExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo);

private:
	static std::string    strDumpFile;
	static CCreateDump*    __instance;
};

