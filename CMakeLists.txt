cmake_minimum_required(VERSION 3.26)
project(uol_oop_crypto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(uol_oop_crypto
        Main.cpp
        MerkelMain.cpp
        MerkelMain.h
        OrderBookEntry.h
        test.cpp)
