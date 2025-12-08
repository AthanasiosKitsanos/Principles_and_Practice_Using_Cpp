#include "global.h"
#include "parser_context/parser_context.h"

// global pointer to use on every model
parser_context* global_pc = nullptr;

namespace global
{
    parser_context* initialize_parser(const char* start, const char* end)
    {
        void* raw = ::operator new(sizeof(parser_context));
        return new(raw) parser_context{start, end};
    }

    void free_parser(parser_context*& ptr)
    {
        ptr->~parser_context();
        ::operator delete(ptr);
        ptr = nullptr;
    }
}