cmake_minimum_required(VERSION 3.16)
project(MyQtApp LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(MyQtApp
    main.cpp
)

target_link_libraries(MyQtApp PRIVATE Qt6::Widgets)
