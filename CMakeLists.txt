cmake_minimum_required(VERSION 3.14)

project(ChatServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Network)

add_executable(ChatServer
  main.cpp
  server.cpp
  socket.cpp
  server.h
  socket.h
)
target_link_libraries(ChatServer PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(ChatServer PRIVATE Qt6::Network)

install(TARGETS ChatServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
