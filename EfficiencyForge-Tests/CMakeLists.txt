cmake_minimum_required(VERSION 3.5)

project(EfficiencyForge LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE SOURCES_LIST *.h *.cpp)

option(RUN_TEST_IN_EXEC "Turn tests on/off" OFF)

find_package(Qt5 COMPONENTS Core Test REQUIRED)

if(RUN_TEST_IN_EXEC)
    add_executable(${PROJECT_NAME}-Tests ${SOURCES_LIST})
else()
    list(FILTER SOURCES_LIST EXCLUDE REGEX "main")
    add_library(${PROJECT_NAME}-Tests SHARED ${SOURCES_LIST})
endif()

target_include_directories(${PROJECT_NAME}-Tests PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}-Tests PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}-Tests PRIVATE ${PROJECT_NAME}-core Qt5::Core Qt5::Test)
