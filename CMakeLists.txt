cmake_minimum_required(VERSION 3.10)
project(Cpp_Exersices)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(MyCppApp ${SOURCES})
