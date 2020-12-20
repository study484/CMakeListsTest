cmake_minimum_required(VERSION 3.8)
project(MultiProjects)
 
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
 
# SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)   #导出clangd需要的文件，用于智能提示和基于语议的补全
 
# set(CMAKE_CXX_FLAGS "-std=c++11 -g3 -rdynamic")
# set(CMAKE_CXX_FLAGS_DEBUG "-O0")
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
 
#打印信息
message(STATUS "build type:")
message(STATUS "CXX_FLAGS = ${CMAKE_CXX_FLAGS} ")
 
#设置库文件输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
 
 
#递归目录获取所有h文件
include_directories(${PROJECT_SOURCE_DIR}/source/add)
include_directories(${PROJECT_SOURCE_DIR}/source/sub)
include_directories(${PROJECT_SOURCE_DIR}/source/main)
 
 
add_subdirectory(source/add)
add_subdirectory(source/sub)
add_subdirectory(source/main)
 
#cmake中执行shell指令
#execute_process(COMMAND pwd)