#include "headers.h"
#include "global.h"
#include "token_stream.h"
#include "token.h"

Token_Stream* ts_global = nullptr;
Token_Stream* Token::ts = nullptr;

void initialize_pointer()
{
    void * rawMemory = _aligned_malloc(sizeof(Token_Stream), alignof(Token_Stream));
    if(!rawMemory)
    {
        throw std::runtime_error("Allocation failed");
    }

    ts_global = new(rawMemory) Token_Stream();

    Token::initializa_token_pointer(ts_global);
}

void delete_pointer()
{
    if(ts_global)
    {
        Token::delete_token_pointer();
        ts_global->~Token_Stream();
        _aligned_free(ts_global);

        ts_global = nullptr;
    }
}