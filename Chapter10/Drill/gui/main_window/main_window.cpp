#include "main_window.h"
#include <cmath>

main_window::main_window(QWidget* parent):
    QWidget(parent),
    line1(width() * x_axis_spos, height() * y_axis_spos, width() * x_axis_epos, height() * y_axis_spos),
    line2(0, 0, 0, 0),
    button(new QPushButton{"Next", this}), back{new QPushButton{"Back", this}}, page(0)
{
    setMinimumSize(600, 400);
    setMaximumSize(2560, 1080);
    setWindowTitle("Drill");
    resize(600, 400);
    setWindowIcon(QIcon{"icons\\icons8-c-256.ico"});
    {
        QPalette palette;
        palette.setColor(QPalette::Button, Qt::gray);
        palette.setColor(QPalette::ButtonText, Qt::black);
        button->setPalette(palette);
        back->setPalette(palette);
    }
    connect(button, &QPushButton::clicked, this, &main_window::when_button_pressed);
    connect(back, &QPushButton::clicked, this, &main_window::when_back_pressed);
}

void main_window::resizeEvent(QResizeEvent*)
{
    canvas = QPixmap(size());
    canvas.fill(Qt::darkGray);
    int x(width()), y{height()};

    button->move(x - button->width() + 5, y - button->height() - 5);
    back->move(10, y - back->height() - 5);

    line1.setLine(x * x_axis_spos, y * y_axis_spos, x * x_axis_epos, y * y_axis_spos);
    line2.setLine(x * x_axis_spos, y * y_axis_spos, x * x_axis_spos, y * y_axis_epos);
}

void main_window::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    QPen pen;
    QFont font;
    painter.drawPixmap(0, 0, canvas);
    font.setPointSize(24);
    painter.setFont(font);
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.drawText(rect(), Qt::AlignCenter, "Hello, World!");

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    begin_drawing(painter, font);
}

void main_window::when_button_pressed()
{
    if(page == max_pages) return;
    ++page;
    update();
}

void main_window::when_back_pressed()
{
    if(page == 0) return;
    --page;
    update();
}

void main_window::dsin(double d)
{
    double a = std::sin(d);
}

void main_window::begin_drawing(QPainter& painter, QFont& font)
{
    int x(width()), y{height()};
    for(short p{1}; p <= page; ++p)
    {
        switch(p)
        {
            case 1:
                painter.drawLine(line1);
                font.setPointSize(13);
                painter.setFont(font);
                painter.drawText((line1.x2() + line1.x1()) / 2, line1.y2() + 20, "X Axis");
                break;
            case 2:
                painter.drawLine(line2);
                painter.save();
                painter.translate(line2.x1() - 10, (line2.y2() + line2.y1()) / 2);
                painter.rotate(-90);
                font.setPointSize(13);
                painter.setFont(font);
                painter.drawText(0, 0, "Y Axis");
                painter.restore();
                break;
            case 3:
            {
                float start{0}, end{0}, step{0};
                int tick{0};
                for(short i{1} ; i < ticks; ++i)
                {
                    start = x * x_axis_spos;
                    end = x * x_axis_epos;
                    step = (end - start) / ticks;
                    tick = start + i * step;
                    painter.drawLine(tick, y * y_axis_spos, tick, y * y_axis_spos - 5);
                    start = y * y_axis_spos;
                    end = y * y_axis_epos;
                    step = (start - end) / ticks;
                    tick = end + i * step;
                    painter.drawLine(x * x_axis_spos, tick, x * x_axis_spos + 5, tick);
                }
                break;
            }
            case 4:
            {
                QPoint previous, current;
                const double amplitude{y * 0.1}, center_y(y / 2);
                double theta{0}, y_sin{0}; 
                for(int step{0}; step < x; ++step)
                {
                    theta = (2.0 * M_PI * step) / y;
                    y_sin = center_y - amplitude * std::cos(theta);
                    current = QPoint{step, static_cast<int>(y_sin)};
                    if(step > 0) painter.drawLine(previous, current);
                    previous = current;
                }
            }
        }
    }
}