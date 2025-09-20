#pragma once

class Token_Stream;

class Token
{
    private:
        static Token_Stream* ts;

    public:
        double value;
        char kind;

        Token();
        Token(char k);
        Token(char k, double v);

        double expression();
        double term();
        double primary();
        static void initializa_token_pointer(Token_Stream* ptr);
        static void delete_token_pointer();
};