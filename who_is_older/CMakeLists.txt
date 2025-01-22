cmake_minimum_required(VERSION 3.16)

project(who_is_older LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(who_is_older main.cpp)

include(GNUInstallDirs)
install(TARGETS who_is_older
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
