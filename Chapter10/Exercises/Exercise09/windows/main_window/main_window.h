#pragma once

#include "pch.h"

class main_window: public QWidget
{
    QPixmap original_image;
    QPixmap drawn_image;

    protected:
        void paintEvent(QPaintEvent*) override;
        void resizeEvent(QResizeEvent* event) override;
    
    public:
        explicit main_window(QWidget* parent = nullptr) noexcept;
        ~main_window() = default;
};