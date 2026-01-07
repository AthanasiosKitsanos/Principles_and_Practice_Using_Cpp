#include "main_window.h"
#include "house.h"
#include <iostream>

constexpr int max_width{2560};
constexpr int max_height{1080};
constexpr short door_lines{5};

main_window::main_window(QWidget* parent) noexcept: QWidget(parent), home(static_cast<house*>(::operator new(sizeof(house), std::align_val_t(alignof(house)))))
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    setMinimumSize(max_width / 2, max_height / 3);
    new(home) house{};
    show();
}

main_window::~main_window()
{
    home->~house();
    ::operator delete(home, std::align_val_t(alignof(house)));
    home = nullptr;
}

void main_window::resizeEvent(QResizeEvent*)
{
   win_x = width() / 10.0f;
   win_y = height() / 10.0f;
   home->resize_house({win_x * 4, win_y * 4, win_x * 2 , win_y * 5});
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    home->draw_house(painter);
}