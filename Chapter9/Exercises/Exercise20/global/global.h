#pragma once

struct parser_context;

extern parser_context* global_pc;

namespace global
{
    parser_context* initialize_parser(const char* start, const char* end);
    void free_parser(parser_context*& ptr);
}