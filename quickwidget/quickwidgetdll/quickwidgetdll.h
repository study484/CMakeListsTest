
//定义类导入导出宏，
#ifdef quickwidgetdll_lib_shared_EXPORTS
#define quickwidgetdll_lib_shared_EXPORTS  __declspec(dllexport)
#else   
#define quickwidgetdll_lib_shared_EXPORTS  __declspec(dllimport)
#endif //quickwidgetdll_lib_shared_EXPORTS