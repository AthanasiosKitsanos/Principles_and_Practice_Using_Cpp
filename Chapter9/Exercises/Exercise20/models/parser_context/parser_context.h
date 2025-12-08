#pragma once
#include "pch.h"

struct parser_context
{
    const char* current;
    const char* end;

    parser_context();
    parser_context(const char* front, const char* back);
    ~parser_context();
};