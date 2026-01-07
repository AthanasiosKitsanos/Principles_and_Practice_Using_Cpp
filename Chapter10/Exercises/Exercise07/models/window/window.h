#pragma once

#include "house_pch.h"

class window
{
    QRect win;
    QLine curtain;

    public:
        explicit window() noexcept;
        ~window() = default;

        void set_window(int point_x, int point_y, int width, int height);
        void draw_window(QPainter& painter);
};