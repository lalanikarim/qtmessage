cmake_minimum_required(VERSION 3.14)

project(qtmessagelib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_library(qtmessagelib SHARED
  qtmessagelib_global.h
  sms.cpp
  sms.h
)

target_link_libraries(qtmessagelib PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)

target_compile_definitions(qtmessagelib PRIVATE QTMESSAGELIB_LIBRARY)
