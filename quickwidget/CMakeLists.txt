cmake_minimum_required(VERSION 2.8.12)

project(quickwidget LANGUAGES CXX)
#set(Qt5_DIR "/home/liuqiang/Qt5.10.1/5.10.1/gcc_64/lib/cmake/Qt5")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
link_directories(${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/add)
include_directories(${PROJECT_SOURCE_DIR}/quickwidgetdll)

add_subdirectory(add)
add_subdirectory(quickwidgetdll)


find_package(Qt5 COMPONENTS core gui quick widgets quickwidgets REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "fbitem.h" "fbitem.cpp" "CCreateDump.h" "CCreateDump.cpp" "quickwidget.qrc")

target_link_libraries(${PROJECT_NAME}  Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick Qt5::Widgets Qt5::QuickWidgets add quickwidgetdll)