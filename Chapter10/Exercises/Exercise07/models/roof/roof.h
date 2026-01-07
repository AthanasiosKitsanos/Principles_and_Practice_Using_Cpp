#pragma once

#include "house_pch.h"

class roof
{
    QLineF l_part;
    QLineF r_part;

    public:
        explicit roof() noexcept;
        ~roof() = default;

        void set_roof(int x, int y, int ax, int ay);
        void draw_roof(QPainter& painter);
};