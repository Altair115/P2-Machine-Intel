project(ConcurrentWk4)
include_directories("${CMAKE_SOURCE_DIR}/ThreadPool")
add_executable(Concurrent_Wk4 main.cpp grid.cpp grid.h)
