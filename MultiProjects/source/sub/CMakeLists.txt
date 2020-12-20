#递归目录获取所有c文件
file(GLOB_RECURSE c_files  *.cpp *.c)
#生成动态库
add_library(sub_lib_shared  SHARED ${c_files})
#将动态库名字设为sub
set_target_properties(sub_lib_shared PROPERTIES OUTPUT_NAME "sub")
set_target_properties(sub_lib_shared PROPERTIES VERSION 1.0 SOVERSION 1)