#include "main_window.h"

main_window::main_window(QWidget* parent) noexcept: QWidget(parent)
{
    setMinimumSize(600, 400);
    setMaximumSize(600, 400);
    setWindowTitle("Exercise 3");
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter p{this};
    QPen pen;
    QFont font{"Arial", 50};
    QFontMetrics fm{font};

    pen.setWidth(5);
    pen.setColor(Qt::white);
    p.setFont(font);
    p.setPen(pen);
    p.translate(20, 0);
    p.scale(1.0, 150.0 / fm.height());
    p.drawText(0, fm.height(), "A");
    p.translate(100, 0);
    p.drawText(0, fm.height(), "K");
}