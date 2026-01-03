#include "main_window.h"

main_window::main_window(QWidget* parent) noexcept: QWidget(parent), frame_width(QGuiApplication::primaryScreen()->logicalDotsPerInch() * 0.25f), rect(nullptr), win_x(0), win_y(0)
{
    setMinimumSize(640, 270);
    setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    setWindowTitle("Exercise 6");

    void* raw = malloc(sizeof(QRect));
    rect = new(raw) QRect{};

    win_x = width();
    win_y = height();
    float rect_width{win_x * (2.0f / 3.0f)};
    float rect_height{win_y * (3.0f / 4.0f)};
    float x = (win_x - rect_width) / 2.0f;
    float y = (win_y - rect_height) / 2.0f;
    rect->setRect(x, y, rect_width, rect_height);

}

main_window::~main_window() noexcept
{
    if(rect)
    {
        rect->~QRect();
        free(rect);
        rect = nullptr;
    }
}

void main_window::resizeEvent(QResizeEvent*)
{
    win_x = width();
    win_y = height();
    float rect_width{win_x * 0.75f};
    float rect_height{win_y * (2.0f / 3.0f)};
    float x = (win_x - rect_width) / 2.0f;
    float y = (win_y - rect_height) / 2.0f;
    rect->setRect(x, y, rect_width, rect_height);
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidthF(frame_width);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(*rect);
}