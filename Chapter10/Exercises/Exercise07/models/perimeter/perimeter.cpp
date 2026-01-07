#include "perimeter.h"

perimeter::perimeter() noexcept {}
perimeter::perimeter(int x, int y, int ax, int ay) noexcept: per(x, y , ax, ay) {}

void perimeter::resize_perimeter(int x, int y, int ax, int ay)
{
    per.setRect(x, y, ax, ay);
}

void perimeter::draw_perimeter(QPainter& painter)
{
    painter.drawRect(per);
}