cmake_minimum_required(VERSION 3.15)
project(2ndPeriod)

set(CMAKE_CXX_STANDARD 17)

include(pmm.cmake)
include_directories(ThreadPool)
pmm(CONAN)

add_subdirectory(Algoritme/Wk1)
add_subdirectory(Algoritme/Wk3tm5)
add_subdirectory(OOP2/OOP2WK1)
add_subdirectory(OOP2/OOP2WK2)
add_subdirectory(OOP2/OOP2WK3)
add_subdirectory(ConcurrentProgramming/ConcurrentWK1)
add_subdirectory(ConcurrentProgramming/ConcurrentWK2)
add_subdirectory(ConcurrentProgramming/ConcurrentWK4)