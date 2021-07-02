#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
 #项目名称
PROJECT(TEst)

#file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
#source_group("Include" FILES ${CURRENT_HEADERS})

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
#AUX_SOURCE_DIRECTORY(. SRC_LIST)
#生成应用程序 hello (在windows下会自动生成hello.exe)
#ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST} ${CURRENT_HEADERS})

add_subdirectory(src)
