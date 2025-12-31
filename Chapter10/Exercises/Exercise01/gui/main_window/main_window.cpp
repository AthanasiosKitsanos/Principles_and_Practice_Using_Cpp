#include "main_window.h"

main_window::main_window(QWidget* parent): QWidget(parent)
{
    setMinimumSize(600, 400);
    setMaximumSize(600, 400);
    setWindowTitle("Exercise 1");
}

main_window::~main_window() {}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    QFont font;
    QRect rect{100, 100 , 200, 100};

    //Rectangle
    {
        painter.setPen(Qt::blue);
        painter.drawRect(rect);
        rect.setWidth(100);
        rect.setHeight(50);
        rect.moveTo(310, 125);
        painter.setPen(Qt::yellow);
        font.setBold(true);
        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, "Rectangle");
    }

    //Polygon
    painter.setPen(Qt::red);
    QPolygon poly;
    poly.append({100, 250});
    poly.append({300, 250});
    poly.append({300, 350});
    poly.append({100, 350});
    painter.drawPolygon(poly);
    painter.setPen(Qt::yellow);
    rect.moveTo(310, 275);
    painter.drawText(rect, Qt::AlignCenter, "Polygon");
}