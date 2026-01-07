#pragma once

#include "house_pch.h"

class perimeter
{
    QRect per;

    public:
        explicit perimeter() noexcept;
        explicit perimeter(int x, int y, int ax, int ay) noexcept;
        ~perimeter() = default;

        void resize_perimeter(int x, int y, int ax, int ay);
        void draw_perimeter(QPainter& painter);
};