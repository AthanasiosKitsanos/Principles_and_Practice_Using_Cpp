add_library(widget STATIC
    main_widget/main_widget.cpp
)
target_include_directories(widget PRIVATE
    "main_widget"
    "../models/show_data"
    "../pch"
)
target_link_libraries(widget PRIVATE Qt::Widgets)
target_precompile_headers(widget PRIVATE
    "../pch/widget_pch.h"
)
target_compile_options(widget PUBLIC -O3)