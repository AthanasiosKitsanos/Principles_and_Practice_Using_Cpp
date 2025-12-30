cmake_minimum_required(VERSION 3.30)

project(Drill LANGUAGES CXX)

# Global configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# Dependencies
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# main_window library
add_library(main_window STATIC gui/main_window/main_window.cpp)
target_include_directories(main_window PUBLIC 
    "${CMAKE_SOURCE_DIR}/gui/main_window"
    "${CMAKE_SOURCE_DIR}/pch"
)
target_link_libraries(main_window PUBLIC
    Qt6::Widgets
)
target_precompile_headers(main_window PRIVATE "${CMAKE_SOURCE_DIR}/pch/pch.h")
target_compile_options(main_window PRIVATE -O3)

# Executable
add_executable(run main.cpp)
target_link_libraries(run PRIVATE main_window)
target_precompile_headers(run PRIVATE "${CMAKE_SOURCE_DIR}/pch/pch.h")
target_compile_options(run PRIVATE -O3)