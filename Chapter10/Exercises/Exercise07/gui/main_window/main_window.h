#pragma once

#include "pch.h"

class house;

class main_window: public QWidget
{
    house* home;
    short win_x;
    short win_y;

    protected:
        void paintEvent(QPaintEvent*) override;
        void resizeEvent(QResizeEvent*) override;

    public:
        explicit main_window(QWidget* parent = nullptr) noexcept;
        ~main_window();
};