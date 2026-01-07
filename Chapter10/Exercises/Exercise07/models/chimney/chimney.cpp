#include "chimney.h"

chimney::chimney() noexcept {}

void chimney::set_chimney(int x, int y) noexcept
{
    l_part.setLine(x, y, x, y * 0.5f);
    t_part.setLine(x, y * 0.5f, x * 1.06f, y * 0.5f);
    r_part.setLine(x * 1.06f, y * 0.5f, x * 1.06f, y - y * 0.26f);
}

void chimney::draw_chimney(QPainter& painter) noexcept
{
    painter.drawLine(l_part);
    painter.drawLine(t_part);
    painter.drawLine(r_part);
}