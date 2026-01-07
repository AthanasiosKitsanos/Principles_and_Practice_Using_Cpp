#include "roof.h"

roof::roof() noexcept {}

void roof::set_roof(int x, int y, int ax, int ay)
{
    l_part.setLine(x, y, ax, ay);
    r_part.setLine(ax, ay, x + 2 *(ax - x), y);
}

void roof::draw_roof(QPainter& painter)
{
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawLine(l_part);
    painter.drawLine(r_part);
    painter.setRenderHint(QPainter::Antialiasing, false);
}