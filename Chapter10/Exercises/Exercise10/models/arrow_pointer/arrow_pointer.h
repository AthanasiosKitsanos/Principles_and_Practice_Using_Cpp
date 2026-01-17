#pragma once

#include "data_pch.h"

struct arrow_pointer
{
    QLine arrow_body;
    QPoint arrow_head_1;
    QPoint arrow_head_2;

    explicit arrow_pointer() noexcept;
    ~arrow_pointer() = default;

    void create_arrow(const QLine& line, double arrow_size = 12.0f);
    void set_arrow_head(double arrow_size);
};