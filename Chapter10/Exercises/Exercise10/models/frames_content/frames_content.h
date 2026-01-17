#pragma once

#include "data_pch.h"

struct frames_content
{
    QString file_type;
    QString constructor_string;

    explicit frames_content(const QString& file, const QString& constuct) noexcept;
    explicit frames_content(const frames_content& other) noexcept;
    ~frames_content() = default;
};