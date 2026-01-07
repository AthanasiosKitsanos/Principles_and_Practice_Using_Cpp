#include "door.h"

door::door() noexcept {}

void::door::set_door(int x, int y)
{
    l_line.setLine(x, y, x, y - y * 0.25f);
    t_line.setLine(x, y - y * 0.25f, x * 1.14f, y - y * 0.25f);
    r_line.setLine(x * 1.14f, y - y * 0.25f, x * 1.14f, y);
    int start(x + (x * 0.14f) / (ticks + 1));
    int end(x * 1.14f);
    int step{(end - x) / (ticks + 1)};
    int tick{0};
    for(short i{0}; i < ticks; ++i)
    {
        tick = start + i * step;
        inlines[i].setLine(tick, y - y * 0.25f, tick, y);
    }
}

void door::draw_door(QPainter& painter)
{
    painter.drawLine(l_line);
    painter.drawLine(t_line);
    painter.drawLine(r_line);
    for(short i{0}; i < ticks; ++i)
    {
        painter.drawLine(inlines[i]);
    }
}