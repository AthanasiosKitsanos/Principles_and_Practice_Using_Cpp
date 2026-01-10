cmake_minimum_required(VERSION 3.30)

project(Exercise08 LANGUAGES CXX)

# Langauge
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED  on)

# Build type & Output type
set(CMAKE_BUILD_TYPE release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# Dependencies
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Window
add_subdirectory(window)

# Executable
add_executable(run main.cpp)
target_include_directories(run PRIVATE "window")
target_link_libraries(run PRIVATE window)
target_compile_options(run PRIVATE -O3)