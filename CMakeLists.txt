cmake_minimum_required(VERSION 3.10)
project(ProjectOptimizationMeta)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(Optimizer main.cpp ${SOURCES})