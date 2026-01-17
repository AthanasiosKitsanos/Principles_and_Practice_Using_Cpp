#include "data_block.h"

data_block::data_block(const frames_content& con, const float& new_x, const float& new_y, const float& x_pad, const float& y_pad, int arrow_n, data_index i) noexcept:
    frames(), context(con), arrows(), links(nullptr), new_x_pos(new_x), new_y_pos(new_y), x_padding(x_pad), y_padding(y_pad), arrow_num(arrow_n), index(i)
{
    if(arrow_num > 0)
    {
        links = static_cast<int*>(malloc(sizeof(int) * arrow_num));
        switch(index)
        {
            case data_index::graph_1:
                *(links) = static_cast<int>(data_index::point_1);
                break;
            case data_index::window_1:
                *(links) = static_cast<int>(data_index::point_1);
                break;
            case data_index::gui_1:
                *(links) = static_cast<int>(data_index::window_1);
                break;
            case data_index::simple_window_1:
                *(links) = static_cast<int>(data_index::gui_1);
                break;
            case data_index::ch10_1:
                *(links) = static_cast<int>(data_index::graph_1);
                *(links + 1) = static_cast<int>(data_index::simple_window_1);
                break;
            case data_index::window_cpp_2:
                *(links) = static_cast<int>(data_index::gui_2);
                *(links + 1) = static_cast<int>(data_index::window_2);
                *(links + 2) = static_cast<int>(data_index::graph_2);
                *(links + 3) = static_cast<int>(data_index::gui_private_2);
                *(links + 4) = static_cast<int>(data_index::qtheaders);
                *(links + 5) = static_cast<int>(data_index::image_2);
                break;
            case data_index::gui_private_2:
                *(links) = static_cast<int>(data_index::graph_2);
                *(links + 1) = static_cast<int>(data_index::qtheaders);
                break;
            case data_index::image_2:
                *(links) = static_cast<int>(data_index::qtheaders);
                break;
        }
    }
}

void data_block::set_frames(const QRect& frame)
{
    int x_start_pos{frame.left()};
    int y_start_pos{frame.top()};
    int f_width{frame.width()};
    int f_height{frame.height()};
    frames.title_frame = QRect(x_start_pos, y_start_pos, f_width, f_height * 0.5f);
    frames.context_frame = QRect(x_start_pos, y_start_pos + f_height * 0.5f, f_width * x_padding, f_height * y_padding);
}

QPoint data_block::get_start_current() const
{
    switch(index)
    {
        case data_index::graph_1: case data_index::ch10_1: case data_index::gui_private_2: case data_index::image_2:
        case data_index::window_cpp_2:
            return QPoint(left_2() + width_2() * 0.5f, top_2());
        case data_index::simple_window_1:
            return QPoint(right_2(), top_2() + height_2() * 0.5f);
        case data_index::gui_1: case data_index::window_1:
            return QPoint(left_2(), top_2() + height_2() * 0.5f);
    }
    return QPoint(0, 0);
}

QPoint data_block::get_end_linked(const data_block& block) const
{
    switch(block.index)
    {
        case data_index::point_1: case data_index::graph_1: case data_index::simple_window_1: case data_index::gui_1:
        case data_index::qtheaders: case data_index::gui_private_2: case data_index::image_2:
            return QPoint(block.left_2() + block.width_2() * 0.5f, block.bottom_2());

        case data_index::window_1: case data_index::gui_2: case data_index::window_2: case data_index::graph_2:
            return QPoint(block.right_2(), block.top_2() + block.height_2() * 0.5f);
    }
    return QPoint(0, 0);
}