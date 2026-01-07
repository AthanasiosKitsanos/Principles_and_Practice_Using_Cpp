#include "window.h"

window::window() noexcept {}

void window::set_window(int point_x, int point_y, int width, int height)
{
    win.setRect(point_x, point_y, width, height);
    curtain.setPoints({point_x + width / 2, point_y}, {point_x + width / 2, point_y + height});
}

void window::draw_window(QPainter& painter)
{
    painter.drawRect(win);
    painter.drawLine(curtain);
}