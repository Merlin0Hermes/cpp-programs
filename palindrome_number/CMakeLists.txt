cmake_minimum_required(VERSION 3.16)

project(palindrome_number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(palindrome_number main.cpp)

include(GNUInstallDirs)
install(TARGETS palindrome_number
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
