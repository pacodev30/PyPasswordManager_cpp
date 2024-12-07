cmake_minimum_required(VERSION 3.16)

project(MyPasswordManager_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    MyPasswordManager_cpp
    main.cpp
    Entry.h
    Entry.cpp
    Manager.h
    Manager.cpp
)

include(GNUInstallDirs)
install(TARGETS MyPasswordManager_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
