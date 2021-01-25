find_package(Qt5 COMPONENTS Core)


#递归目录获取所有c文件
file(GLOB_RECURSE c_files  *.cpp *.c)
#生成动态库
add_library(add_lib_shared  SHARED ${c_files})
#将动态库名字设为add
set_target_properties(add_lib_shared PROPERTIES OUTPUT_NAME "add")
set_target_properties(add_lib_shared PROPERTIES VERSION 1.0 SOVERSION 1)