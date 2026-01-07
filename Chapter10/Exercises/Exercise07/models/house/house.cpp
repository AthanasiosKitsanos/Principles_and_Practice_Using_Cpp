#include "house.h"
#include <iostream>
#include <algorithm>

house::house() noexcept: width(0), height(0) {}

void house::resize_house(const QRect& area)
{
    int x{area.x()};
    int y{area.y()};
    width = area.width();
    height = area.height();
    h_door.set_door(x + width / 3, y + height);
    h_chimney.set_chimney(x + (width / 2) / 3, y - height * 0.2f);
    l_window.set_window(x + width / 13, y + height / 9, width / 4, height / 4);
    r_window.set_window(x + width * 0.67f, y + height / 9, width / 4, height / 4);
    h_roof.set_roof(x, y, x + width / 2, height / 5);
    h_per.resize_perimeter(x, y, width, height);
}

void house::draw_house(QPainter& painter)
{
    h_door.draw_door(painter);
    h_chimney.draw_chimney(painter);
    l_window.draw_window(painter);
    r_window.draw_window(painter);
    h_roof.draw_roof(painter);
    h_per.draw_perimeter(painter);
}