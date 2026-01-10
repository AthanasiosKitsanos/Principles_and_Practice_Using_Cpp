add_library(window STATIC
    window.cpp
    ../models/circle_data/circle_data.cpp
)
target_include_directories(window PUBLIC 
    "window"
    "../models/circle_data"
    "../pch"
)
target_precompile_headers(window PRIVATE "../pch/pch.h")
target_link_libraries(window PUBLIC Qt6::Widgets)
target_compile_options(window PUBLIC -O3)