#include <windows.h>
#include <process.h>
#include <assert.h>
#include <stdio.h>
 
#define DEFAULT_STACK//注释该行,则开辟的线程默认栈大小为512KB
 
volatile bool g_bExitThread = false;
HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
 
 
UINT WINAPI WorkThread(void* ptr)
{
	int nThreadID = *((int*)ptr);	
	printf("%d Thread start.\n", nThreadID);
 
	SetEvent(g_hEvent);
	while(!g_bExitThread)
	{
		Sleep(1);//权宜之计，让线程不要提前退出
	}
 
	return 0;
}
 
int main(int argc, char* argv[])
{
	for(int i=0; i<5000; i++)
	{
 
#ifdef DEFAULT_STACK
		HANDLE _handle = (HANDLE)_beginthreadex(NULL, 0, WorkThread, &i, 0, NULL);
#else
		HANDLE _handle = (HANDLE)_beginthreadex(NULL, 512*1024, WorkThread, &i, STACK_SIZE_PARAM_IS_A_RESERVATION, NULL);
#endif		
		
		if (_handle == 0)
		{
			if(GetLastError() == 8)
			{
				printf("Fail to create thread, storage space insufficient!\n");
			}
			else
			{
				printf("Fail to create thread,error number : %d\n", GetLastError());
			}
			break;
		}
		WaitForSingleObject(g_hEvent, INFINITE);
	}
	getchar();
	return 0;
}