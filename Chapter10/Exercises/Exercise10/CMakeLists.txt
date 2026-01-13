cmake_minimum_required(VERSION 3.30)

project(run LANGUAGES CXX)

# Languages
set(CMAKE_CXX_STANDARD 20)

# Build and Output Type
set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# Dependencies
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Sub-directories
add_subdirectory(widgets)
add_subdirectory(models/show_data)


# Executable
add_executable(run main.cpp)
target_include_directories(run PRIVATE
    "models/show_data"
    "widgets/main_widget"
    "pch"
)
target_precompile_headers(run PRIVATE "pch/pch.h")
target_link_libraries(run PRIVATE
    Qt::Widgets
    widget
    show_data
)
target_compile_options(run PRIVATE -O3)