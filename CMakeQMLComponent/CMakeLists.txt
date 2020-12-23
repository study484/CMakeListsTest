
cmake_minimum_required(VERSION 2.8.12)

project(01_qml LANGUAGES CXX)
#set(Qt5_DIR "/home/liuqiang/Qt5.10.1/5.10.1/gcc_64/lib/cmake/Qt5")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Quick REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "resource.qrc")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Widgets)
