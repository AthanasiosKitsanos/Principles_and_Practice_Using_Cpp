#include "show_data.h"

show_data::show_data(const QString& file, const QString& con, const float x, const float y, const float x_p, const float y_pad, const int line) noexcept: file_type(std::move(file)),
    constructor_string(std::move(con)), x_factor(x), y_factor(y), x_padding(x_p), y_padding(y_pad), lines(line)
{

}

void show_data::set_frames(const QRect& frame)
{
    int x_start_p{frame.left()};
    int y_start_p{frame.top()};
    int f_width{frame.width()};
    int f_height{frame.height()};
    file_type_frame = QRectF(x_start_p, y_start_p, f_width, f_height * 0.5);
    constructor_frame = QRectF(x_start_p, y_start_p + f_height * 0.5f, f_width * x_padding, f_height * y_padding);
}