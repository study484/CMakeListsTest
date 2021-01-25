
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


find_package(Qt5 COMPONENTS core gui quick widgets quickwidgets REQUIRED)


#生成动态库
add_library(quickwidgetdll_lib_shared  SHARED "fbitem.h" "fbitem.cpp" "quickwidgetdll.h" "mainwindow.h" "mainwindow.cpp" "quickwidget.qrc")
#将动态库名字设为add
set_target_properties(quickwidgetdll_lib_shared PROPERTIES OUTPUT_NAME "quickwidgetdll")
set_target_properties(quickwidgetdll_lib_shared PROPERTIES VERSION 1.0 SOVERSION 1)

target_link_libraries(quickwidgetdll_lib_shared  Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick Qt5::Widgets Qt5::QuickWidgets)