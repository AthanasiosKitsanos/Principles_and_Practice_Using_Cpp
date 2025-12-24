cmake_minimum_required(VERSION 3.30)

project(Drill LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(run main.cpp gui/main_window/main_window.cpp)

target_include_directories(
    run PRIVATE "${CMAKE_SOURCE_DIR}/pch"
    "${CMAKE_SOURCE_DIR}/gui/main_window"
)

target_precompile_headers(run PRIVATE "${CMAKE_SOURCE_DIR}/pch/pch.h")

set_target_properties(run PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug")
set_target_properties(run PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release")

target_link_libraries(run PRIVATE Qt6::Widgets)
target_compile_options(run PRIVATE -O3)