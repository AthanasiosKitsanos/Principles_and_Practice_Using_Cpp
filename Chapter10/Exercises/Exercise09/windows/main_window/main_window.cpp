#include "main_window.h"

main_window::main_window(QWidget* parent) noexcept: QWidget(parent), original_image("images/hb_photo.png")
{
    QScreen* screen = this->screen();
    QRect current_screen{screen->availableGeometry()};
    setAttribute(Qt::WA_OpaquePaintEvent);
    setMinimumSize(current_screen.width() * 0.25f, current_screen.height() * 0.25f);
    setWindowTitle("Exercise 9 - My image");
    setWindowIcon(QIcon{"icons/cpp_icon.ico"});
    show();
}

void main_window::resizeEvent(QResizeEvent* event)
{
    drawn_image = original_image.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QWidget::resizeEvent(event);
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.drawPixmap(0, 0, drawn_image);
}