cmake_minimum_required(VERSION 3.27)
project(Esame_E_M)

set(CMAKE_CXX_STANDARD 17)

add_executable(Esame_E_M main.cpp
        ContoCorrente.cpp
        Transazioni.cpp
        Check.cpp)
