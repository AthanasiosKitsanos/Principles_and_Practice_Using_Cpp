#pragma once

#include "house_pch.h"
#include "door.h"
#include "roof.h"
#include "window.h"
#include "perimeter.h"
#include "chimney.h"

class house
{
    door h_door;
    chimney h_chimney;
    window l_window;
    window r_window;
    roof h_roof;
    perimeter h_per;
    int width, height;

    public:
        explicit house() noexcept;
        ~house() = default;
        
        void resize_house(const QRect& rect);
        void draw_house(QPainter& painter);
};