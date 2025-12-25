#include "headers.h"
#include "global.h"
#include "token_stream.h"

Token_Stream* ts_global = nullptr;

void initialize_stream_pointer()
{
    void* raw_memory = _aligned_malloc(sizeof(Token_Stream), alignof(Token_Stream));
    if(!raw_memory)
    {
        throw std::runtime_error("Failed to allocate Token_Stream");
    }

    ts_global = new(raw_memory) Token_Stream();
}

void delete_stream_pointer()
{
    if(ts_global)
    {
        ts_global->~Token_Stream();
        _aligned_free(ts_global);
        ts_global = nullptr;
    }
}