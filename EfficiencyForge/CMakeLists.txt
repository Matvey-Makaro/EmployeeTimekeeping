cmake_minimum_required(VERSION 3.5)

project(EfficiencyForge LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
file(GLOB_RECURSE SOURCES_LIST *.h *.cpp *.qrc *.ui)
get_filename_component(MAIN_CPP ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ABSOLUTE)
list(REMOVE_ITEM SOURCES_LIST ${MAIN_CPP})

add_library(${PROJECT_NAME}-core STATIC ${SOURCES_LIST})
target_link_libraries(${PROJECT_NAME}-core PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql)

add_executable(${PROJECT_NAME} ${MAIN_CPP})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-core Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql)

