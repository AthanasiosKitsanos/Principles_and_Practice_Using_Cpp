cmake_minimum_required(VERSION 3.30)

project(Exercise09 LANGUAGES CXX)

# Language
set(CMAKE_CXX_STANDARD 20)

# Build and Output Type
set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# Dependencies
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Sub-Directories
add_subdirectory(windows)

# Eecutable
add_executable(run main.cpp)
target_include_directories(run PRIVATE "windows/main_window")
target_link_libraries(run PRIVATE window)
target_compile_options(run PRIVATE -O3)