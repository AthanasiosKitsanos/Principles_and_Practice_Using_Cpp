#pragma once

#include "data_pch.h"

struct data_frame
{
    QRect title_frame;
    QRect context_frame;

    explicit data_frame() noexcept;
    ~data_frame() = default;
};