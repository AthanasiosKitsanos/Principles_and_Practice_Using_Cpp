#include "pch.h"
#include "circle_data.h"

class circle_data;
constexpr short data_count{4};

class window: public QWidget
{
    circle_data data[data_count] =
    {
        circle_data{Qt::black, 2.0f, 1.0f},
        circle_data{Qt::red, 3.0f, 1.0f},
        circle_data{Qt::yellow, 1.5f, 1.5f},
        circle_data{Qt::green, 2.5f, 1.5f}
    };
    QRectF circle;
    float cell_width;
    float cell_height;

    protected:
        void resizeEvent(QResizeEvent*) override;
        void paintEvent(QPaintEvent*) override;
    
    public:
        explicit window(QWidget* parent = nullptr) noexcept;
        ~window() = default;
};