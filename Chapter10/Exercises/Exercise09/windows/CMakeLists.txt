add_library(window STATIC
    main_window/main_window.cpp
)
target_include_directories(window PUBLIC
    "main_window"
    "../pch"
)
target_link_libraries(window PUBLIC Qt6::Widgets)
target_precompile_headers(window PRIVATE "../pch/pch.h")
target_compile_options(window PUBLIC -O3)