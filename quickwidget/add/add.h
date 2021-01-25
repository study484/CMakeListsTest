#define add_lib_shared_EXPORTS
//定义类导入导出宏，
#ifdef add_lib_shared_EXPORTS
#define add_lib_shared_EXPORTS  __declspec(dllexport)
#else   
#define add_lib_shared_EXPORTS  __declspec(dllimport)
#endif //add_lib_shared_EXPORTS

extern "C" int add_lib_shared_EXPORTS add(int a, int b);
