#include "headers.h"
#include "global.h"
#include "token.h"
#include "token_stream.h"

Token_Stream* global_ts = nullptr;
Token_Stream* Token::ts = nullptr;

void init_global_pointer()
{
    void* rawMemory = _aligned_malloc(sizeof(Token_Stream), alignof(Token_Stream));
    if(!rawMemory)
    {
        throw std::runtime_error("Allocation failed");
    }

    global_ts = new(rawMemory) Token_Stream();

    Token::set_to_global(global_ts);

    std::cout << "Global pointer and Token pointer all set" << std::endl;
}

void delete_global_pointer()
{
    if(global_ts)
    {
        global_ts->~Token_Stream();

        _aligned_free(global_ts);

        Token::delete_from_global();
        global_ts = nullptr;

        std::cout << "Allocated memory freed and pointer are null" << std::endl;
    }
}