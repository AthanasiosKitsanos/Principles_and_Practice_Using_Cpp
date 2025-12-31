#include "main_window.h"

main_window::main_window(QWidget* parent) noexcept: QWidget(parent)
{
    setMinimumSize(600, 400);
    setMaximumSize(600, 400);
    setWindowTitle("Exercise 2");
}

main_window::~main_window() {}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter p{this};
    QRect rect{250, 170, 100, 30};
    p.drawRect(rect);
    p.drawText(rect, Qt::AlignCenter, "Howdy!");
}