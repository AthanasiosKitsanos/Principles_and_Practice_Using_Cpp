#pragma once

#include "show_data_pch.h"

struct show_data
{
    QRectF file_type_frame;
    QRectF constructor_frame;
    QString file_type;
    QString constructor_string;
    float x_factor;
    float y_factor;
    float x_padding;
    float y_padding;
    int lines;

    explicit show_data(const QString& file, const QString& constuct, const float x, const float y, const float x_p, const float y_p, const int line) noexcept;
    ~show_data() = default;

    void set_frames(const QRect& frame);
};