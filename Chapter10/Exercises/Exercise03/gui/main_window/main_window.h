#pragma once

#include "pch.h"

class main_window: public QWidget
{
    protected:
        void paintEvent(QPaintEvent*) override;

    public:
        main_window(QWidget* parent = nullptr) noexcept;
        ~main_window() = default;
};