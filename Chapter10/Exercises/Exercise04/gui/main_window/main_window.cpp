#include "main_window.h"

main_window::main_window(QWidget* parent) noexcept: QWidget(parent)
{
    setMinimumSize(600, 400);
    setMaximumSize(600, 400);
    setWindowTitle("Exercise 4");
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    int line_width{pen.width()};
    bool is_white{false};
    // By keeping the line's width, we make sure the rectangles don't overlap
    for(int x{min_width - line_width}; x < max_width - line_width; x += (min_width + line_width))
    {
        for(int y{min_height - line_width}; y < max_height - line_width; y += (min_height + line_width))
        {
            if(is_white) pen.setColor(Qt::white);
            else pen.setColor(Qt::red);
            painter.setPen(pen);
            painter.drawRect(x, y, min_width, min_height);
            is_white = !is_white;
        }
    }
}