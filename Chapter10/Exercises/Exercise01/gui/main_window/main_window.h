#pragma once

#include "pch.h"

class main_window: public QWidget
{
    protected:
        void paintEvent(QPaintEvent*) override;
    
    public:
        explicit main_window(QWidget* parent = nullptr);
        ~main_window();
};