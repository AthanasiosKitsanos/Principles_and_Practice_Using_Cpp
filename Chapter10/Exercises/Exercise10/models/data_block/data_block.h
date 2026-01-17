#pragma once

#include "frames_content.h"
#include "data_frames.h"
#include "arrow_pointer.h"

enum class data_index: short {point_1, graph_1, window_1, gui_1, simple_window_1, ch10_1, qtheaders, graph_2, window_2, gui_2, gui_private_2, window_cpp_2, image_2};

struct data_block
{
    data_frame frames;
    frames_content context;
    arrow_pointer arrows;
    int* links;
    float new_x_pos;
    float new_y_pos;
    float x_padding;
    float y_padding;
    int arrow_num;
    data_index index;
    
    explicit data_block(const frames_content& con, const float& new_x, const float& new_y, const float& x_pad, const float& y_pad, int arrow_n, data_index index) noexcept;
    ~data_block() = default;

    void set_frames(const QRect& frame);
    QPoint get_start_current() const;
    QPoint get_end_linked(const data_block& block) const;

    double left_1() const { return frames.title_frame.left(); }
    double right_1() const { return frames.title_frame.right(); }
    double top_1() const { return frames.title_frame.top(); }
    double bottom_1() const { return frames.title_frame.bottom(); }
    double width_1() const { return frames.title_frame.width(); }
    double height_1() const { return frames.title_frame.height(); }

    double left_2() const { return frames.context_frame.left(); }
    double right_2() const { return frames.context_frame.right(); }
    double top_2() const { return frames.context_frame.top(); }
    double bottom_2() const { return frames.context_frame.bottom(); }
    double width_2() const { return frames.context_frame.width(); }
    double height_2() const { return frames.context_frame.height();}

    const QLine& arrow_body() const { return arrows.arrow_body; }
    const QPoint& arrow_head_1() const { return arrows.arrow_head_1; }
    const QPoint& arrow_head_2() const { return arrows.arrow_head_2; }
};