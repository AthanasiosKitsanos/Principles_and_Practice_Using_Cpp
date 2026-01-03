#pragma once

#include "pch.h"

enum class window_state: short {shape, window};

class main_window: public QWidget
{
    QPushButton* state_button;
    QPixmap canvas;
    window_state state;
    short button_width;
    short button_height;

    void paint(QPainter& painter);

    private slots:
        void on_button_pressed();

    protected:
        void paintEvent(QPaintEvent*) override;
        void resizeEvent(QResizeEvent*) override;

    public:
        explicit main_window(QWidget* parent = nullptr) noexcept;
        ~main_window() = default;
};