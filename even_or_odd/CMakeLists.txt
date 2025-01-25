cmake_minimum_required(VERSION 3.16)

project(even_or_odd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(even_or_odd main.cpp)

include(GNUInstallDirs)
install(TARGETS even_or_odd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
