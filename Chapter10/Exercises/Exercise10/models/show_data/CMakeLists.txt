add_library(show_data STATIC "show_data.cpp")
target_include_directories(show_data PRIVATE
    "show_data"
    "../../pch"
)
target_link_libraries(show_data PRIVATE Qt::Widgets)
target_precompile_headers(show_data PRIVATE "../../pch/show_data_pch.h")
target_compile_options(show_data PUBLIC -O3)