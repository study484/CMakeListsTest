#pragma once
#include <string>

using namespace std;
class CCreateDump
{
public:
	CCreateDump();
	~CCreateDump(void);
	static CCreateDump* Instance();
	
	//����Dump�ļ����쳣ʱ���Զ����ɡ����Զ�����.dmp�ļ�����׺
	void DeclarDumpFile(std::string dmpFileName = "");

private:
    static long /*__stdcall*/ UnhandleExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo);

private:
	static std::string    strDumpFile;
	static CCreateDump*    __instance;
};

