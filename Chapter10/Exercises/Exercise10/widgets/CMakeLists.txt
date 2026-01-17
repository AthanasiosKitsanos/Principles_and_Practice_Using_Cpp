add_library(widget STATIC
    main_widget/main_widget.cpp
)
target_include_directories(widget PUBLIC
    "main_widget"
)
target_link_libraries(widget PUBLIC
    Qt::Widgets
    data_block
)
target_precompile_headers(widget PRIVATE "../pch/widget_pch.h")
target_compile_options(widget PRIVATE -O3)