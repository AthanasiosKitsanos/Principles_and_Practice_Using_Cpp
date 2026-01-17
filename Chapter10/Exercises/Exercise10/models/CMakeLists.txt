add_library(data_block STATIC
    "frames_content/frames_content.cpp"
    "data_block/data_block.cpp"
    "arrow_pointer/arrow_pointer.cpp"
    "data_frames/data_frames.cpp"
)
target_include_directories(data_block PUBLIC
    "frames_content"
    "data_block"
    "arrow_pointer"
    "data_frames"
    "../pch"
)
target_link_libraries(data_block PUBLIC Qt::Gui)
target_precompile_headers(data_block PRIVATE "../pch/data_pch.h")
target_compile_options(data_block PUBLIC -O3)