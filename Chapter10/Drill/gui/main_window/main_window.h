#pragma once

#include "pch.h"

constexpr float x_axis_spos = 0.05f;
constexpr float x_axis_epos = 0.5f;
constexpr float y_axis_spos = 0.85f;
constexpr float y_axis_epos = 0.25f;
constexpr short ticks = 10;
constexpr short min_pages = 0;
constexpr short max_pages = 5;

class main_window: public QWidget
{
    QPixmap canvas;
    QLine line1;
    QLine line2;
    QPushButton* button;
    QPushButton* back;
    short page;

    private slots:
        void when_button_pressed();
        void when_back_pressed();

    protected:
        void resizeEvent(QResizeEvent*) override;

        void paintEvent(QPaintEvent*) override;

    public:
        explicit main_window(QWidget* parent = nullptr);
        void begin_drawing(QPainter& painter, QFont& font);
        void dsin(double d);
};