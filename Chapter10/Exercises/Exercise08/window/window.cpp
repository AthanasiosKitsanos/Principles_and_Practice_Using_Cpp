#include "window.h"
#include <QScreen>

constexpr short x_grid{5};
constexpr short y_grid{4};
constexpr float offset{0.9f};

window::window(QWidget* parent) noexcept: QWidget(parent), circle(), cell_width(0.0f), cell_height(0.0f)
{
    QScreen* screen = this->screen();
    QRect screen_rect = screen->availableGeometry();
    setMinimumSize(screen_rect.width() * 0.25f, screen_rect.height() * 0.25f);
    setWindowTitle("Exercise 8");
    QColor temp_color{};
    QPalette palette{this->palette()};
    palette.setColor(QPalette::Window, Qt::darkGray);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    show();
}

void window::resizeEvent(QResizeEvent*)
{
    cell_width = this->width() / x_grid;
    cell_height = this->height() / y_grid;
    circle.setRect(cell_width, cell_height, cell_width * offset, cell_width * offset);
    update();
}

void window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawEllipse(circle);
    for(short i{0}; i < data_count; ++i)
    {
        pen.setColor(data[i].color);
        painter.setPen(pen);
        circle.moveTo(cell_width * data[i].x_factor, cell_height * data[i].y_factor);
        painter.drawEllipse(circle);
    }
}