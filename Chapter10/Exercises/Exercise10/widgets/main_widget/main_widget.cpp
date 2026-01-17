#include "main_widget.h"
#include <QtMAth>

constexpr int page_1_begin{0};
constexpr int page_1_end{6};
constexpr int page_2_begin{page_1_end};
constexpr int page_2_end{data_count};

main_widget::main_widget(QWidget* parent) noexcept: QWidget(parent), p1_buffer(), p2_buffer(), pixmap(), current_pixmap(&p1_buffer), button(new QPushButton{"Next", this})
{
    QScreen* screen{this->screen()};
    QRect current_screen{screen->availableGeometry()};
    setAttribute(Qt::WA_OpaquePaintEvent);
    int initial_width{current_screen.width()};
    int initial_height{current_screen.height()};
    setMinimumSize(initial_width* 0.5f, initial_height * 0.5f);
    setWindowTitle("Exercise 10");
    paint_pixmaps(initial_width, initial_height);
    QPalette palette;
    palette.setColor(QPalette::Button, Qt::gray);
    palette.setColor(QPalette::ButtonText, Qt::black);
    button->setPalette(palette);
    connect(button, &QPushButton::clicked, this, &main_widget::on_press);
    show();
}

void main_widget::on_press()
{
    if(current_pixmap == &p1_buffer)
    {
        current_pixmap = &p2_buffer;
        button->setText("Previous");
    }
    else
    {
        current_pixmap = &p1_buffer;
        button->setText("Next");
    }
    update();
}

void main_widget::resizeEvent(QResizeEvent* event)
{
    button->move(width() - button->width() - 5, height() - button->height() - 10);
    update();
    QWidget::resizeEvent(event);
}

void main_widget::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    pixmap = current_pixmap->scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.setRenderHint(QPainter::Antialiasing, QPainter::SmoothPixmapTransform);
    painter.drawPixmap(0, 0, pixmap);
}

void main_widget::paint_pixmaps(const int width, const int height) noexcept
{
    QFont font;
    font.setPointSize(25);
    font.setBold(true);
    QRect frame(width * 0.1f, height * 0.2f, width * 0.15f, height * 0.2f);
    paint_pixmap_1(width, height, frame, font);
    paint_pixmap_2(width, height, frame, font);
}

void main_widget::paint_pixmap_1(const int width, const int height, QRect& frame, QFont& font) noexcept
{
    p1_buffer = QPixmap{width, height};
    p1_buffer.fill(Qt::darkGray);

    QPainter painter{&p1_buffer};
    painter.setFont(font);
    painter.drawText(width * 0.477f, height * 0.97f, "Page 1");
    data_block* current{nullptr};
    for(short i{page_1_begin}; i < page_1_end; ++i)
    {
        current = &data_list[i];
        frame.moveTo(width * current->new_x_pos, height * current->new_y_pos);
        data_list[i].set_frames(frame);
        if(data_list[i].arrow_num > 0)
        {
            painter.save();
            QPen pen;
            pen.setWidth(5);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            for(short j{0}; j < current->arrow_num; ++j)
            {
                const data_block& linked_data = data_list[*(data_list[i].links + j)];
                QPoint end(current->get_end_linked(linked_data));
                QLine line(current->get_start_current(), end);
                current->arrows.create_arrow(line);
                painter.drawLine(current->arrow_body());
                painter.drawLine(end, current->arrow_head_1());
                painter.drawLine(end, current->arrow_head_2());
            }
            painter.restore();
        }
        painter.setBrush(Qt::yellow);
        painter.drawRect(current->frames.context_frame);
        painter.setPen(Qt::blue);
        painter.drawText(current->frames.title_frame, Qt::AlignBottom, current->context.file_type);
        painter.drawText(current->frames.context_frame, Qt::AlignCenter, current->context.constructor_string);
    }
    current = nullptr;
}

void main_widget::paint_pixmap_2(const int width, const int height, QRect& frame, QFont& font) noexcept
{
    p2_buffer = QPixmap{width, height};
    p2_buffer.fill(Qt::darkGray);
    QPainter painter{&p2_buffer};
    painter.setFont(font);
    painter.drawText(width * 0.477f, height * 0.97f, "Page 2");
    data_block* current{&data_list[page_2_begin]};
    frame.moveTo(width * current->new_x_pos, height * current->new_y_pos);
    current->set_frames(frame);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::yellow);
    painter.drawRect(current->frames.context_frame);
    painter.setPen(Qt::black);
    painter.drawText(current->frames.context_frame, Qt::AlignCenter, current->context.constructor_string);
    for(short i{page_2_begin + 1}; i < page_2_end; ++i)
    {
        current = &data_list[i];
        frame.moveTo(width * current->new_x_pos, height * current->new_y_pos);
        current->set_frames(frame);
        if(current->arrow_num > 0)
        {
            painter.save();
            QPen pen;
            pen.setWidth(5);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            for(short j{0}; j < current->arrow_num; ++j)
            {
                const data_block& linked_data = data_list[*(data_list[i].links + j)];
                QPoint end(current->get_end_linked(linked_data));
                QLine line(current->get_start_current(), end);
                current->arrows.create_arrow(line);
                painter.drawLine(current->arrow_body());
                painter.drawLine(end, current->arrow_head_1());
                painter.drawLine(end, current->arrow_head_2());
            }
            painter.restore();
        }
        painter.setPen(Qt::black);
        painter.setBrush(Qt::yellow);
        painter.drawRect(current->frames.context_frame);
        painter.setPen(Qt::blue);
        painter.drawText(current->frames.title_frame, Qt::AlignBottom, current->context.file_type);
        painter.drawText(current->frames.context_frame, Qt::AlignCenter, current->context.constructor_string);
    }
    current = nullptr;
}