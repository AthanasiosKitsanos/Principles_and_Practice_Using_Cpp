#pragma once

class Token_Stream;

class Token
{
    private:
        static Token_Stream* ts;

    public:
        int value;
        char kind;

        Token();
        Token(char k);
        Token(char k, int v);
        ~Token();

        int binary_or();
        int binary_xor();
        int binary_and();
        int primary();

        static void set_to_global(Token_Stream* ptr);
        static void delete_from_global();
};