//定义类导入导出宏，
#ifdef sub_lib_shared_EXPORTS
#define sub_lib_shared_EXPORTS  __declspec(dllexport)
#else   
#define sub_lib_shared_EXPORTS  __declspec(dllimport)
#endif //sub_lib_shared_EXPORTS

extern "C" int sub_lib_shared_EXPORTS sub(int a, int b);