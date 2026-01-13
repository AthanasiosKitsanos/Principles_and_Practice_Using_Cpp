#include "main_widget.h"

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
    setMinimumSize(initial_width* 0.25f, initial_height * 0.33f);
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
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
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
    for(short i{page_1_begin}; i < page_1_end; ++i)
    {
        frame.moveTo(width * data_list[i].x_factor, height * data_list[i].y_factor);
        data_list[i].set_frames(frame);
        painter.setPen(Qt::black);
        if(data_list[i].lines > 0)
        {
            draw_arrows(static_cast<data_index>(i), data_list[i] , painter);
        }
        painter.setBrush(Qt::yellow);
        painter.drawRect(data_list[i].constructor_frame);
        painter.setPen(Qt::blue);
        painter.drawText(data_list[i].file_type_frame, Qt::AlignBottom, data_list[i].file_type);
        painter.drawText(data_list[i].constructor_frame, Qt::AlignCenter, data_list[i].constructor_string);
    }
}

void main_widget::paint_pixmap_2(const int width, const int height, QRect& frame, QFont& font) noexcept
{
    p2_buffer = QPixmap{width, height};
    p2_buffer.fill(Qt::darkGray);
    QPainter painter{&p2_buffer};
    painter.setFont(font);
    painter.drawText(width * 0.477f, height * 0.97f, "Page 2");
    frame.moveTo(width * data_list[page_2_begin].x_factor, height * data_list[page_2_begin].y_factor);
    data_list[page_2_begin].set_frames(frame);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::yellow);
    painter.drawRect(data_list[page_2_begin].constructor_frame);
    painter.setPen(Qt::black);
    painter.drawText(data_list[page_2_begin].constructor_frame, Qt::AlignCenter, data_list[page_2_begin].constructor_string);
    for(short i{page_2_begin + 1}; i < page_2_end; ++i)
    {
        frame.moveTo(width * data_list[i].x_factor, height * data_list[i].y_factor);
        data_list[i].set_frames(frame);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::yellow);
        painter.drawRect(data_list[i].constructor_frame);
        painter.setPen(Qt::blue);
        painter.drawText(data_list[i].file_type_frame, Qt::AlignBottom, data_list[i].file_type);
        painter.drawText(data_list[i].constructor_frame, Qt::AlignCenter, data_list[i].constructor_string);
    }
}

void main_widget::draw_arrows(const data_index& index, const show_data& data, QPainter& painter)
{
    switch(index)
    {
        case data_index::graph_1:
        {   
            
            QPoint start_pos(data.constructor_frame.left() + data.constructor_frame.width() * 0.5f, data.constructor_frame.top());
            QPoint end_pos(data.constructor_frame.left() + data.constructor_frame.width() * 0.5f, data_list[static_cast<int>(data_index::point_1)].constructor_frame.bottom());
            painter.drawLine(start_pos, end_pos);
        }
    }
}