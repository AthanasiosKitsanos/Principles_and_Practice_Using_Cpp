#pragma once

#include "house_pch.h"

constexpr int ticks = 3;

class door
{
    QLine l_line;
    QLine t_line;
    QLine r_line;
    QLine inlines[ticks];

    public:
        explicit door() noexcept;
        ~door() = default;

        void set_door(int x, int y);
        void draw_door(QPainter& painter);
};