#递归目录获取所有c文件
file(GLOB_RECURSE c_files  *.cpp *.c)
link_directories(${PROJECT_SOURCE_DIR}/bin)
 
add_executable(cmakeTest ${c_files})
 
target_link_libraries(cmakeTest add)
target_link_libraries(cmakeTest sub)