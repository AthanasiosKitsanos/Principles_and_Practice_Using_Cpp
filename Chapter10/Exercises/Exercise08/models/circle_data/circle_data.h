#pragma once

#include <QColor>

struct circle_data
{
    QColor color;
    float x_factor;
    float y_factor;

    explicit circle_data(const QColor& c, const float x, const float y) noexcept;
    ~circle_data() = default;
};