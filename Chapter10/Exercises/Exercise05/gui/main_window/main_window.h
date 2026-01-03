#pragma once

#include "pch.h"

class main_window: public QWidget
{
    QRect* rect;
    qreal frame_width;
    int win_x;
    int win_y;
    
    protected:
        void paintEvent(QPaintEvent*) override;
        void resizeEvent(QResizeEvent*) override;
    
    public:
        main_window(QWidget* parent = nullptr) noexcept;
        ~main_window() noexcept;
};