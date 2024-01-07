cmake_minimum_required(VERSION 3.14)

project(qtmessage LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_executable(qtmessage
  main.cpp
  private.h
)
target_link_libraries(qtmessage Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)
include_directories(qtmessage ../qtmessagelib)
add_dependencies(qtmessage qtmessagelib)
target_link_libraries(qtmessage qtmessagelib)

include(GNUInstallDirs)
install(TARGETS qtmessage
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
