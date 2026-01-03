#include "main_window.h"

constexpr int min_window_width = 640;
constexpr int min_window_height = 270;

main_window::main_window(QWidget* parent) noexcept: QWidget(parent), canvas(min_window_width * 4, min_window_height * 4), state_button(new QPushButton{this}),
    state(window_state::shape), button_width(0), button_height(state_button->height()) 
{
    setMinimumSize(min_window_width, min_window_height);
    setWindowTitle("Exercise 6");
    {
        QPalette palette;
        palette.setColor(QPalette::Button, Qt::lightGray);
        palette.setColor(QPalette::ButtonText, Qt::black);
        state_button->setPalette(palette);
    }

    state_button->setStyleSheet
    (
        "QPushButton:hover {"
        "background-color: #d6d6d6"
        "}"
    );
    state_button->setFixedWidth(75);
    state_button->setText("Shape");
    button_width = state_button->width();
    connect(state_button, &QPushButton::clicked, this, &on_button_pressed);

    canvas.fill(Qt::transparent);
    QPainter painter{&canvas};
    painter.setPen(Qt::red);
    painter.drawRect(min_window_width, min_window_height, min_window_width * 2, min_window_height * 2);
}

void main_window::resizeEvent(QResizeEvent*)
{
    state_button->move(width() - button_width - 10, height() - button_height- 5);
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    paint(painter);
}

void main_window::on_button_pressed()
{
    switch(state)
    {
        case window_state::shape:
            state = window_state::window;
            state_button->setText("Window");
            break;
        case window_state::window:
            state = window_state::shape;
            state_button->setText("Shape");
            break;
    }
    update();
}

void main_window::paint(QPainter& painter)
{
    switch(state)
    {
        case window_state::shape:
            painter.setClipRect(rect());
            painter.drawPixmap(-(canvas.width() - width()), -(canvas.height() - height()), canvas);
            break;
        case window_state::window:
            resize(min_window_width * 5, min_window_height * 5);
            break;
    }
}