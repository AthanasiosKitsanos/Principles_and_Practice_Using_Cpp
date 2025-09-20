#include "headers.h"
#include "token_stream.h"
#include "token.h"
#include "global.h"

Token::Token() { }
Token::Token(char c): kind(c), value(0.00) { }
Token::Token(char c, int val): kind(c), value(val) { }
Token::~Token() {}

int Token::binary_or()
{
    int left = binary_xor();

    Token t = ts->get();

    while(true)
    {
        switch(t.kind)
        {
            case '|':
                left |= binary_xor();
                t = ts->get();
                break;

            default:
                ts->putback(t);
                return left;
        }
    }
}

int Token::binary_xor()
{
    int left = binary_and();

    Token t = ts->get();

    while(true)
    {
        switch(t.kind)
        {
            case '^':
                left ^= binary_and();
                t = ts->get();
                break;
            
            default:
                ts->putback(t);
                return left;
        }
    }
}

int Token::binary_and()
{
   int left = primary();

   Token t = ts->get();

   while(true)
   {
        switch(t.kind)
        {
            case '&':
                left &= primary();
                t = ts->get();
                break;

            default:
                ts->putback(t);
                return left;
        }
   }
}

int Token::primary()
{
    Token t = ts->get();

    switch(t.kind)
    {
        case '(':
            {
                int i = binary_or();

                t = ts->get();

                if(t.kind != ')')
                {
                    throw std::runtime_error("')' expected");
                }

                return i;
            }

        case '~':
            {
                Token next = ts->get();

                if(next.kind != '8')
                {
                    throw std::runtime_error("Expected a primary number after ~");
                }

                return ~next.value;
            }

        case '!': //where !0 returns true (1) and every other number bigger than 0 (like !5) returns false (0)
            {
                Token next = ts->get();

                if(next.kind != '8')
                {
                    throw std::runtime_error("Expected a primary after !");
                }

                return !next.value;
            }

        case '8':
            return t.value;

        default:
            throw std::runtime_error("Expected a primary number");
    }
}

void Token::set_to_global(Token_Stream* ptr)
{
    ts = ptr;
}

void Token::delete_from_global()
{
    ts = nullptr;
}